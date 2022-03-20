clear
source ~/.zshrc
CURRENTDIR=$(pwd)

rm -rf bin
mkdir build
cd build 
rm ./CMakeCache.txt


cmake ..
make -j8
cd ..

# --- RUN:: MAIN ---
cd $CURRENTDIR/bin
./main
# ./test-linkedlist

# --- RUN:: TEST ---
cd $CURRENTDIR/bin/test
# ./test-opencv $CURRENTDIR/images/lena.jpg
# ./test-gflags
# ./test-glog ./test_glog.log

# --- RUN:: CXX11 ---
cd $CURRENTDIR/bin/cxx11
# ./std_function
# ./std_bind
# ./variadic_templates
# ./variadic_templates-recursive_print
# ./smart_pointer

# --- RUN:: STL ---
# cd $CURRENTDIR/bin/stl
# ./stl_vector

# --- RUN:: algorithm ---
# cd $CURRENTDIR/bin/algorithm
# ./dynamic_programming

# rm -rf $CURRENTDIR/bin