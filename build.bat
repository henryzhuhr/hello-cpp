@REM @echo off

rmdir /s /q bin
@REM rmdir /s /q build
del "build\CMakeCache.txt"

mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE:STRING=Debug ..  
@REM cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
make -j8

cd ..


@REM --- RUN:: MAIN ---
cd bin
cd ..

@REM --- RUN:: STL ---
cd bin
cd ..

@REM --- RUN:: algorithm ---
cd bin/algorithm
dynamic_programming.exe
cd ../..
