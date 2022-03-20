include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(.  myLib)

# ------ dynamic-link-library ------
add_library(myLib_shared SHARED ${myLib})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/lib)