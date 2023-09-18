#include <iostream>
#include <string>
#include <vector>

#ifndef BUFFER_H
#define BUFFER_H
class Buffer
{
  private:
    unsigned char* buf;
    int            capacity;
    int            length;

  public:
    explicit Buffer(int capacity) : buf(new unsigned char[capacity]{0}), capacity(capacity), length(0) { std::cout << "Buffer constructor called: " << *this << std::endl; }
    ~Buffer()
    {
        std::cout << "Buffer destructor called: " << *this << std::endl;
        delete[] buf;
    }

    // Copy Construct & Assign
    /**
     * 拷贝构造函数
     * 这好像不对
     */
    Buffer(Buffer& buffer) : buf(nullptr), capacity(0), length(0) { *this = buffer; }
    /**
     * 拷贝赋值函数
     */
    Buffer& operator=(Buffer const& buffer)
    {
        std::cout << "Buffer assignment operator called: " << &buffer << std::endl;
        if (this != &buffer)
        {
            this->capacity = buffer.capacity;
            this->length   = buffer.length;
            delete[] this->buf;
            this->buf = new unsigned char[buffer.capacity];
            std::copy(buffer.buf, buffer.buf + buffer.capacity, this->buf);
        }
        return *this;
    }
    // Move Construct & Assign
    /**
     * 移动构造函数
     */
    Buffer(Buffer&& buffer) noexcept
    { // left value reference

        std::cout << "Buffer move constructor called: " << buffer << std::endl;
        this->capacity = buffer.capacity;
        this->length   = buffer.length;
        this->buf      = buffer.buf;
        /**
         * 偷完资源后，原对象的资源就没有了，所以要把原对象的资源清空
         * 尤其是指针
         */
        buffer.capacity = 0;
        buffer.length   = 0;
        buffer.buf      = nullptr;
    }
    /**
     * 移动赋值函数
     */
    Buffer& operator=(Buffer&& buffer) noexcept
    {
        std::cout << "Buffer move assignment operator called: " << buffer << std::endl;
        if (this != &buffer)
        {
            this->capacity = buffer.capacity;
            this->length   = buffer.length;
            this->buf      = buffer.buf;
            /**
             * 偷完资源后，原对象的资源就没有了，所以要把原对象的资源清空
             * 尤其是指针
             */
            buffer.capacity = 0;
            buffer.length   = 0;
            buffer.buf      = nullptr;
        }

        return *this;
    }


  public:
    int GetLength() { return length; }
    int GetCapacity() { return capacity; }

  public:
    bool write(unsigned char value)
    {
        if (length == capacity)
            return false;
        buf[length++] = value;
        return true;
    }
    void append(const unsigned char* data, int length)
    {
        if (this->length + length > this->capacity)
        {
            unsigned char* new_buf = new unsigned char[this->capacity + length];
            std::copy(this->buf, this->buf + this->capacity, new_buf);
            std::copy(data, data + length, new_buf + this->capacity);
            delete[] this->buf;
            this->buf = new_buf;
            this->capacity += length;
        }
        else
        {
            std::copy(data, data + length, this->buf + this->length);
        }
        this->length += length;
    }
    void print()
    {
        std::cout << "Buffer: ";
        for (int i = 0; i < this->length; i++)
        {
            std::cout << this->buf[i];
        }
        std::cout << std::endl;
    }


  public:
    friend std::ostream& operator<<(std::ostream& os, Buffer& buffer);
};
std::ostream& operator<<(std::ostream& os, Buffer& buffer)
{
    os << "Buffer(" << buffer.length << "/" << buffer.capacity << ")[";
    for (int i = 0; i < buffer.capacity; i++)
    {
        os << (int)buffer.buf[i] << ",";
    }
    os << "]";
    return os;
}
#endif

int main(int argc, char const* argv[])
{
    {
        std::cout << "==========" << std::endl;
        auto buffers = std::vector<Buffer>();
        std::cout << " push_back " << std::endl;
        buffers.push_back(Buffer(12));
        std::cout << " push_back " << std::endl;
        buffers.push_back(Buffer(20));
        std::cout << " push_back " << std::endl;
        buffers.push_back(Buffer(30));
        std::cout << " finish domain " << std::endl;
    }

    return 0;
    {
        std::cout << "========== auto buffer = Buffer(5); ==========" << std::endl;
        Buffer buffer(5);
        std::cout << " finish domain " << std::endl;
    }
    {
        std::cout << "========== auto buffer = Buffer(10); ==========" << std::endl;
        auto buffer = Buffer(10); // left value (buffer) = right value (Buffer(16));
        std::cout << " finish domain " << std::endl;
    }
    return 0;
}
