cmake_minimum_required (VERSION 2.8.11)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS "-static")

project(multMatrix LANGUAGES CXX)
add_executable(main_multMatrix main_multMatrix.cpp multmatrix.h multmatrix.cpp)
target_link_libraries(main_multMatrix pthread)

project(multMatrix_Client LANGUAGES CXX)
add_executable(mainClient mainClient.cpp utils.h utils.cpp multmatrix_stub.h multmatrix_stub.cpp serialize.h serialize.cpp)
target_link_libraries(mainClient pthread)

project(multMatrix_Server LANGUAGES CXX)
add_executable(mainServer mainServer.cpp utils.h utils.cpp multmatrix_imp.h multmatrix_imp.cpp serialize.h serialize.cpp multmatrix.h multmatrix.cpp)
target_link_libraries(mainServer pthread)