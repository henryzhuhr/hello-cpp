
# Usage
```bash
./build
```


# Struture
``` bash
.
├─app       # test file
├─bin       # binary output
├─conf
├─include   # head file
|   ├─LinkedList.hpp
|   └─...
├─src       # source file
└─tools # Download from release
    ├─cmake-3.20.1-windows-x86_64   # cmake
    └─mingw64                       # mingw 64
```

# Include
## LinkedList
[LinkedList.hpp](include/LinkedList.hpp)

```hpp
namespace DataStruture
{
    template <class T> class LinkedList
    {
    private:
        SingleNode<T>* head;
        SingleNode<T>* ptail;
        int            maxLength;
        int            length;

    public:
        LinkedList(const int maxLength = -1); // -1 mean no limit to length
        ~LinkedList();

    public:
        void TravelLinkedList();

    public:
        void SetMaxLength(const int maxLength = -1);

    public:
        bool Append(const T data);
        bool Insert(const T data, const int index); // insert data in index i
    public:
        bool GetDataByIndex(T& data, const int index = 0);

    public:
        bool Remove(const int index = 0);
        bool Clear();
    };
}
```