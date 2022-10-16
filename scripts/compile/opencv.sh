BASE_DIR=$HOME/program
LIB_NAME=opencv
VERSION=4.5.5

SOURCE_DIR=$BASE_DIR/src/$LIB_NAME-${VERSION}
CONTRIB_DIR=$BASE_DIR/src/${LIB_NAME}_contrib-${VERSION}

DEFAULT=$(echo -en '\033[0m')
RED=$(echo -en '\033[00;31m')
GREEN=$(echo -en '\033[00;32m')

if [ ! -d $SOURCE_DIR ]; then
    echo "$RED--> Not found $LIB_NAME-$VERSION source: $SOURCE_DIR $DEFAULT"
    exit
fi
echo "$GREEN--> Found $LIB_NAME-$VERSION source: $SOURCE_DIR $DEFAULT"

if [ ! -d $CONTRIB_DIR ]; then
    echo "$RED--> Not found ${LIB_NAME}_contrib-$VERSION source: $CONTRIB_DIR $DEFAULT"
    exit
fi
echo "$GREEN--> Found ${LIB_NAME}_contrib-$VERSION source: $CONTRIB_DIR $DEFAULT"

# enter
cd $SOURCE_DIR
rm -rf build
mkdir -p build
cd build
rm CMakeCache.txt

# config
INSTALL_PREFIX=$BASE_DIR/$LIB_NAME-$VERSION
# INSTALL_PREFIX=$BASE_DIR/$LIB_NAME

# -DCMAKE_SYSTEM_PROCESSOR=arm64 \
export PYTHON3_EXECUTABLE=/Users/henryzhu/miniconda3/envs/torch/bin/python3
cmake .. \
    -DCMAKE_OSX_ARCHITECTURES=arm64 \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX \
    -DOPENCV_EXTRA_MODULES_PATH=$CONTRIB_DIR/modules \
    -DCMAKE_BUILD_TYPE=Release \
    -DOPENCV_GENERATE_PKGCONFIG=ON \
    -DBUILD_SHARED_LIBS=ON \
    -DBUILD_STATIC_LIBS=ON \
    -DBUILD_opencv_apps=ON \
    -DBUILD_EXAMPLES=OFF \
    -DWITH_ONNX=ON \
    -DONNXRT_ROOT_DIR=$ORT_INSTALL_DIR
    # -DWITH_CUDA=ON \
    # -DOPENCV_DNN_CUDA=ON \
    # -DCUDNN_LIBRARY=$cuDNN_HOME/lib \
    # -DCUDNN_INCLUDE_DIR=$cuDNN_HOME/include 
# exit

NUM_CORES=`sysctl -n hw.ncpu`   # for Darwin
# NUM_CORES=`nproc --all`         # for Linux
make -j${NUM_CORES}
# make -j4

# install
make install

# clean
cd $SOURCE_DIR
# rm -rf build