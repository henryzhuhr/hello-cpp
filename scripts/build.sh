# --- VARIABLES ---
# 构建目录
BUILD_DIR=build
# 二进制输出目录
BINARY_DIR=bin
# 是否清理 1/0
IS_CLEAN=0

# --- CLEAN ---
[ -d $BINARY_DIR ] && rm -rf $BINARY_DIR

if [ -d $BUILD_DIR ]; then
    # [ -f $BUILD_DIR/CMakeCache.txt ] && rm -f $BUILD_DIR/CMakeCache.txt
    rm -rf $BUILD_DIR
fi
[ ! -d $BUILD_DIR ] && mkdir -p $BUILD_DIR

# --- BUILD and COMPILE ---
cd $BUILD_DIR

# 构建参数
build_args=(
    "-DCMAKE_INSTALL_PREFIX=.." # 安装到上级目录，如果注释掉则安装到系统目录 /usr/local
    "-DCMAKE_BUILD_TYPE=Release"
)

if command -v ninja &> /dev/null; then
    echo "-- [Info] Ninja is installed, version: $(ninja --version)"
    cmake .. -G "Ninja" ${buildArgs[@]}
    ninja -j8
    ninja install
else
    echo "-- [Warn] Ninja is not installed. Run 'apt install ninja-build' to install it."
    cmake .. ${buildArgs[@]}
    make -j8
    make install
fi


# --- RUN:: MAIN ---
CURRENTDIR=$(pwd)

if [ -d $BINARY_DIR ]; then
    cd bin
    ./hello-world
    ./hello-world $USER
else
    # cd /usr/local/bin
    hello-world
    hello-world $USER
fi

cd $CURRENTDIR

# --- UNINSTALL ---
if [ $IS_CLEAN -eq 1 ]; then
    if command -v ninja &> /dev/null; then
        ninja uninstall
    else
        make uninstall
    fi
fi

