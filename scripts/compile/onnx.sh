BASE_DIR=$HOME/program
LIB_NAME=onnx

SOURCE_DIR=$BASE_DIR/src/$LIB_NAME


DEFAULT=$(echo -en '\033[0m')
RED=$(echo -en '\033[00;31m')
GREEN=$(echo -en '\033[00;32m')
LCYAN=$(echo -en '\033[01;36m')

cd $BASE_DIR/src
protobuf_src=$BASE_DIR/src/protobuf
if [ ! -d $protobuf_src ]; then
    git_url=https://github.com/protocolbuffers/protobuf.git
    git clone $git_url
    echo "$LCYAN--> Clone $LIB_NAME source from $git_url to: $protobuf_src $DEFAULT" 
else
    echo "$GREEN--> Found protobuf source: $protobuf_src $DEFAULT"
fi

# get source
if [ ! -d $SOURCE_DIR ]; then   
    git_url=https://github.com/onnx/onnx.git
    git clone $git_url
    echo "$LCYAN--> Clone $LIB_NAME source from $git_url to: $SOURCE_DIR $DEFAULT" 
else
    echo "$GREEN--> Found $LIB_NAME source: $SOURCE_DIR $DEFAULT"
fi



# --- build protobuf ---
# enter
cd $protobuf_src
mkdir -p build_source
cd build_source

# config
INSTALL_PREFIX=$BASE_DIR/protobuf
cmake .. \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX \
    -DCMAKE_BUILD_TYPE=Release \
    -Dprotobuf_BUILD_SHARED_LIBS=ON \
    -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
    -Dprotobuf_BUILD_TESTS=OFF 
export NUM_CORES=`sysctl -n hw.ncpu`   # for Darwin
make -j${NUM_CORES}
make install
cd $protobuf_src
rm -rf build_source
export CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH:$INSTALL_PREFIX




# --- build onnx ---
# enter
cd $SOURCE_DIR
git submodule update --init --recursive

mkdir -p build_source
cd build_source

INSTALL_PREFIX=$BASE_DIR/$LIB_NAME
cmake .. \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX \
    -DONNX_USE_LITE_PROTO=ON

make
make install
exit
# /Users/henryzhu/program/protobuf/lib/cmake
# CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH:$INSTALL_PREFIX