# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager

# Include any dependencies generated for this target.
include CMakeFiles/pruebaCliente.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pruebaCliente.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pruebaCliente.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pruebaCliente.dir/flags.make

CMakeFiles/pruebaCliente.dir/mainPruebaCliente.cpp.o: CMakeFiles/pruebaCliente.dir/flags.make
CMakeFiles/pruebaCliente.dir/mainPruebaCliente.cpp.o: mainPruebaCliente.cpp
CMakeFiles/pruebaCliente.dir/mainPruebaCliente.cpp.o: CMakeFiles/pruebaCliente.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pruebaCliente.dir/mainPruebaCliente.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pruebaCliente.dir/mainPruebaCliente.cpp.o -MF CMakeFiles/pruebaCliente.dir/mainPruebaCliente.cpp.o.d -o CMakeFiles/pruebaCliente.dir/mainPruebaCliente.cpp.o -c /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/mainPruebaCliente.cpp

CMakeFiles/pruebaCliente.dir/mainPruebaCliente.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pruebaCliente.dir/mainPruebaCliente.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/mainPruebaCliente.cpp > CMakeFiles/pruebaCliente.dir/mainPruebaCliente.cpp.i

CMakeFiles/pruebaCliente.dir/mainPruebaCliente.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pruebaCliente.dir/mainPruebaCliente.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/mainPruebaCliente.cpp -o CMakeFiles/pruebaCliente.dir/mainPruebaCliente.cpp.s

CMakeFiles/pruebaCliente.dir/utils.cpp.o: CMakeFiles/pruebaCliente.dir/flags.make
CMakeFiles/pruebaCliente.dir/utils.cpp.o: utils.cpp
CMakeFiles/pruebaCliente.dir/utils.cpp.o: CMakeFiles/pruebaCliente.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pruebaCliente.dir/utils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pruebaCliente.dir/utils.cpp.o -MF CMakeFiles/pruebaCliente.dir/utils.cpp.o.d -o CMakeFiles/pruebaCliente.dir/utils.cpp.o -c /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/utils.cpp

CMakeFiles/pruebaCliente.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pruebaCliente.dir/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/utils.cpp > CMakeFiles/pruebaCliente.dir/utils.cpp.i

CMakeFiles/pruebaCliente.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pruebaCliente.dir/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/utils.cpp -o CMakeFiles/pruebaCliente.dir/utils.cpp.s

CMakeFiles/pruebaCliente.dir/fileManagerClient.cpp.o: CMakeFiles/pruebaCliente.dir/flags.make
CMakeFiles/pruebaCliente.dir/fileManagerClient.cpp.o: fileManagerClient.cpp
CMakeFiles/pruebaCliente.dir/fileManagerClient.cpp.o: CMakeFiles/pruebaCliente.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pruebaCliente.dir/fileManagerClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pruebaCliente.dir/fileManagerClient.cpp.o -MF CMakeFiles/pruebaCliente.dir/fileManagerClient.cpp.o.d -o CMakeFiles/pruebaCliente.dir/fileManagerClient.cpp.o -c /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/fileManagerClient.cpp

CMakeFiles/pruebaCliente.dir/fileManagerClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pruebaCliente.dir/fileManagerClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/fileManagerClient.cpp > CMakeFiles/pruebaCliente.dir/fileManagerClient.cpp.i

CMakeFiles/pruebaCliente.dir/fileManagerClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pruebaCliente.dir/fileManagerClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/fileManagerClient.cpp -o CMakeFiles/pruebaCliente.dir/fileManagerClient.cpp.s

CMakeFiles/pruebaCliente.dir/serialize.cpp.o: CMakeFiles/pruebaCliente.dir/flags.make
CMakeFiles/pruebaCliente.dir/serialize.cpp.o: serialize.cpp
CMakeFiles/pruebaCliente.dir/serialize.cpp.o: CMakeFiles/pruebaCliente.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pruebaCliente.dir/serialize.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pruebaCliente.dir/serialize.cpp.o -MF CMakeFiles/pruebaCliente.dir/serialize.cpp.o.d -o CMakeFiles/pruebaCliente.dir/serialize.cpp.o -c /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/serialize.cpp

CMakeFiles/pruebaCliente.dir/serialize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pruebaCliente.dir/serialize.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/serialize.cpp > CMakeFiles/pruebaCliente.dir/serialize.cpp.i

CMakeFiles/pruebaCliente.dir/serialize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pruebaCliente.dir/serialize.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/serialize.cpp -o CMakeFiles/pruebaCliente.dir/serialize.cpp.s

CMakeFiles/pruebaCliente.dir/filemanager.cpp.o: CMakeFiles/pruebaCliente.dir/flags.make
CMakeFiles/pruebaCliente.dir/filemanager.cpp.o: filemanager.cpp
CMakeFiles/pruebaCliente.dir/filemanager.cpp.o: CMakeFiles/pruebaCliente.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pruebaCliente.dir/filemanager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pruebaCliente.dir/filemanager.cpp.o -MF CMakeFiles/pruebaCliente.dir/filemanager.cpp.o.d -o CMakeFiles/pruebaCliente.dir/filemanager.cpp.o -c /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/filemanager.cpp

CMakeFiles/pruebaCliente.dir/filemanager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pruebaCliente.dir/filemanager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/filemanager.cpp > CMakeFiles/pruebaCliente.dir/filemanager.cpp.i

CMakeFiles/pruebaCliente.dir/filemanager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pruebaCliente.dir/filemanager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/filemanager.cpp -o CMakeFiles/pruebaCliente.dir/filemanager.cpp.s

# Object files for target pruebaCliente
pruebaCliente_OBJECTS = \
"CMakeFiles/pruebaCliente.dir/mainPruebaCliente.cpp.o" \
"CMakeFiles/pruebaCliente.dir/utils.cpp.o" \
"CMakeFiles/pruebaCliente.dir/fileManagerClient.cpp.o" \
"CMakeFiles/pruebaCliente.dir/serialize.cpp.o" \
"CMakeFiles/pruebaCliente.dir/filemanager.cpp.o"

# External object files for target pruebaCliente
pruebaCliente_EXTERNAL_OBJECTS =

pruebaCliente: CMakeFiles/pruebaCliente.dir/mainPruebaCliente.cpp.o
pruebaCliente: CMakeFiles/pruebaCliente.dir/utils.cpp.o
pruebaCliente: CMakeFiles/pruebaCliente.dir/fileManagerClient.cpp.o
pruebaCliente: CMakeFiles/pruebaCliente.dir/serialize.cpp.o
pruebaCliente: CMakeFiles/pruebaCliente.dir/filemanager.cpp.o
pruebaCliente: CMakeFiles/pruebaCliente.dir/build.make
pruebaCliente: CMakeFiles/pruebaCliente.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable pruebaCliente"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pruebaCliente.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pruebaCliente.dir/build: pruebaCliente
.PHONY : CMakeFiles/pruebaCliente.dir/build

CMakeFiles/pruebaCliente.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pruebaCliente.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pruebaCliente.dir/clean

CMakeFiles/pruebaCliente.dir/depend:
	cd /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager /home/javiortig/uni/sistemas-distribuidos/practica_1/Pr1/fileManager/CMakeFiles/pruebaCliente.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pruebaCliente.dir/depend

