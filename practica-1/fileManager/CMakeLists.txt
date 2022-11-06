cmake_minimum_required (VERSION 2.8.11)

project (fileManager)
add_executable (fileManager main_fm.cpp filemanager.cpp filemanager.h utils.cpp utils.h fileManagerClient.cpp fileManagerClient.h serialize.h serialize.cpp)
target_link_libraries(fileManager pthread)

project(fileManagerServer LANGUAGES CXX)
add_executable(fileServer mainFileServer.cpp utils.cpp utils.h fileManagerServer.cpp fileManagerServer.h fileManagerClient.cpp fileManagerClient.h filemanager.cpp filemanager.h serialize.h serialize.cpp)
target_link_libraries(fileServer pthread)

project(fileClientConsole LANGUAGES CXX)
add_executable(clientConsole mainConsole.cpp utils.cpp utils.h fileManagerClient.cpp fileManagerClient.h filemanager.cpp filemanager.h serialize.h serialize.cpp clientConsole.h clientConsole.cpp)
target_link_libraries(clientConsole pthread)
