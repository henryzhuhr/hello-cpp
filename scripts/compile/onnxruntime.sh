BASE_DIR=$HOME/program
LIB_NAME=onnxruntime
VERSION=1.11.0

# clone指定分支 发布版1.7.2
# git clone -b rel-1.7.2 https://github.com/microsoft/onnxruntime.git
 
# 拉取子项目
# git submodule update --init --recursive



SOURCE_DIR=$BASE_DIR/src/$LIB_NAME

DEFAULT=$(echo -en '\033[0m')
RED=$(echo -en '\033[00;31m')
LCYAN=$(echo -en '\033[01;36m')

cd $BASE_DIR/src
if [ ! -d $SOURCE_DIR ]; then
    git_url=https://github.com/microsoft/onnxruntime.git
    echo "$LCYAN--> Clone $LIB_NAME from $git_url $DEFAULT"
    git clone $git_url
    exit
else
    echo "$GREEN--> Found $LIB_NAME source: $SOURCE_DIR $DEFAULT"
fi
cd $SOURCE_DIR
git submodule update --init --recursive

# exit
# enter
cd $SOURCE_DIR/cmake
rm -rf build
mkdir build
cd build

# config
# INSTALL_PREFIX=$BASE_DIR/$LIB_NAME-$VERSION
INSTALL_PREFIX=$BASE_DIR/$LIB_NAME
cmake .. \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX \
    -DBUILD_SHARED_LIBS=ON \
    -DBUILD_STATIC_LIBS=ON \
    -Donnxruntime_ENABLE_PYTHON=ON

# make
NUM_CORES=`sysctl -n hw.ncpu`   # for Darwin
# NUM_CORES=`nproc --all`         # for Linux
make -j${NUM_CORES}

# install
make install

cd ..
rm -rf build


./build.sh \
    --config Release \
    --osx_arch arm64 \
    --osx_arch arm64 \
    --build_wheel \
    --enable_pybind \
    --parallel \
    --use_coreml \
    --use_extensions \
    --skip_tests \
    --build_shared_lib