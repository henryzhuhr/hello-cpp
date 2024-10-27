include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

aux_source_directory(src hello_library_src)
message(STATUS "[INFO] source code of hello_library: ${hello_library_src}")


# ------ dynamic-link-library ------
# 将源码 ${hello_library_src} 编译成动态库 hello_library
add_library(hello_library SHARED ${hello_library_src})


# 将库 hello_library 重命名为 hello_library
SET_TARGET_PROPERTIES (hello_library PROPERTIES OUTPUT_NAME "hello_library") 
SET_TARGET_PROPERTIES(hello_library PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# 同时我们还可以修改动态库的版本号
SET_TARGET_PROPERTIES (hello_library PROPERTIES VERSION 1.2 SOVERSION 1)    # VERSION for dll version, SOVERSION for API version

# See https://blog.csdn.net/sinat_31608641/article/details/121712590
# See https://zhuanlan.zhihu.com/p/551251797


# ------ 可执行文件 ------
add_executable(hello-dynamic-library app/hello_dynamic_library_test.cpp ${hello_library})

install(TARGETS hello-dynamic-library DESTINATION bin)

# <prefix>/include/
INSTALL(FILES hello.h DESTINATION include/hello_library.hpp)
