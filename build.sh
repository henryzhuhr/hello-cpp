rm -rf bin
mkdir build
cd build 

rm ./CMakeCache.txt

cmake ..
make -j8

cd ..


cd bin
# ./main
# ./test-opencv "../images/lena.jpg"
./lvalue_rvalue
cd ..

# run STL
# cd bin/stl
# ./stl_vector


