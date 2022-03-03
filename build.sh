rm -rf bin
mkdir build
cd build 

rm ./CMakeCache.txt

cmake ..
make -j8

cd ..



# --- RUN:: MAIN ---
cd bin
# ./main
# ./test-opencv "../images/lena.jpg"
# ./lvalue_rvalue
cd ..

# --- RUN:: STL ---
# cd bin/stl
# ./stl_vector

# --- RUN:: algorithm ---
cd bin/algorithm
./dynamic_programming
cd ../..
