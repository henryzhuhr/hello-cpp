cmake_minimum_required(VERSION 3.10)



# ==================================
#   Config Compiler (must before project() command)
# ==================================
# set(CMAKE_C_COMPILER /usr/bin/gcc)
# set(CMAKE_CXX_COMPILER /usr/bin/g++)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS  "-g -fexec-charset=utf-8 -m64 ")
# set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
# set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

add_compile_options(-std=c++17 -Wall -Werror)

project(dataStructure)


add_subdirectory(app)
