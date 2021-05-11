
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


# git
in file `.git/config`
```bash
[remote "origin"]
	url = https://gitee.com/<用户名>/<仓库名字>.git
	url = https://github.com/<用户名>/<仓库名字>.git
	fetch = +refs/heads/*:refs/remotes/origin/*
```bash