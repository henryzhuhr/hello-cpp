DEFAULT=$(echo -en '\033[0m')
RED=$(echo -en '\033[00;31m')
GREEN=$(echo -en '\033[00;32m')
LYELLOW=$(echo -en '\033[01;33m')

export SOFTWARE_DIR=$HOME/software
export INSTALL_DIR=$HOME/program

LIB_NAME=qtbase
VERSION=6.4.0

# https://download.qt.io/development_releases/qt/
SOURCE_DIR=$SOFTWARE_DIR/$LIB_NAME-everywhere-src-${VERSION}

cd $SOFTWARE_DIR
if [ -d $SOURCE_DIR ]; then
    echo "$GREEN--> Found $LIB_NAME-$VERSION source: $SOURCE_DIR $DEFAULT"
    # "$GREEN--> Found $LIB_NAME-$VERSION source: $SOURCE_DIR $DEFAULT"
elif [ -f $SOURCE_DIR.tar.xz ]; then
    echo "$GREEN--> Found $LIB_NAME-$VERSION source: $SOURCE_DIR.tar.xz $DEFAULT"
    tar -xzf $SOURCE_DIR.tar.xz
elif [ -f $SOURCE_DIR.zip ]; then
    echo "$GREEN--> Found $LIB_NAME-$VERSION source: $SOURCE_DIR.zip $DEFAULT"
    unzip $SOURCE_DIR.zip
else
    echo "$LYELLOW--> Not found $LIB_NAME-$VERSION source: $SOURCE_DIR $DEFAULT"
    exit
fi

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


NUM_CORES=`sysctl -n hw.ncpu`   # for Darwin
# NUM_CORES=`nproc --all`         # for Linux

make -j${NUM_CORES}

# install
make install

# clean
# cd $SOFTWARE_DIR
# rm -rf $SOURCE_DIR
