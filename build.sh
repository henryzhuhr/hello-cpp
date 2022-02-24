rm -rf bin
mkdir build
cd build 

rm ./CMakeCache.txt

cmake ..
make -j8

cd ..


# cd bin
# ./main


# run STL
# cd bin/stl
# ./stl_vector


