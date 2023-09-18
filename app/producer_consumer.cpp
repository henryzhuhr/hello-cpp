#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>


void producer(std::queue<int>& q, std::mutex& m, std::condition_variable& cv)
{
    for (int i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 注释掉这行代码，看看会发生什么
        std::unique_lock<std::mutex> lock(m);                        // 独占的互斥量，不能递归使用。std::unique_lock 无法获取锁时，可以主动释放锁，而 std::lock_guard 无法主动释放锁。
        // 这个也是构造互斥锁的写法，就是会在lock_guard构造函数里加锁，在析构函数里解锁，之所以搞了这个写法，C++委员会的解释是防止使用mutex加锁解锁的时候，忘记解锁unlock了。
        q.push(i);
        std::cout << "Produced: " << i << std::endl;
        lock.unlock();   // 注释也是可以的，因为 std::unique_lock 的析构函数会自动释放锁。但是为了代码的可读性，还是建议显式地释放锁。
        cv.notify_one(); // 某个线程满足条件执行完之后调用 notify_one 或 notify_all 唤醒一个或者所有等待线程。
    }
}

void consumer(std::queue<int>& q, std::mutex& m, std::condition_variable& cv)
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(m);
        // 当前线程调用wait()后将被阻塞并且函数会解锁互斥量，直到另外某个线程调用notify_one或者 notify_all唤醒当前线程；
        // 一旦当前线程获得通知(notify)，wait()函数也是自动调用lock()，同理不 能使用lock_guard对象。
        cv.wait(lock, [&q]()
                { return !q.empty(); });
        /**
         * 两种重载
         * void wait (unique_lock<mutex>& lck);
         * void wait (unique_lock<mutex>& lck, Predicate pred);
         * 
         * 外一个Predicate 对象（等待条件），这里必须使用 unique_lock，因为 wait() 会在等待时释放锁，而在被唤醒时重新获取锁。
        */
        int i = q.front();
        q.pop();
        std::cout << "Consumed: " << i << std::endl;
        lock.unlock();
    }
}

int main()
{

    const int               MAX_SIZE = 5;
    std::mutex              buffer_mutex; // 独占的互斥量，不能递归使用。
    std::condition_variable cv;           // 条件变量，用于线程间的通信。
    std::queue<int>         buffer;
    // std::ref() 用于将引用包装为 std::reference_wrapper 类型，以便可以被 std::thread 拷贝。传递引用的目的是为了让线程共享数据。
    std::thread producer_thread(producer, std::ref(buffer), std::ref(buffer_mutex), std::ref(cv));
    std::thread consumer_thread(consumer, std::ref(buffer), std::ref(buffer_mutex), std::ref(cv));
    producer_thread.join();
    consumer_thread.join();
    return 0;
}

/**
 * lock_guard  unique_lock
 *
 * 虽然lock_guard挺好用的，但是有个很大的缺陷，
 * 在定义lock_guard的地方会调用构造函数加锁，
 * 在离开定义域的话lock_guard就会被销毁，调用析构函数解锁。
 * 这就产生了一个问题，如果这个定义域范围很大的话，那么锁的粒度就很大，很大程序上会影响效率。
 *
 * 这个会在构造函数加锁，然后可以利用unique.unlock()来解锁，
 * 所以当你觉得锁的粒度太多的时候，可以利用这个来解锁，
 * 而析构的时候会判断当前锁的状态来决定是否解锁，如果当前状态已经是解锁状态了，那么就不会再次解锁，
 * 而如果当前状态是加锁状态，就会自动调用unique.unlock()来解锁。
 *
 * 而lock_guard在析构的时候一定会解锁，也没有中途解锁的功能。
 *
 */