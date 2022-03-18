## gflags


### 源码下载
从 [GitHub](https://github.com/gflags/gflags) 下载源码


### 编译和安装
```sh
VERSION=2.2.2

cd gflags-${VERSION}
rm -rf build
mkdir build
cd build

cmake .. \
    -DCMAKE_INSTALL_PREFIX=../../gflags \
    -DBUILD_SHARED_LIBS=ON \
    -DBUILD_STATIC_LIBS=ON
NUM_CORES=`sysctl -n hw.ncpu`   # for Darwin
# NUM_CORES=`nproc --all`         # for Linux
make -j${NUM_CORES}
make install

cd ..
rm -rf build
```


编译配置选项:
- `CMAKE_INSTALL_PREFIX` : 安装路径
- `BUILD_SHARED_LIBS` : 编译动态链接库
- `BUILD_STATIC_LIBS` : 编译静态库
- `BUILD_TESTING` : Build tests for execution by CTest
- `BUILD_gflags_LIBS` : 编译多线程版本 (需要找到多线程库)
- `BUILD_gflags_nothreads_LIBS` : 编译单线程版本
- `GFLAGS_NAMESPACE` : 命名空间。默认为 `gflags` To maintain backwards compatibility with the Google Commandline Flags, set this variable to "google". 



in `~/.bashrc`
```bash
gflags_DIR=~/program/gflags/lib/cmake/gflags
```

in `CMakeLists.txt`
```cmake
find_package(gflags REQUIRED)
include_directories(GFLAGS_INCLUDE_DIR)
add_executable(test-gflags test-gflags.cpp)
target_link_libraries (test-gflags gflags)
```


### 库使用
[How To Use gflags (formerly Google Commandline Flags)](https://gflags.github.io/gflags/#cmake)
