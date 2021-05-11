aux_source_directory(./  DIR_SRCS)
message(STATUS "[INFO] compile by: ${DIR_SRCS}")
include_directories(${PROJECT_SOURCE_DIR}/include)

# ------ static
# add_library(src STATIC ${DIR_SRCS})
# SET_TARGET_PROPERTIES (src PROPERTIES OUTPUT_NAME "src")


# ------ shared
add_library(dataReader SHARED ${DIR_SRCS})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message(STATUS "[INFO] SHARED linked library compiled by : " ${DIR_SRCS})

target_link_libraries(dataReader
    wsock32 
)