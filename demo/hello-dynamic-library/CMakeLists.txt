include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

aux_source_directory(src hello_library)

# ------ dynamic-link-library ------
add_library(hello_library SHARED ${hello_library})
# SET_TARGET_PROPERTIES (hello_library PROPERTIES VERSION 1.2 SOVERSION 1)    # VERSION for dll version, SOVERSION for API version

# See https://blog.csdn.net/sinat_31608641/article/details/121712590


# ------ 可执行文件 ------
add_executable(hello-dynamic-library app/hello_dynamic_library_test.cpp ${hello_library})

install(TARGETS hello-dynamic-library DESTINATION bin)

