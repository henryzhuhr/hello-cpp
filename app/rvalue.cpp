#include <iostream>
#include <string>


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
    explicit Buffer(int capacity)
    {
        this->buf      = new unsigned char[capacity]{0};
        this->capacity = capacity;
        this->length   = 0;
        std::cout << "Buffer constructor called " << std::endl;
    }
    ~Buffer()
    {
        std::cout << "Buffer destructor called" << std::endl;
        delete[] buf;
    }

    // Copy Construct & Assign
    Buffer(Buffer& buffer)
    {
        std::cout << "Buffer copy constructor called" << std::endl;
        this->capacity = buffer.capacity;
        this->length   = buffer.length;
        this->buf      = new unsigned char[buffer.capacity];
        std::copy(buffer.buf, buffer.buf + buffer.capacity, this->buf);
    }
    Buffer& operator=(Buffer const& buffer)
    {
        std::cout << "Buffer assignment operator called" << std::endl;

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
    Buffer(Buffer&& buffer) noexcept
    { // left value reference
        std::cout << "Buffer move constructor called" << std::endl;
        this->capacity  = buffer.capacity;
        this->length    = buffer.length;
        this->buf       = buffer.buf;
        buffer.capacity = 0;
        buffer.length   = 0;
        buffer.buf      = nullptr;
    }

    Buffer& operator=(Buffer&& buffer) noexcept
    {
        std::cout << "Buffer move assignment operator called " << std::endl;

        if (this != &buffer)
        {
            this->capacity = buffer.capacity;
            this->length   = buffer.length;
            this->buf      = buffer.buf;

            buffer.capacity = 0;
            buffer.length   = 0;
            buffer.buf      = nullptr;
        }

        return *this;
    }
};
#endif

int main(int argc, char const* argv[])
{
    std::cout << "========== auto buffer = Buffer(10); ==========" << std::endl;
    auto buffer = Buffer(10);

    std::cout << "========== buffer = Buffer(16); ==========" << std::endl;
    buffer = Buffer(16); // left value (buffer) = right value (Buffer(16));


    std::cout << "==========" << std::endl;
    auto buffers = std::vector<Buffer>();
    buffers.push_back(Buffer(12));
    buffers.push_back(Buffer(20));
    buffers.push_back(Buffer(30));

    std::cout << "========== Destory ==========" << std::endl;
    return 0;
}
