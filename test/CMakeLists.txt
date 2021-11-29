include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message(" BINARY DIR:" ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/bin)

# gflags
find_package(gflags REQUIRED)
include_directories(GFLAGS_INCLUDE_DIR)
add_executable(test-gflags test-gflags.cpp)
target_link_libraries (test-gflags gflags)

# gflags
find_package(glog REQUIRED)
include_directories(GLOG_INCLUDE_DIR)
add_executable(test-glog test-glog.cpp)
target_link_libraries (test-glog glog::glog)
