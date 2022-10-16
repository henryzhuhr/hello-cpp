
BASE_DIR=$HOME/program
LIB_NAME=gflags
VERSION=2.2.2


SOURCE_DIR=$BASE_DIR/src/$LIB_NAME-${VERSION}

DEFAULT=$(echo -en '\033[0m')
RED=$(echo -en '\033[00;31m')
GREEN=$(echo -en '\033[00;32m')

if [ ! -d $SOURCE_DIR ]; then
    echo "$RED--> Not found $LIB_NAME-$VERSION source: $SOURCE_DIR $DEFAULT"
    exit
fi
echo "$GREEN--> Found $LIB_NAME-$VERSION source: $SOURCE_DIR $DEFAULT"

# enter
cd $SOURCE_DIR
rm -rf build
mkdir build
cd build

# config
# INSTALL_PREFIX=$BASE_DIR/$LIB_NAME-$VERSION
INSTALL_PREFIX=$BASE_DIR/$LIB_NAME
cmake .. \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX \
    -DBUILD_SHARED_LIBS=ON \
    -DBUILD_STATIC_LIBS=ON

# make
NUM_CORES=`sysctl -n hw.ncpu`
make -j${NUM_CORES}

# install
make install

cd ..
rm -rf build