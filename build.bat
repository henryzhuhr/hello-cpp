@REM @echo off

set HOME=%cd%

@REM set CMAKE_BIN=%HOME%/tools/cmake-3.20.1-windows-x86_64/bin/
@REM set path=%PATH%;%CMAKE_BIN%

@REM set MinGW64_BIN=%HOME%/tools/mingw64/bin/
@REM set path=%PATH%;%MinGW64_BIN%



rmdir /s /q bin
rmdir /s /q build


mkdir build
cd build
cmake ^
    -G "MinGW Makefiles" ^
    -DCMAKE_BUILD_TYPE=Release ^
    ..   
@REM cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
make -j8


cd ../

rmdir /s /q build

cd bin
memory_deep_copy.exe

