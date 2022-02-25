
## glog


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
NUM_CORES=`sysctl -n hw.ncpu`
make -j${NUM_CORES}
make install

cd ..
rm -rf build
```

in `~/.bashrc`
```bash
glog_DIR=~/program/glog/lib/cmake/glog
```

in `CMakeLists.txt`
```cmake
find_package(glog REQUIRED)
include_directories(GLOG_INCLUDE_DIR)
add_executable(test-glog test-glog.cpp)
target_link_libraries (test-glog glog::glog)
```
