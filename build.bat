@REM @echo off

rmdir /s /q bin
@REM rmdir /s /q build
del "build\CMakeCache.txt"

mkdir build
cd build
cmake ^
    -DCMAKE_BUILD_TYPE=Release ^
    ..   
@REM cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
make -j8

cd ../bin
generic_programming.exe

@REM rmdir /s /q "..\build"
