# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/carcar/BoostLearn2018/CommonModule

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/carcar/BoostLearn2018/CommonModule/build

# Include any dependencies generated for this target.
include src/CMakeFiles/test_depend.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/test_depend.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/test_depend.dir/flags.make

src/CMakeFiles/test_depend.dir/any.cpp.o: src/CMakeFiles/test_depend.dir/flags.make
src/CMakeFiles/test_depend.dir/any.cpp.o: ../src/any.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/carcar/BoostLearn2018/CommonModule/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/test_depend.dir/any.cpp.o"
	cd /root/carcar/BoostLearn2018/CommonModule/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_depend.dir/any.cpp.o -c /root/carcar/BoostLearn2018/CommonModule/src/any.cpp

src/CMakeFiles/test_depend.dir/any.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_depend.dir/any.cpp.i"
	cd /root/carcar/BoostLearn2018/CommonModule/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/carcar/BoostLearn2018/CommonModule/src/any.cpp > CMakeFiles/test_depend.dir/any.cpp.i

src/CMakeFiles/test_depend.dir/any.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_depend.dir/any.cpp.s"
	cd /root/carcar/BoostLearn2018/CommonModule/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/carcar/BoostLearn2018/CommonModule/src/any.cpp -o CMakeFiles/test_depend.dir/any.cpp.s

src/CMakeFiles/test_depend.dir/any.cpp.o.requires:
.PHONY : src/CMakeFiles/test_depend.dir/any.cpp.o.requires

src/CMakeFiles/test_depend.dir/any.cpp.o.provides: src/CMakeFiles/test_depend.dir/any.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/test_depend.dir/build.make src/CMakeFiles/test_depend.dir/any.cpp.o.provides.build
.PHONY : src/CMakeFiles/test_depend.dir/any.cpp.o.provides

src/CMakeFiles/test_depend.dir/any.cpp.o.provides.build: src/CMakeFiles/test_depend.dir/any.cpp.o

src/CMakeFiles/test_depend.dir/array.cpp.o: src/CMakeFiles/test_depend.dir/flags.make
src/CMakeFiles/test_depend.dir/array.cpp.o: ../src/array.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/carcar/BoostLearn2018/CommonModule/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/test_depend.dir/array.cpp.o"
	cd /root/carcar/BoostLearn2018/CommonModule/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_depend.dir/array.cpp.o -c /root/carcar/BoostLearn2018/CommonModule/src/array.cpp

src/CMakeFiles/test_depend.dir/array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_depend.dir/array.cpp.i"
	cd /root/carcar/BoostLearn2018/CommonModule/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/carcar/BoostLearn2018/CommonModule/src/array.cpp > CMakeFiles/test_depend.dir/array.cpp.i

src/CMakeFiles/test_depend.dir/array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_depend.dir/array.cpp.s"
	cd /root/carcar/BoostLearn2018/CommonModule/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/carcar/BoostLearn2018/CommonModule/src/array.cpp -o CMakeFiles/test_depend.dir/array.cpp.s

src/CMakeFiles/test_depend.dir/array.cpp.o.requires:
.PHONY : src/CMakeFiles/test_depend.dir/array.cpp.o.requires

src/CMakeFiles/test_depend.dir/array.cpp.o.provides: src/CMakeFiles/test_depend.dir/array.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/test_depend.dir/build.make src/CMakeFiles/test_depend.dir/array.cpp.o.provides.build
.PHONY : src/CMakeFiles/test_depend.dir/array.cpp.o.provides

src/CMakeFiles/test_depend.dir/array.cpp.o.provides.build: src/CMakeFiles/test_depend.dir/array.cpp.o

src/CMakeFiles/test_depend.dir/lexical.cpp.o: src/CMakeFiles/test_depend.dir/flags.make
src/CMakeFiles/test_depend.dir/lexical.cpp.o: ../src/lexical.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/carcar/BoostLearn2018/CommonModule/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/test_depend.dir/lexical.cpp.o"
	cd /root/carcar/BoostLearn2018/CommonModule/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_depend.dir/lexical.cpp.o -c /root/carcar/BoostLearn2018/CommonModule/src/lexical.cpp

src/CMakeFiles/test_depend.dir/lexical.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_depend.dir/lexical.cpp.i"
	cd /root/carcar/BoostLearn2018/CommonModule/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/carcar/BoostLearn2018/CommonModule/src/lexical.cpp > CMakeFiles/test_depend.dir/lexical.cpp.i

src/CMakeFiles/test_depend.dir/lexical.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_depend.dir/lexical.cpp.s"
	cd /root/carcar/BoostLearn2018/CommonModule/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/carcar/BoostLearn2018/CommonModule/src/lexical.cpp -o CMakeFiles/test_depend.dir/lexical.cpp.s

src/CMakeFiles/test_depend.dir/lexical.cpp.o.requires:
.PHONY : src/CMakeFiles/test_depend.dir/lexical.cpp.o.requires

src/CMakeFiles/test_depend.dir/lexical.cpp.o.provides: src/CMakeFiles/test_depend.dir/lexical.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/test_depend.dir/build.make src/CMakeFiles/test_depend.dir/lexical.cpp.o.provides.build
.PHONY : src/CMakeFiles/test_depend.dir/lexical.cpp.o.provides

src/CMakeFiles/test_depend.dir/lexical.cpp.o.provides.build: src/CMakeFiles/test_depend.dir/lexical.cpp.o

src/CMakeFiles/test_depend.dir/tokenizer.cpp.o: src/CMakeFiles/test_depend.dir/flags.make
src/CMakeFiles/test_depend.dir/tokenizer.cpp.o: ../src/tokenizer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/carcar/BoostLearn2018/CommonModule/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/test_depend.dir/tokenizer.cpp.o"
	cd /root/carcar/BoostLearn2018/CommonModule/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_depend.dir/tokenizer.cpp.o -c /root/carcar/BoostLearn2018/CommonModule/src/tokenizer.cpp

src/CMakeFiles/test_depend.dir/tokenizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_depend.dir/tokenizer.cpp.i"
	cd /root/carcar/BoostLearn2018/CommonModule/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/carcar/BoostLearn2018/CommonModule/src/tokenizer.cpp > CMakeFiles/test_depend.dir/tokenizer.cpp.i

src/CMakeFiles/test_depend.dir/tokenizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_depend.dir/tokenizer.cpp.s"
	cd /root/carcar/BoostLearn2018/CommonModule/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/carcar/BoostLearn2018/CommonModule/src/tokenizer.cpp -o CMakeFiles/test_depend.dir/tokenizer.cpp.s

src/CMakeFiles/test_depend.dir/tokenizer.cpp.o.requires:
.PHONY : src/CMakeFiles/test_depend.dir/tokenizer.cpp.o.requires

src/CMakeFiles/test_depend.dir/tokenizer.cpp.o.provides: src/CMakeFiles/test_depend.dir/tokenizer.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/test_depend.dir/build.make src/CMakeFiles/test_depend.dir/tokenizer.cpp.o.provides.build
.PHONY : src/CMakeFiles/test_depend.dir/tokenizer.cpp.o.provides

src/CMakeFiles/test_depend.dir/tokenizer.cpp.o.provides.build: src/CMakeFiles/test_depend.dir/tokenizer.cpp.o

# Object files for target test_depend
test_depend_OBJECTS = \
"CMakeFiles/test_depend.dir/any.cpp.o" \
"CMakeFiles/test_depend.dir/array.cpp.o" \
"CMakeFiles/test_depend.dir/lexical.cpp.o" \
"CMakeFiles/test_depend.dir/tokenizer.cpp.o"

# External object files for target test_depend
test_depend_EXTERNAL_OBJECTS =

src/libtest_depend.a: src/CMakeFiles/test_depend.dir/any.cpp.o
src/libtest_depend.a: src/CMakeFiles/test_depend.dir/array.cpp.o
src/libtest_depend.a: src/CMakeFiles/test_depend.dir/lexical.cpp.o
src/libtest_depend.a: src/CMakeFiles/test_depend.dir/tokenizer.cpp.o
src/libtest_depend.a: src/CMakeFiles/test_depend.dir/build.make
src/libtest_depend.a: src/CMakeFiles/test_depend.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libtest_depend.a"
	cd /root/carcar/BoostLearn2018/CommonModule/build/src && $(CMAKE_COMMAND) -P CMakeFiles/test_depend.dir/cmake_clean_target.cmake
	cd /root/carcar/BoostLearn2018/CommonModule/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_depend.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/test_depend.dir/build: src/libtest_depend.a
.PHONY : src/CMakeFiles/test_depend.dir/build

src/CMakeFiles/test_depend.dir/requires: src/CMakeFiles/test_depend.dir/any.cpp.o.requires
src/CMakeFiles/test_depend.dir/requires: src/CMakeFiles/test_depend.dir/array.cpp.o.requires
src/CMakeFiles/test_depend.dir/requires: src/CMakeFiles/test_depend.dir/lexical.cpp.o.requires
src/CMakeFiles/test_depend.dir/requires: src/CMakeFiles/test_depend.dir/tokenizer.cpp.o.requires
.PHONY : src/CMakeFiles/test_depend.dir/requires

src/CMakeFiles/test_depend.dir/clean:
	cd /root/carcar/BoostLearn2018/CommonModule/build/src && $(CMAKE_COMMAND) -P CMakeFiles/test_depend.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/test_depend.dir/clean

src/CMakeFiles/test_depend.dir/depend:
	cd /root/carcar/BoostLearn2018/CommonModule/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/carcar/BoostLearn2018/CommonModule /root/carcar/BoostLearn2018/CommonModule/src /root/carcar/BoostLearn2018/CommonModule/build /root/carcar/BoostLearn2018/CommonModule/build/src /root/carcar/BoostLearn2018/CommonModule/build/src/CMakeFiles/test_depend.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/test_depend.dir/depend

