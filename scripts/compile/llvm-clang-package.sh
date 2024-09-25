DEFAULT=$(echo -en '\033[0m')
RED=$(echo -en '\033[00;31m')
GREEN=$(echo -en '\033[00;32m')
YELLOW=$(echo -en '\033[01;33m')

export SOFTWARE_DIR=$HOME/Software
export INSTALL_DIR=$HOME/program
export BUILD_DIRNAME=make-build

SOFTWARE=llvm
VERSION=15.0.0


cd $SOFTWARE_DIR
lib=llvm-project
SOURCE_DIR=$SOFTWARE_DIR/$lib-$VERSION
if [ ! -d $SOURCE_DIR ]; then   
    echo "$YELLOW -- Not found source code directory: $SOFTWARE_DIR/$SOURCE_DIR $DEFAULT" 
    if [ -f $SOURCE_DIR.src.tar.xz ]; then
        # Download (llvm-project-<version>.src.tar.xz) from https://github.com/llvm/llvm-project/releases
        echo "$GREEN -- Found $SOURCE_DIR source: $SOFTWARE_DIR/$SOURCE_DIR.src.tar.xz $DEFAULT"
        echo "$GREEN    extracting to $SOFTWARE_DIR/$SOURCE_DIR  $DEFAULT"
        tar -xjf $SOURCE_DIR.src.tar.xz
        mv $SOURCE_DIR.src $SOURCE_DIR
    else
        echo "$RED -- Not found source code: $SOFTWARE_DIR/$SOURCE_DIR.src.tar.xz $DEFAULT"
        exit
    fi
else
    echo "$GREEN -- source code $SOURCE_DIR found in $SOFTWARE_DIR/$SOURCE_DIR  $DEFAULT"
fi


cd $SOURCE_DIR
rm -rf $BUILD_DIRNAME
mkdir $BUILD_DIRNAME
cd $BUILD_DIRNAME

# configure: https://releases.llvm.org/8.0.0/docs/CMake.html
# INSTALL_PREFIX=$BASE_DIR/$SOFTWARE_NAME-$VERSION
INSTALL_PREFIX=$INSTALL_DIR/$SOFTWARE-$VERSION

# DLLVM_TARGETS_TO_BUILD X86;AArch64
cmake ../llvm \
    -G "Unix Makefiles" \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX \
    -DLLVM_TARGETS_TO_BUILD="AArch64" \
    -DCMAKE_BUILD_TYPE=Release \
    -DLLVM_ENABLE_PROJECTS="clang" \
    -DBUILD_SHARED_LIBS=ON \
    -DPYTHON_EXECUTABLE=$(which python3)

# make
NUM_CORES=`sysctl -n hw.ncpu`   # for Darwin
# NUM_CORES=`nproc --all`         # for Linux
make -j8

# install
make install

if [ -L $INSTALL_DIR/$SOFTWARE ]; then
    rm $SOFTWARE
fi
ln -s $INSTALL_PREFIX $INSTALL_DIR/$SOFTWARE