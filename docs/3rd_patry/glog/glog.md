
## glog
### 直接使用

在这之前，同级目录下需要添加源码的软连接或者将源码复制到同级目录下
```sh
ln -s <glog_source_dir> glog
```
> [Adding a Library](https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20a%20Library.html)

in `CMakeLists.txt`
```cmake
add_subdirectory(glog)
include_directories(GLOG_INCLUDE_DIR)
add_executable(test-glog test-glog.cpp)
target_link_libraries (test-glog glog::glog)
```

### 编译源码
```sh
LIB_NAME=glog
VERSION=0.5.0

cd ${LIB_NAME}-${VERSION}
rm -rf build
mkdir build
cd build

cmake .. \
    -DCMAKE_INSTALL_PREFIX=../../${LIB_NAME} \
    -DBUILD_SHARED_LIBS=ON \
    -DBUILD_STATIC_LIBS=ON
NUM_CORES=`sysctl -n hw.ncpu`   # for Darwin
# NUM_CORES=`nproc --all`         # for Linux
make -j${NUM_CORES}
make install

cd ..
rm -rf build
```

in `~/.bashrc`
```bash
glog_DIR=~/program/glog/lib/cmake/glog
export CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH:$glog_DIR
```

in `CMakeLists.txt`
```cmake
find_package(glog REQUIRED)
include_directories(GLOG_INCLUDE_DIR)
add_executable(test-glog test-glog.cpp)
target_link_libraries (test-glog glog::glog)
```
