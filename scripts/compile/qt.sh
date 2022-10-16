DEFAULT=$(echo -en '\033[0m')
RED=$(echo -en '\033[00;31m')
GREEN=$(echo -en '\033[00;32m')
LYELLOW=$(echo -en '\033[01;33m')

export SOFTWARE_DIR=$HOME/software
export INSTALL_DIR=$HOME/program

LIB_NAME=qt
VERSION=6.4.0


# https://download.qt.io/development_releases/qt/
SOURCE_DIR=$SOFTWARE_DIR/$LIB_NAME-everywhere-src-${VERSION}

if [ ! -d $SOURCE_DIR ]; then
    echo "$RED--> Not found $LIB_NAME-$VERSION source: $SOURCE_DIR $DEFAULT"
    exit
fi
echo "$GREEN--> Found $LIB_NAME-$VERSION source: $SOURCE_DIR $DEFAULT"

# enter
cd $SOURCE_DIR
mkdir -p build
cd build
rm CMakeCache.txt

# config
export Ninja_EXECUTABLE=/Users/henryzhu/program/ninjia/bin/ninja # -G "Ninja"
INSTALL_PREFIX=$INSTALL_DIR/$LIB_NAME-$VERSION
cmake .. \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX 
    # \
    # -DNinja_EXECUTABLE=$Ninja_EXECUTABLE \
    # -DFEATURE_clang=ON \
    # -DFEATURE_clangcpp=ON

# exit
# make
NUM_CORES=`sysctl -n hw.ncpu`   # for Darwin
# NUM_CORES=`nproc --all`         # for Linux

make -j4
# make -j${NUM_CORES}

# install
make install

# clean
cd $SOURCE_DIR
# rm -rf build


# To configure and build other Qt modules, you can use the following convenience script:
#         /Users/henryzhu/program/qt-6.3.0-rc/bin/qt-configure-module