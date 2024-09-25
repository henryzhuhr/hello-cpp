#include <iostream>
#include <string>

#ifndef BUFFER_H
#define BUFFER_H
class Buffer
{
  private:
    unsigned char* buffer_;
    int            capacity;
    int            length;

  public:
    /**
     * 单参数构造函数
     */
    explicit Buffer(int capacity) : buffer_(new unsigned char[capacity]{0}), capacity(capacity), length(0) {}
    /**
     * 拷贝构造函数
     */
    Buffer(Buffer& buffer)
    {
        this->capacity = buffer.capacity;
        this->length   = buffer.length;
        this->buffer_  = new unsigned char[buffer.capacity];
        std::copy(buffer.buffer_, buffer.buffer_ + buffer.capacity, this->buffer_);
    }
    /**
     * 拷贝赋值函数
     */
    Buffer& operator=(Buffer const& buffer)
    {
        if (this != &buffer)
        {
            this->capacity = buffer.capacity;
            this->length   = buffer.length;
            delete[] this->buffer_;
            this->buffer_ = new unsigned char[buffer.capacity];
            std::copy(buffer.buffer_, buffer.buffer_ + buffer.capacity, this->buffer_);
        }
        return *this;
    }
    ~Buffer() { delete[] buffer_; }

  public:
    int GetLength() { return length; }
    int GetCapacity() { return capacity; }

  public:
    friend std::ostream& operator<<(std::ostream& os, Buffer& buffer)
    {
        os << "Buffer(" << buffer.length << "/" << buffer.capacity << ")[";
        for (int i = 0; i < buffer.capacity; i++)
        {
            os << (int)buffer.buffer_[i] << ",";
        }
        os << "]";
        return os;
    }


  public:
    bool write(unsigned char value)
    {
        if (length == capacity)
            return false;
        buffer_[length++] = value;
        return true;
    }
};

#endif

int main(int argc, char const* argv[])
{
    Buffer buffer(10);
    buffer.write(97);
    auto buffer2 = buffer;

    buffer.write(65);

    std::cout << "buffer:  " << buffer << std::endl;
    std::cout << "buffer2: " << buffer2 << std::endl;

    return 0;
}
