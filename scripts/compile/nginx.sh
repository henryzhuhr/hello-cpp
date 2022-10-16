BASE_DIR=$HOME/program
LIB_NAME=nginx
VERSION=1.21.6

SOURCE_DIR=$BASE_DIR/src/$LIB_NAME-$VERSION

DEFAULT=$(echo -en '\033[0m')
RED=$(echo -en '\033[00;31m')
GREEN=$(echo -en '\033[00;32m')

# check dir
if [ ! -d $SOURCE_DIR ]; then
    echo "$RED--> Not found $LIB_NAME-$VERSION source: $SOURCE_DIR $DEFAULT"
    exit
fi
echo "$GREEN--> Found $LIB_NAME-$VERSION source: $SOURCE_DIR $DEFAULT"



# enter
cd $SOURCE_DIR

# config
INSTALL_PREFIX=$BASE_DIR/$LIB_NAME-$VERSION
./configure \
    --prefix=INSTALL_PREFIX
    --with-http_stub_status_module \
    --with-http_ssl_module

    # --add-module=/home/fastdfs-nginx-module/src

# make
NUM_CORES=`sysctl -n hw.ncpu`
make -j${NUM_CORES}