cmake_minimum_required(VERSION 3.10)

string(ASCII 27 Esc)
set(ColourReset "${Esc}[m")
set(BoldRed "${Esc}[1;31m")
set(BoldGreen "${Esc}[1;32m")
set(BoldYellow "${Esc}[1;33m")
set(BoldMagenta "${Esc}[1;35m")
set(BoldCyan "${Esc}[1;36m")
set(BoldWhite "${Esc}[1;37m")

# CMAKE_C_COMPILER
if(NOT CMAKE_C_COMPILER)
    if(APPLE)
        set(CMAKE_C_COMPILER /usr/bin/clang)
    elseif(UNIX AND NOT APPLE)
        set(CMAKE_C_COMPILER /usr/bin/gcc)
    elseif(WIN32)
        set(CMAKE_C_COMPILER C:/mingw64/bin/x86_64-w64-mingw32-gcc.exe)
    else()
        message(FATAL_ERROR "Unsupported platform, please set CMAKE_C_COMPILER")
    endif()
endif()

message(STATUS "[INFO] C compiler: ${CMAKE_C_COMPILER}")

# CMAKE_CXX_COMPILER
if(NOT CMAKE_CXX_COMPILER)
    if(APPLE)
        set(CMAKE_CXX_COMPILER /usr/bin/clang++)
    elseif(UNIX AND NOT APPLE)
        set(CMAKE_CXX_COMPILER /usr/bin/g++)
    elseif(WIN32)
        set(CMAKE_CXX_COMPILER C:/mingw64/bin/x86_64-w64-mingw32-g++.exe)
    else()
        message(FATAL_ERROR "Unsupported platform, please set CMAKE_CXX_COMPILER")
    endif()
endif()

message(STATUS "[INFO] CXX compiler: ${CMAKE_CXX_COMPILER}")

# CXX-standard
set(CMAKE_CXX_STANDARD 11)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

# CXX-flags
# set(CMAKE_CXX_FLAGS  "$ENV{CXXFLAGS} -g -fexec-charset=GBK")
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -g -fno-elide-constructors")
# 优化禁止
# -fno-elide-constructors # 禁止编译器优化返回值 RVO

# -------- Debug config --------
# -- dubug 模式------------------这个非常重要，否则无法进入断点
# add_definitions("-Wall -g")
# set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
# SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
message("${BoldCyan}Configuration Summary:${ColourReset}")
message("  ${BoldCyan}   Plateform: ${BoldGreen}${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION}${ColourReset}")
message("  ${BoldCyan}Architecture: ${BoldGreen}${CMAKE_SYSTEM_PROCESSOR}${ColourReset}")
message("  ${BoldCyan}     C flags: ${BoldGreen}${CMAKE_C_FLAGS}${ColourReset}")
message("  ${BoldCyan}   C++ flags: ${BoldGreen}${CMAKE_CXX_FLAGS}${ColourReset}")


project(project) # 必须在设置编译器后面

# add_subdirectory(src)
add_subdirectory(app)
# add_subdirectory(test)
