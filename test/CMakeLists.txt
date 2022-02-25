include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message(" BINARY DIR:" ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/bin)

# gflags
find_package(gflags REQUIRED)
include_directories(GFLAGS_INCLUDE_DIR)
add_executable(test-gflags test-gflags.cpp)
target_link_libraries (test-gflags gflags)

# glog
find_package(glog REQUIRED)
include_directories(GLOG_INCLUDE_DIR)
add_executable(test-glog test-glog.cpp)
target_link_libraries (test-glog glog::glog)

# Opencv4
# set(OpenCV_DIR "C:/Users/henryzhu/OneDrive/Programming/Cpp/CppLibrary/Opencv/mingw-build/install")
find_package( OpenCV 4 REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
link_directories(${OpenCV_LIB_DIRS})
message(STATUS "OpenCV status:")
message(STATUS "    Opencv version: ${OpenCV_VERSION}")   
message(STATUS "    Opencv include: ${OpenCV_INCLUDE_DIRS}")

add_executable(test-opencv test-opencv.cpp)
target_link_libraries (test-opencv ${OpenCV_LIBS})