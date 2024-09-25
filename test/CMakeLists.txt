include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/test)
message(" BINARY DIR:" ${PROJECT_SOURCE_DIR}/bin/test)

link_directories(${PROJECT_SOURCE_DIR}/bin/test)

# gflags : gflags_DIR
find_package(gflags REQUIRED)
message(STATUS "gflags status: ${GFLAGS_INCLUDE_DIR}")
include_directories(GFLAGS_INCLUDE_DIR)
add_executable(test-gflags test-gflags.cpp)
target_link_libraries (test-gflags gflags)

# glog : glog_DIR
find_package(glog REQUIRED)
message(STATUS "glog status: ${GLOG_INCLUDE_DIR}")
include_directories(GLOG_INCLUDE_DIR)
add_executable(test-glog test-glog.cpp)
target_link_libraries (test-glog glog::glog)

# Opencv4 : OpenCV_DIR
find_package(OpenCV 4 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
link_directories(${OpenCV_LIB_DIRS})
message(STATUS "OpenCV status:")
message(STATUS "    Opencv version: ${OpenCV_VERSION}")   
message(STATUS "    Opencv include: ${OpenCV_INCLUDE_DIRS}")

add_executable(test-opencv test-opencv.cpp)
target_link_libraries (test-opencv ${OpenCV_LIBS})