DEFAULT=$(echo -en '\033[0m')
RED=$(echo -en '\033[00;31m')
GREEN=$(echo -en '\033[00;32m')
LYELLOW=$(echo -en '\033[01;33m')

export SOFTWARE_DIR=$HOME/software
export INSTALL_DIR=$HOME/program

SOFTWARE_NAME=llvm
VERSION=8.x

# See: https://releases.llvm.org/8.0.0/docs/GettingStarted.html#getting-started-with-llvm
# See: https://releases.llvm.org/8.0.0/docs/GettingStarted.html#getting-started-with-llvm
# See: https://csstormq.github.io/blog/LLVM%20之%20Clang%20篇（1）：如何从源码构建并安装%20Clang
cd $SOFTWARE_DIR
SOURCE_DIR=$SOFTWARE_DIR/llvm-project/llvm

if [ ! -d $SOURCE_DIR ]; then
    echo "$RED--> Not found $LIB_NAME-$VERSION source: $SOURCE_DIR $DEFAULT"
    cd $SOFTWARE_DIR
    "$GREEN--> Try to download source code from https://github.com/llvm/llvm-project.git $DEFAULT"
    git clone https://github.com/llvm/llvm-project.git
    "$GREEN--> checkout release/$VERSION $DEFAULT"
    git checkout release/$VERSION
    "$LYELLOW--> Please run this shell again $DEFAULT"
    exit
fi
echo "$GREEN--> Found $LIB_NAME-$VERSION source: $SOURCE_DIR $DEFAULT"

# source code of Clang in `llvm-project/clang`

# enter
cd $SOURCE_DIR
rm -rf make-build
mkdir make-build
cd make-build

# configure: https://releases.llvm.org/8.0.0/docs/CMake.html
# INSTALL_PREFIX=$BASE_DIR/$SOFTWARE_NAME-$VERSION
INSTALL_PREFIX=$INSTALL_DIR/$SOFTWARE_NAME

# DLLVM_TARGETS_TO_BUILD X86;AArch64
cmake .. \
    -G "Unix Makefiles" \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX \
    -DLLVM_TARGETS_TO_BUILD="X86" \
    -DCMAKE_BUILD_TYPE=Release \
    -DLLVM_ENABLE_PROJECTS="clang" \
    -DBUILD_SHARED_LIBS=ON \
    -DPYTHON_EXECUTABLE=$(which python3)

# make
make -j8

# install
make install

