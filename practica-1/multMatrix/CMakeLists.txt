cmake_minimum_required (VERSION 2.8.11)

project (multMatrix)

add_executable (multMatrix main_multMatrix.cpp multmatrix.cpp multmatrix.h multmatrix_imp.cpp multmatrix_imp.h multmatrix_stub.cpp multmatrix_stub.h)


project(multMatrix LANGUAGES CXX)
add_executable(main main_multMatrix.cpp multmatrix.h multmatrix.cpp)
target_link_libraries(main pthread)

project(multMatrix_Client LANGUAGES CXX)
add_executable(mainClient utils.h utils.cpp multmatrix_stub.h multmatrix_stub_stub.cpp serialize.h serialize.cpp)
target_link_libraries(mainClient pthread)

project(multMatrix_Server LANGUAGES CXX)
add_executable(mainServer utils.h utils.cpp multmatrix_stub_imp.h multmatrix_stub_imp.cpp serialize.h serialize.cpp)
target_link_libraries(mainServer pthread)