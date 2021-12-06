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
        std::cout << "destructor called: " << *this << std::endl;
        delete[] buf;
    }

    // Copy Construct & Assign
    Buffer(Buffer& buffer)
    {
        std::cout << "copy constructor called: " << *this << std::endl;
        this->capacity = buffer.capacity;
        this->length   = buffer.length;
        this->buf      = new unsigned char[buffer.capacity];
        std::copy(buffer.buf, buffer.buf + buffer.capacity, this->buf);
    }
    Buffer& operator=(Buffer const& buffer)
    {
        std::cout << "assignment operator called: " << &buffer << std::endl;

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
        std::cout << "move constructor called: " << buffer << std::endl;
        this->capacity  = buffer.capacity;
        this->length    = buffer.length;
        this->buf       = buffer.buf;
        buffer.capacity = 0;
        buffer.length   = 0;
        buffer.buf      = nullptr;
    }
    Buffer& operator=(Buffer&& buffer) noexcept
    {
        std::cout << "move assignment operator called: " << buffer << std::endl;

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
    friend std::ostream& operator<<(std::ostream& os, Buffer& buffer)
    {
        os << "Buffer(" << buffer.length << "/" << buffer.capacity << ")[";
        for (int i = 0; i < buffer.capacity; i++)
        {
            os << (int)buffer.buf[i] << ",";
        }
        os << "]";
        return os;
    }
};
#endif

int main(int argc, char const* argv[])
{
    std::cout << std::endl << " ========== auto buffer = Buffer(10); ========== " << std::endl;
    auto buffer = Buffer(10);

    std::cout << std::endl << " ========== buffer = Buffer(16); ========== " << std::endl;
    buffer = Buffer(16); // left value (buffer) = right value (Buffer(16));
    std::cout << buffer << std::endl;

    std::cout << std::endl << " ========== in vector ========== " << std::endl;
    // auto buffers = std::vector<Buffer>();
    // buffers.push_back(Buffer(12));
    // buffers.push_back(Buffer(20));
    // buffers.push_back(Buffer(30));

    std::cout << " ========== Destory ========== " << std::endl;
    return 0;
}
