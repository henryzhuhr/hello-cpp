source ~/.zshrc


rm -rf bin
mkdir build
cd build 
# rm ./CMakeCache.txt
rm -rf build


cmake .. -G "Ninja" -DCMAKE_BUILD_TYPE=Release
# make -j8
ninja

CURRENTDIR=$(pwd)

# --- RUN:: MAIN ---
cd $CURRENTDIR/app
./move_constructor-optim


# ./test-linkedlist
# cd $CURRENTDIR/app/cxx11
# ./cxx11

# --- RUN:: TEST ---
# cd $CURRENTDIR/app/test
# ./test-opencv $CURRENTDIR/images/lena.jpg
# ./test-gflags
# ./test-glog ./test_glog.log

# --- RUN:: CXX11 ---
# cd $CURRENTDIR/app/cxx11
# ./std_function
# ./std_bind
# ./variadic_templates
# ./variadic_templates-recursive_print
# ./smart_pointer
# ./universal_reference

# --- RUN:: STL ---
# cd $CURRENTDIR/app/stl
# ./stl_vector

# --- RUN:: algorithm ---
# cd $CURRENTDIR/app/algorithm
# ./dynamic_programming

# --- RUN:: sort ---
# cd $CURRENTDIR/app/bin/sort
# ./sort

# rm -rf $CURRENTDIR/bin


cd $CURRENTDIR