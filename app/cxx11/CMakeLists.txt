set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/cxx11)

# link_directories(${PROJECT_SOURCE_DIR}/bin/stl)

add_executable(std_function std_function.cpp)           # std_function
add_executable(std_bind std_bind.cpp)                   # std_bind
add_executable(lambda_expression lambda_expression.cpp) # Lambda expression
add_executable(lvalue_rvalue lvalue_rvalue.cpp)         # lvalue rvalue
