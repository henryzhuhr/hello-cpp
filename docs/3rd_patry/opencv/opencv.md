

# Install 
[Installation in MacOS](https://docs.opencv.org/4.x/d0/db2/tutorial_macos_install.html)

[OpenCV configuration options reference](https://docs.opencv.org/4.x/db/d05/tutorial_config_reference.html)


# Compile
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
    -DBUILD_EXAMPLES=ON
NUM_CORES=`sysctl -n hw.ncpu`
make -j${NUM_CORES}
make install

cd ..
rm -rf build
```

in `~/.bashrc`
```sh
OpenCV_DIR=~/program/opencv/lib/cmake
export PATH=$PATH:${OpenCV_DIR}
```