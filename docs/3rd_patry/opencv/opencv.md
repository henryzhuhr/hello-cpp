

# 源码编译 OpenCV 
[Installation in MacOS](https://docs.opencv.org/4.x/d0/db2/tutorial_macos_install.html)

[OpenCV configuration options reference](https://docs.opencv.org/4.x/db/d05/tutorial_config_reference.html)


## 编译过程

编译过程以 `OpenCV 4.5.4` 为例，根据下载的版本修改版本号

在源码同级目录下新建脚本 `build-opencv.sh`
```sh
.
├── build-opencv.sh
├── opencv-4.5.4
└── opencv_contrib-4.5.4
```

在脚本中，写入下面内容
> 安装到自定义的用户目录而不是系统目录是一种干净又卫生的做法，这时候只需要在环境变量中添加安装目录即可在使用中找到配置文件 `OpenCVConfig.cmake` 
> 
> 如果仍然希望在系统内安装，那么只需要将参数 `-DCMAKE_INSTALL_PREFIX` 删除，则会默认安装到 `/usr/local/` 内，或者也可以指定 `-DCMAKE_INSTALL_PREFIX` 为 `/usr/local`
```sh
VERSION=4.5.4

cd opencv-${VERSION}
rm -rf build
mkdir build
cd build

cmake .. \
    -DCMAKE_INSTALL_PREFIX="../../opencv" \
    -DOPENCV_EXTRA_MODULES_PATH="../../opencv_contrib-${VERSION}/modules" \
    -DCMAKE_BUILD_TYPE=Release \
    -DOPENCV_GENERATE_PKGCONFIG=ON \
    -DBUILD_SHARED_LIBS=ON \
    -DBUILD_STATIC_LIBS=ON \
    -DBUILD_opencv_apps=ON \
    -DBUILD_EXAMPLES=OFF
# NUM_CORES=`sysctl -n hw.ncpu`   # for Darwin
NUM_CORES=`nproc --all`         # for Linux
make -j${NUM_CORES}
make install

cd ..
rm -rf build
```

> 变量 `NUM_CORES` 是当前系统可以使用的核心数量，对于获取核心数的命令，不同平台的命令不一样，需要根据当前的系统环境自行注释

运行脚本
```sh
zsh build-opencv.sh     # for Darwin
bash build-opencv.sh    # for Linux
```


编译完成后会安装到同级目录下的 `opencv` 目录中
```sh
.
├── build-opencv.sh
├── opencv
├── opencv-4.5.4
├── opencv_contrib-4.5.4
└── ...
```

如果安装到自定义的用户目录下，则需要在用户级的环境变量文件 `~/.bashrc`/`~/.zsh` 中添加即可
```sh
OpenCV_DIR=~/program/opencv/lib/cmake
export PATH=$PATH:${OpenCV_DIR}
```

## 测试
在任意目录下新建 `CMakeList.txt`
```cmake
# CMakeList.txt
cmake_minimum_required(VERSION 3.1)
project(TestOpencv)

find_package( OpenCV 4 REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
link_directories(${OpenCV_LIB_DIRS})

message(STATUS "OpenCV status:")
message(STATUS "    Opencv version: ${OpenCV_VERSION}")   
message(STATUS "    Opencv include: ${OpenCV_INCLUDE_DIRS}")
```

执行
```sh
mkdir build
cd build
cmake ..
cd ..
rm -rf build
```

这时候可以看到 cmake 已经找到了 OpenCV 
```sh
-- OpenCV status:
--     Opencv version: 4.5.4
--     Opencv include: ~/program/opencv/include/opencv4
-- Configuring done
-- Generating done
-- Build files have been written to: ...
```