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
memory_deep_copy.exe

@REM rmdir /s /q "..\build"
