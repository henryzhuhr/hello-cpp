include_directories(${PROJECT_SOURCE_DIR}/include)

# add_subdirectory(cxx11)
# add_subdirectory(stl)
# add_subdirectory(algorithm)
# add_subdirectory(design_pattern)
# add_subdirectory(sort)

# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# message(" BINARY DIR:" ${PROJECT_SOURCE_DIR}/bin)

# link_directories(${PROJECT_SOURCE_DIR}/bin)





# add_executable(main main.cpp)
# target_link_libraries(main intList)

# add_executable(test-linkedlist test-linkedlist.cpp)
# add_executable(test-linkedlist test-linkedlist.cpp)

# add_executable(reference reference.cpp)                   # reference in CXX

add_executable(memory_shallow_copy memory_shallow_copy.cpp) # copy in CXX
add_executable(memory_deep_copy memory_deep_copy.cpp)       # copy in CXX
add_executable(move_constructor move_constructor.cpp)       # move constructor in CXX
add_executable(move_constructor-optim move_constructor-optim.cpp)       # move constructor in CXX


# add_executable(generic_programming generic_programming.cpp) # Generic Programming

# add_executable(initializer_list initializer_list.cpp)       # Initializer List

# add_executable(recursive_print recursive_print.cpp)         # recursive print

# add_executable(rvalue rvalue.cpp)                           # rvalue
# add_executable(producer_consumer producer_consumer.cpp)                           # producer_consumer



# file(COPY ${PROJECT_SOURCE_DIR}/tools/mingw64/bin/libstdc++-6.dll DESTINATION ${PROJECT_SOURCE_DIR}/bin FOLLOW_SYMLINK_CHAIN)
# file(COPY ${PROJECT_SOURCE_DIR}/tools/mingw64/bin/libwinpthread-1.dll DESTINATION ${PROJECT_SOURCE_DIR}/bin FOLLOW_SYMLINK_CHAIN)
# file(COPY ${PROJECT_SOURCE_DIR}/tools/mingw64/bin/libgcc_s_seh-1.dll DESTINATION ${PROJECT_SOURCE_DIR}/bin FOLLOW_SYMLINK_CHAIN)