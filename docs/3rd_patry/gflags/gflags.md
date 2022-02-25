## gflags

[How To Use gflags (formerly Google Commandline Flags)](https://gflags.github.io/gflags/#cmake)


```sh
LIB_NAME=gflags
VERSION=2.2.2

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
gflags_DIR=~/program/gflags/lib/cmake/gflags
```

in `CMakeLists.txt`
```cmake
find_package(gflags REQUIRED)
include_directories(GFLAGS_INCLUDE_DIR)
add_executable(test-gflags test-gflags.cpp)
target_link_libraries (test-gflags gflags)
```