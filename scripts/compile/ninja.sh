DEFAULT=$(echo -en '\033[0m')
RED=$(echo -en '\033[00;31m')
GREEN=$(echo -en '\033[00;32m')
YELLOW=$(echo -en '\033[01;33m')

# Set Global Variable
if [ ! $LIBRARY_SOURCE_DIR ];then
	LIBRARY_SOURCE_DIR=$HOME/software
fi
if [ ! $PROGRAM_DIR ];then
	PROGRAM_DIR=$HOME/program
fi



LIBRARY_NAME=ninja
VERSION=1.11.1

LIBRARY_BASE=${LIBRARY_SOURCE_DIR}/${LIBRARY_NAME}-${VERSION}

PACKAGE_TYPE=tar.gz
if [ ! -d $LIBRARY_BASE ]; then   
    echo "$YELLOW -- Not found source code directory: $LIBRARY_BASE $DEFAULT"
    if [ -f $LIBRARY_BASE.$PACKAGE_TYPE ]; then
        # Download (llvm-project-<version>.src.tar.xz) from https://github.com/llvm/llvm-project/releases
        echo "$GREEN -- Found $LIBRARY_BASE source: $LIBRARY_BASE.$PACKAGE_TYPE $DEFAULT"
        echo "$GREEN    extracting to $LIBRARY_BASE  $DEFAULT"
        tar -xf $LIBRARY_BASE.$PACKAGE_TYPE -C $LIBRARY_SOURCE_DIR
    else
        echo "$RED -- Not found source code: $LIBRARY_BASE.$PACKAGE_TYPE $DEFAULT"
        exit
    fi
else
    echo "$GREEN -- source code $LIBRARY_BASE found in $LIBRARY_BASE  $DEFAULT"
fi

# enter
BUILD_DIR=build
cd $LIBRARY_BASE
mkdir -p $BUILD_DIR
cd $BUILD_DIR

# configure
INSTALL_PREFIX=$PROGRAM_DIR/$LIBRARY_NAME-$VERSION
cmake .. \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX
make
make install


if [ -L $PROGRAM_DIR/$LIBRARY_NAME ]; then
    rm $LIBRARY_NAME
fi
ln -s $INSTALL_PREFIX $PROGRAM_DIR/$LIBRARY_NAME