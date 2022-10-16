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


# Download (boost_<version>.tar.bz2) from https://www.boost.org/users/download/
LIBRARY_NAME=boost
VERSION=1_80_0

LIBRARY_BASE=${LIBRARY_SOURCE_DIR}/${LIBRARY_NAME}_${VERSION}

PACKAGE_TYPE=tar.bz2
if [ ! -d $LIBRARY_BASE ]; then   
    echo "$YELLOW -- Not found source code directory: $LIBRARY_BASE $DEFAULT"
    if [ -f $LIBRARY_BASE.$PACKAGE_TYPE ]; then    
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
# BUILD_DIR=build
# cd $LIBRARY_BASE
# mkdir -p $BUILD_DIR
# cd $BUILD_DIR
cd $LIBRARY_BASE
# configure
./bootstrap.sh \
    --with-python=/usr/bin/python3

INSTALL_PREFIX=$PROGRAM_DIR/$LIBRARY_NAME-$VERSION
# ./b2 install -j8 \
./b2 install \
    --prefix=$INSTALL_PREFIX \
    --build-dir=./build


if [ -L $PROGRAM_DIR/$LIBRARY_NAME ]; then
    rm $LIBRARY_NAME
fi
ln -s $INSTALL_PREFIX $PROGRAM_DIR/$LIBRARY_NAME