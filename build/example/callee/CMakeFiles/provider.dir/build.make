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
CMAKE_SOURCE_DIR = /home/parallels/video/rpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parallels/video/rpc/build

# Include any dependencies generated for this target.
include example/callee/CMakeFiles/provider.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include example/callee/CMakeFiles/provider.dir/compiler_depend.make

# Include the progress variables for this target.
include example/callee/CMakeFiles/provider.dir/progress.make

# Include the compile flags for this target's objects.
include example/callee/CMakeFiles/provider.dir/flags.make

example/callee/CMakeFiles/provider.dir/main.cc.o: example/callee/CMakeFiles/provider.dir/flags.make
example/callee/CMakeFiles/provider.dir/main.cc.o: ../example/callee/main.cc
example/callee/CMakeFiles/provider.dir/main.cc.o: example/callee/CMakeFiles/provider.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object example/callee/CMakeFiles/provider.dir/main.cc.o"
	cd /home/parallels/video/rpc/build/example/callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT example/callee/CMakeFiles/provider.dir/main.cc.o -MF CMakeFiles/provider.dir/main.cc.o.d -o CMakeFiles/provider.dir/main.cc.o -c /home/parallels/video/rpc/example/callee/main.cc

example/callee/CMakeFiles/provider.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/provider.dir/main.cc.i"
	cd /home/parallels/video/rpc/build/example/callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/rpc/example/callee/main.cc > CMakeFiles/provider.dir/main.cc.i

example/callee/CMakeFiles/provider.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/provider.dir/main.cc.s"
	cd /home/parallels/video/rpc/build/example/callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/rpc/example/callee/main.cc -o CMakeFiles/provider.dir/main.cc.s

example/callee/CMakeFiles/provider.dir/__/User.pb.cc.o: example/callee/CMakeFiles/provider.dir/flags.make
example/callee/CMakeFiles/provider.dir/__/User.pb.cc.o: ../example/User.pb.cc
example/callee/CMakeFiles/provider.dir/__/User.pb.cc.o: example/callee/CMakeFiles/provider.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object example/callee/CMakeFiles/provider.dir/__/User.pb.cc.o"
	cd /home/parallels/video/rpc/build/example/callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT example/callee/CMakeFiles/provider.dir/__/User.pb.cc.o -MF CMakeFiles/provider.dir/__/User.pb.cc.o.d -o CMakeFiles/provider.dir/__/User.pb.cc.o -c /home/parallels/video/rpc/example/User.pb.cc

example/callee/CMakeFiles/provider.dir/__/User.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/provider.dir/__/User.pb.cc.i"
	cd /home/parallels/video/rpc/build/example/callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/rpc/example/User.pb.cc > CMakeFiles/provider.dir/__/User.pb.cc.i

example/callee/CMakeFiles/provider.dir/__/User.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/provider.dir/__/User.pb.cc.s"
	cd /home/parallels/video/rpc/build/example/callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/rpc/example/User.pb.cc -o CMakeFiles/provider.dir/__/User.pb.cc.s

example/callee/CMakeFiles/provider.dir/__/Friend.pb.cc.o: example/callee/CMakeFiles/provider.dir/flags.make
example/callee/CMakeFiles/provider.dir/__/Friend.pb.cc.o: ../example/Friend.pb.cc
example/callee/CMakeFiles/provider.dir/__/Friend.pb.cc.o: example/callee/CMakeFiles/provider.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object example/callee/CMakeFiles/provider.dir/__/Friend.pb.cc.o"
	cd /home/parallels/video/rpc/build/example/callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT example/callee/CMakeFiles/provider.dir/__/Friend.pb.cc.o -MF CMakeFiles/provider.dir/__/Friend.pb.cc.o.d -o CMakeFiles/provider.dir/__/Friend.pb.cc.o -c /home/parallels/video/rpc/example/Friend.pb.cc

example/callee/CMakeFiles/provider.dir/__/Friend.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/provider.dir/__/Friend.pb.cc.i"
	cd /home/parallels/video/rpc/build/example/callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/rpc/example/Friend.pb.cc > CMakeFiles/provider.dir/__/Friend.pb.cc.i

example/callee/CMakeFiles/provider.dir/__/Friend.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/provider.dir/__/Friend.pb.cc.s"
	cd /home/parallels/video/rpc/build/example/callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/rpc/example/Friend.pb.cc -o CMakeFiles/provider.dir/__/Friend.pb.cc.s

example/callee/CMakeFiles/provider.dir/FriendService.cc.o: example/callee/CMakeFiles/provider.dir/flags.make
example/callee/CMakeFiles/provider.dir/FriendService.cc.o: ../example/callee/FriendService.cc
example/callee/CMakeFiles/provider.dir/FriendService.cc.o: example/callee/CMakeFiles/provider.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object example/callee/CMakeFiles/provider.dir/FriendService.cc.o"
	cd /home/parallels/video/rpc/build/example/callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT example/callee/CMakeFiles/provider.dir/FriendService.cc.o -MF CMakeFiles/provider.dir/FriendService.cc.o.d -o CMakeFiles/provider.dir/FriendService.cc.o -c /home/parallels/video/rpc/example/callee/FriendService.cc

example/callee/CMakeFiles/provider.dir/FriendService.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/provider.dir/FriendService.cc.i"
	cd /home/parallels/video/rpc/build/example/callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/rpc/example/callee/FriendService.cc > CMakeFiles/provider.dir/FriendService.cc.i

example/callee/CMakeFiles/provider.dir/FriendService.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/provider.dir/FriendService.cc.s"
	cd /home/parallels/video/rpc/build/example/callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/rpc/example/callee/FriendService.cc -o CMakeFiles/provider.dir/FriendService.cc.s

example/callee/CMakeFiles/provider.dir/UserService.cc.o: example/callee/CMakeFiles/provider.dir/flags.make
example/callee/CMakeFiles/provider.dir/UserService.cc.o: ../example/callee/UserService.cc
example/callee/CMakeFiles/provider.dir/UserService.cc.o: example/callee/CMakeFiles/provider.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object example/callee/CMakeFiles/provider.dir/UserService.cc.o"
	cd /home/parallels/video/rpc/build/example/callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT example/callee/CMakeFiles/provider.dir/UserService.cc.o -MF CMakeFiles/provider.dir/UserService.cc.o.d -o CMakeFiles/provider.dir/UserService.cc.o -c /home/parallels/video/rpc/example/callee/UserService.cc

example/callee/CMakeFiles/provider.dir/UserService.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/provider.dir/UserService.cc.i"
	cd /home/parallels/video/rpc/build/example/callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/rpc/example/callee/UserService.cc > CMakeFiles/provider.dir/UserService.cc.i

example/callee/CMakeFiles/provider.dir/UserService.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/provider.dir/UserService.cc.s"
	cd /home/parallels/video/rpc/build/example/callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/rpc/example/callee/UserService.cc -o CMakeFiles/provider.dir/UserService.cc.s

# Object files for target provider
provider_OBJECTS = \
"CMakeFiles/provider.dir/main.cc.o" \
"CMakeFiles/provider.dir/__/User.pb.cc.o" \
"CMakeFiles/provider.dir/__/Friend.pb.cc.o" \
"CMakeFiles/provider.dir/FriendService.cc.o" \
"CMakeFiles/provider.dir/UserService.cc.o"

# External object files for target provider
provider_EXTERNAL_OBJECTS =

../bin/provider: example/callee/CMakeFiles/provider.dir/main.cc.o
../bin/provider: example/callee/CMakeFiles/provider.dir/__/User.pb.cc.o
../bin/provider: example/callee/CMakeFiles/provider.dir/__/Friend.pb.cc.o
../bin/provider: example/callee/CMakeFiles/provider.dir/FriendService.cc.o
../bin/provider: example/callee/CMakeFiles/provider.dir/UserService.cc.o
../bin/provider: example/callee/CMakeFiles/provider.dir/build.make
../bin/provider: ../lib/librpc.a
../bin/provider: example/callee/CMakeFiles/provider.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/parallels/video/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../../../bin/provider"
	cd /home/parallels/video/rpc/build/example/callee && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/provider.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/callee/CMakeFiles/provider.dir/build: ../bin/provider
.PHONY : example/callee/CMakeFiles/provider.dir/build

example/callee/CMakeFiles/provider.dir/clean:
	cd /home/parallels/video/rpc/build/example/callee && $(CMAKE_COMMAND) -P CMakeFiles/provider.dir/cmake_clean.cmake
.PHONY : example/callee/CMakeFiles/provider.dir/clean

example/callee/CMakeFiles/provider.dir/depend:
	cd /home/parallels/video/rpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/video/rpc /home/parallels/video/rpc/example/callee /home/parallels/video/rpc/build /home/parallels/video/rpc/build/example/callee /home/parallels/video/rpc/build/example/callee/CMakeFiles/provider.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : example/callee/CMakeFiles/provider.dir/depend

