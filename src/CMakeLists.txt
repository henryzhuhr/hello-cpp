include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(.  intList)

# ------ dynamic-link-library ------
add_library(intList SHARED ${intList})
SET_TARGET_PROPERTIES (intList PROPERTIES VERSION 1.2 SOVERSION 1)    # VERSION for dll version, SOVERSION for API version
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/lib)

# See https://blog.csdn.net/sinat_31608641/article/details/121712590