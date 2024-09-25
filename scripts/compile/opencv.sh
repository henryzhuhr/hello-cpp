# OpenCV Get Started: https://opencv.org/get-started
# Build from source
#   - Linux: https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html
#   - MacOS: https://docs.opencv.org/master/d0/db2/tutorial_macos_install.html


# PLEASE download source package(.tar.gz) from https://opencv.org/releases/

SOFTWARE_DIR=$HOME/software # CHANGE: source code directory(.tar.gz)
INSTALL_DIR=$HOME/program   # CHANGE: install directory

LIB_NAME=opencv
VERSION=4.8.0  # CHANGE: package version



DEFAULT=$(echo -en '\033[0m')
RED=$(echo -en '\033[00;31m')
GREEN=$(echo -en '\033[00;32m')


SOURCE_DIR=$SOFTWARE_DIR/$LIB_NAME-$VERSION
CONTRIB_DIR=$SOFTWARE_DIR/${LIB_NAME}_contrib-$VERSION

if [ ! -d $SOURCE_DIR ]; then
    if [ -f $SOURCE_DIR.tar.gz ]; then
        echo "$GREEN--> Found $LIB_NAME-$VERSION source package: $SOURCE_DIR.tar.gz $DEFAULT"
        tar xf $SOURCE_DIR.tar.gz -C $SOFTWARE_DIR
    elif [ -f $SOURCE_DIR.tar.bz2 ]; then
        echo "$GREEN--> Found $LIB_NAME-$VERSION source package: $SOURCE_DIR.tar.bz2 $DEFAULT"
        tar xf $SOURCE_DIR.tar.bz2 -C $SOFTWARE_DIR
    else
        echo "$RED--> Not found $LIB_NAME-$VERSION source: $SOURCE_DIR.tar.bz2 $DEFAULT"
        exit
    fi
fi
echo "$GREEN--> Found $LIB_NAME-$VERSION source: $SOURCE_DIR $DEFAULT"

if [ ! -d $CONTRIB_DIR ]; then
    if [ -f $CONTRIB_DIR.tar.gz ]; then
        echo "$GREEN--> Found $LIB_NAME-$VERSION source package: $CONTRIB_DIR.tar.gz $DEFAULT"
        tar xf $CONTRIB_DIR.tar.gz -C $SOFTWARE_DIR
    elif [ -f $CONTRIB_DIR.tar.bz2 ]; then
        echo "$GREEN--> Found $LIB_NAME-$VERSION source package: $CONTRIB_DIR.tar.bz2 $DEFAULT"
        tar xf $CONTRIB_DIR.tar.bz2 -C $SOFTWARE_DIR
    else
        echo "$RED--> Not found $LIB_NAME-$VERSION source: $CONTRIB_DIR.tar.bz2 $DEFAULT"
        exit
    fi
fi
echo "$GREEN--> Found ${LIB_NAME}_contrib-$VERSION source: $CONTRIB_DIR $DEFAULT"


# enter
cd $SOURCE_DIR
rm -rf build
mkdir -p build
cd build
if [ -f CMakeCache.txt ]; then
    rm CMakeCache.txt
fi

# config
INSTALL_PREFIX=$INSTALL_DIR/$LIB_NAME-$VERSION

# -DCMAKE_SYSTEM_PROCESSOR=arm64 \
PYTHON3_EXECUTABLE=$(which python3)
PYTHON3_INCLUDE_DIR=$(python3 -c "from distutils.sysconfig import get_python_inc; print(get_python_inc())")
PYTHON3_NUMPY_INCLUDE_DIRS=$(python3 -c "import numpy; print(numpy.get_include())")
if [ -z $PYTHON3_NUMPY_INCLUDE_DIRS ]; then
    echo "${RED}[ERROR] python package numpy not found. Exit${DEFAULT}"
    echo " try run \"python3 -m pip install numpy\""
    exit
fi

cmake .. \
    -DCMAKE_OSX_ARCHITECTURES=arm64 \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX \
    -DOPENCV_EXTRA_MODULES_PATH=$CONTRIB_DIR/modules \
    -DCMAKE_BUILD_TYPE=Release \
    -DOPENCV_GENERATE_PKGCONFIG=ON \
    -DBUILD_SHARED_LIBS=ON -DBUILD_STATIC_LIBS=ON \
    -DBUILD_opencv_apps=ON \
    -DOPENCV_DOWNLOAD_MIRROR_ID=gitcode \
    -DBUILD_EXAMPLES=OFF \
    -DPYTHON3_EXECUTABLE=$PYTHON3_EXECUTABLE -DPYTHON3_INCLUDE_DIR=$PYTHON3_INCLUDE_DIR -DPYTHON3_NUMPY_INCLUDE_DIRS=$PYTHON3_NUMPY_INCLUDE_DIRS \
    -DWITH_ONNX=ON -DONNXRT_ROOT_DIR=$ORT_INSTALL_DIR 
    # -DWITH_CUDA=ON \
    # -DOPENCV_DNN_CUDA=ON \
    # -DCUDNN_LIBRARY=$cuDNN_HOME/lib \
    # -DCUDNN_INCLUDE_DIR=$cuDNN_HOME/include 

if [ "$(uname)" = "Darwin" ]; then
    NUM_CORES=`sysctl -n hw.ncpu`
elif [ "$(expr substr $(uname -s) 1 5)" = "Linux" ]; then
    NUM_CORES=`nproc --all`
else
    NUM_CORES=4
fi

make -j${NUM_CORES}


# install
make install

# clean
cd $SOURCE_DIR
# rm -rf build
rm -rf $SOURCE_DIR
rm -rf $CONTRIB_DIR


echo "
 -- set variable :  ${GREEN}
export OpenCV_HOME="${INSTALL_PREFIX}/opencv-$VERSION" # opencv
export OpenCV_DIR=\${OpenCV_HOME}/lib/cmake
${DEFAULT}";