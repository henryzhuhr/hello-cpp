cmake_minimum_required(VERSION 3.10)



# ==================================
#   Config Compiler (must before project() command)
# ==================================

# if (UNIX AND NOT APPLE) # Linux
#     target_compile_definitions(compile-platform PUBLIC "IS_LINUX")
# elseif (APPLE)          # MacOS
#     target_compile_definitions(compile-platform PUBLIC "IS_MACOS")
# elseif (WIN32)          # Windows
#     target_compile_definitions(compile-platform PUBLIC "IS_WINDOWS")
# endif ()

# CMAKE_C_COMPILER
if(NOT CMAKE_C_COMPILER)
    # set(CMAKE_C_COMPILER /usr/bin/gcc)
    # set(CMAKE_C_COMPILER /usr/bin/clang)
endif()
# get_filename_component(CMAKE_C_COMPILER ${CMAKE_C_COMPILER} ABSOLUTE)
message(STATUS "[INFO] C compiler: ${CMAKE_C_COMPILER}")

# CMAKE_CXX_COMPILER
if(NOT CMAKE_CXX_COMPILER)
    # set(CMAKE_C_COMPILER /usr/bin/g++)
    # set(CMAKE_C_COMPILER /usr/bin/clang++)
endif()
# get_filename_component(CMAKE_CXX_COMPILER ${CMAKE_CXX_COMPILER} ABSOLUTE)
message(STATUS "[INFO] CXX compiler: ${CMAKE_CXX_COMPILER}")


# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS  "-g -fexec-charset=utf-8 -m64 ")
# set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
# set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

add_compile_options(-std=c++17 -Wall -Werror)

project(dataStructure)


add_subdirectory(app)
