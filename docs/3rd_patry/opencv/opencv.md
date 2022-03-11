
# 源码编译 OpenCV 

- [源码编译 OpenCV](#源码编译-opencv)
  - [编译过程](#编译过程)
  - [测试](#测试)
  - [报错解决方案](#报错解决方案)
    - [配置中未下载的文件](#配置中未下载的文件)

源码编译参考 Installation in [Linux](https://docs.opencv.org/4.5.5/d7/d9f/tutorial_linux_install.html) / [MacOS](https://docs.opencv.org/4.x/d0/db2/tutorial_macos_install.html) 以及编译配置配置 [OpenCV configuration options reference](https://docs.opencv.org/4.x/db/d05/tutorial_config_reference.html)
> 从源码编译主要针对 Unix 系统， Windows NO


## 编译过程

编译过程以 `OpenCV 4.5.5` 为例，根据下载的版本修改版本号 `VERSION`
> [OpenCV 5.0.0-pre](https://docs.opencv.org/5.x/index.html) 文档已经放出

在源码同级目录下新建脚本 `build-opencv.sh`
```sh
.
├── build-opencv.sh
├── opencv-4.5.5
└── opencv_contrib-4.5.5
```

在脚本中，写入下面内容
> 安装到自定义的用户目录而不是系统目录是一种干净又卫生的做法，这时候只需要在环境变量中添加安装目录即可在使用中找到配置文件 `OpenCVConfig.cmake` 
> 
> 如果仍然希望在系统内安装，那么只需要将参数 `-DCMAKE_INSTALL_PREFIX` 删除，则会默认安装到 `/usr/local/` 内，或者也可以指定 `-DCMAKE_INSTALL_PREFIX` 为 `/usr/local`
```sh
VERSION=4.5.5

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
NUM_CORES=`sysctl -n hw.ncpu`   # for Darwin
# NUM_CORES=`nproc --all`         # for Linux
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
> 这里大概率会在 `cmake` 配置 OpenCV 过程中出现大量 `Warning` ，这是由于网络环境导致的，但是缺少的文件可能会在 make 编译过程中造成失败，这一部分考虑科学上网或者参考 [配置中未下载的文件](#配置中未下载的文件) 进行解决


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
--     Opencv version: 4.5.5
--     Opencv include: ~/program/opencv/include/opencv4
-- Configuring done
-- Generating done
-- Build files have been written to: ...
```

## 报错解决方案
### 配置中未下载的文件
在运行 cmake 配置 OpenCV 的时候，出现无法下载文件
```sh
-- xfeatures2d/boostdesc: Download: boostdesc_bgm.i
-- Try 1 failed
CMake Warning at cmake/OpenCVDownload.cmake:202 (message):
  xfeatures2d/boostdesc: Download failed: 56;"Failure when receiving data
  from the peer"

  For details please refer to the download log file:

  .../opencv-4.5.5/build/CMakeDownloadLog.txt

Call Stack (most recent call first):
  .../opencv_contrib-4.5.5/modules/xfeatures2d/cmake/download_boostdesc.cmake:22 (ocv_download)
  .../opencv_contrib-4.5.5/modules/xfeatures2d/CMakeLists.txt:12 (download_boost_descriptors)
```


根据配置时候出现的问题，我们可以在 `opencv-4.5.5/build/CMakeDownloadLog.txt` 中找到需要下载的文件内容
```txt
#do_copy "boostdesc_bgm.i" "0ea90e7a8f3f7876d450e4149c97c74f" "https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_bgm.i" ".../opencv-4.5.5/build/downloads/xfeatures2d"
#missing ".../opencv-4.5.5/build/downloads/xfeatures2d/boostdesc_bgm.i"
#cmake_download ".../opencv-4.5.5/.cache/xfeatures2d/boostdesc/0ea90e7a8f3f7876d450e4149c97c74f-boostdesc_bgm.i" "https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_bgm.i"
```
表示，确保复制 (do_copy) 从链接 [https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_bgm.i](https://raw.githubusercontent.com/opencv/opencv_3rdparty/34e4206aef44d50e6bbcd0ab06354b52e7466d26/boostdesc_bgm.i) 中下载的文件 `boostdesc_bgm.i` ，到目录 `opencv-4.5.5/build/downloads/xfeatures2d/boostdesc_bgm.i` 下


因此，如果在编译过程中出现因为缺少文件而导致的报错：
```sh
.../opencv/opencv_contrib-4.5.5/modules/xfeatures2d/src/boostdesc.cpp:654:20: fatal error: boostdesc_bgm.i: 没有那个文件或目录
           #include "boostdesc_bgm.i"
                    ^~~~~~~~~~~~~~~~~
compilation terminated.
make[2]: *** [modules/xfeatures2d/CMakeFiles/opencv_xfeatures2d.dir/build.make:417：modules/xfeatures2d/CMakeFiles/opencv_xfeatures2d.dir/src/boostdesc.cpp.o] 错误 1
make[1]: *** [CMakeFiles/Makefile2:8170：modules/xfeatures2d/CMakeFiles/opencv_xfeatures2d.dir/all] 错误 2
make[1]: *** 正在等待未完成的任务....
```
则需要根据配置时候到提示，下载文件到指定的目录下