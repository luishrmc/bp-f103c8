# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild

# Utility rule file for unity-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/unity-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/unity-populate.dir/progress.make

CMakeFiles/unity-populate: CMakeFiles/unity-populate-complete

CMakeFiles/unity-populate-complete: unity-populate-prefix/src/unity-populate-stamp/unity-populate-install
CMakeFiles/unity-populate-complete: unity-populate-prefix/src/unity-populate-stamp/unity-populate-mkdir
CMakeFiles/unity-populate-complete: unity-populate-prefix/src/unity-populate-stamp/unity-populate-download
CMakeFiles/unity-populate-complete: unity-populate-prefix/src/unity-populate-stamp/unity-populate-update
CMakeFiles/unity-populate-complete: unity-populate-prefix/src/unity-populate-stamp/unity-populate-patch
CMakeFiles/unity-populate-complete: unity-populate-prefix/src/unity-populate-stamp/unity-populate-configure
CMakeFiles/unity-populate-complete: unity-populate-prefix/src/unity-populate-stamp/unity-populate-build
CMakeFiles/unity-populate-complete: unity-populate-prefix/src/unity-populate-stamp/unity-populate-install
CMakeFiles/unity-populate-complete: unity-populate-prefix/src/unity-populate-stamp/unity-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'unity-populate'"
	/usr/local/bin/cmake -E make_directory /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/CMakeFiles
	/usr/local/bin/cmake -E touch /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/CMakeFiles/unity-populate-complete
	/usr/local/bin/cmake -E touch /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/src/unity-populate-stamp/unity-populate-done

unity-populate-prefix/src/unity-populate-stamp/unity-populate-update:
.PHONY : unity-populate-prefix/src/unity-populate-stamp/unity-populate-update

unity-populate-prefix/src/unity-populate-stamp/unity-populate-build: unity-populate-prefix/src/unity-populate-stamp/unity-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'unity-populate'"
	cd /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-build && /usr/local/bin/cmake -E echo_append
	cd /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-build && /usr/local/bin/cmake -E touch /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/src/unity-populate-stamp/unity-populate-build

unity-populate-prefix/src/unity-populate-stamp/unity-populate-configure: unity-populate-prefix/tmp/unity-populate-cfgcmd.txt
unity-populate-prefix/src/unity-populate-stamp/unity-populate-configure: unity-populate-prefix/src/unity-populate-stamp/unity-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'unity-populate'"
	cd /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-build && /usr/local/bin/cmake -E echo_append
	cd /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-build && /usr/local/bin/cmake -E touch /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/src/unity-populate-stamp/unity-populate-configure

unity-populate-prefix/src/unity-populate-stamp/unity-populate-download: unity-populate-prefix/src/unity-populate-stamp/unity-populate-gitinfo.txt
unity-populate-prefix/src/unity-populate-stamp/unity-populate-download: unity-populate-prefix/src/unity-populate-stamp/unity-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'unity-populate'"
	cd /home/lumac/learning/stm/bp-f103c8/build/_deps && /usr/local/bin/cmake -P /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/tmp/unity-populate-gitclone.cmake
	cd /home/lumac/learning/stm/bp-f103c8/build/_deps && /usr/local/bin/cmake -E touch /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/src/unity-populate-stamp/unity-populate-download

unity-populate-prefix/src/unity-populate-stamp/unity-populate-install: unity-populate-prefix/src/unity-populate-stamp/unity-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'unity-populate'"
	cd /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-build && /usr/local/bin/cmake -E echo_append
	cd /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-build && /usr/local/bin/cmake -E touch /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/src/unity-populate-stamp/unity-populate-install

unity-populate-prefix/src/unity-populate-stamp/unity-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'unity-populate'"
	/usr/local/bin/cmake -Dcfgdir= -P /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/tmp/unity-populate-mkdirs.cmake
	/usr/local/bin/cmake -E touch /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/src/unity-populate-stamp/unity-populate-mkdir

unity-populate-prefix/src/unity-populate-stamp/unity-populate-patch: unity-populate-prefix/src/unity-populate-stamp/unity-populate-patch-info.txt
unity-populate-prefix/src/unity-populate-stamp/unity-populate-patch: unity-populate-prefix/src/unity-populate-stamp/unity-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'unity-populate'"
	/usr/local/bin/cmake -E echo_append
	/usr/local/bin/cmake -E touch /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/src/unity-populate-stamp/unity-populate-patch

unity-populate-prefix/src/unity-populate-stamp/unity-populate-update:
.PHONY : unity-populate-prefix/src/unity-populate-stamp/unity-populate-update

unity-populate-prefix/src/unity-populate-stamp/unity-populate-test: unity-populate-prefix/src/unity-populate-stamp/unity-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'unity-populate'"
	cd /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-build && /usr/local/bin/cmake -E echo_append
	cd /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-build && /usr/local/bin/cmake -E touch /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/src/unity-populate-stamp/unity-populate-test

unity-populate-prefix/src/unity-populate-stamp/unity-populate-update: unity-populate-prefix/tmp/unity-populate-gitupdate.cmake
unity-populate-prefix/src/unity-populate-stamp/unity-populate-update: unity-populate-prefix/src/unity-populate-stamp/unity-populate-update-info.txt
unity-populate-prefix/src/unity-populate-stamp/unity-populate-update: unity-populate-prefix/src/unity-populate-stamp/unity-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'unity-populate'"
	cd /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-src && /usr/local/bin/cmake -Dcan_fetch=YES -P /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/tmp/unity-populate-gitupdate.cmake

unity-populate: CMakeFiles/unity-populate
unity-populate: CMakeFiles/unity-populate-complete
unity-populate: unity-populate-prefix/src/unity-populate-stamp/unity-populate-build
unity-populate: unity-populate-prefix/src/unity-populate-stamp/unity-populate-configure
unity-populate: unity-populate-prefix/src/unity-populate-stamp/unity-populate-download
unity-populate: unity-populate-prefix/src/unity-populate-stamp/unity-populate-install
unity-populate: unity-populate-prefix/src/unity-populate-stamp/unity-populate-mkdir
unity-populate: unity-populate-prefix/src/unity-populate-stamp/unity-populate-patch
unity-populate: unity-populate-prefix/src/unity-populate-stamp/unity-populate-test
unity-populate: unity-populate-prefix/src/unity-populate-stamp/unity-populate-update
unity-populate: CMakeFiles/unity-populate.dir/build.make
.PHONY : unity-populate

# Rule to build all files generated by this target.
CMakeFiles/unity-populate.dir/build: unity-populate
.PHONY : CMakeFiles/unity-populate.dir/build

CMakeFiles/unity-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unity-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unity-populate.dir/clean

CMakeFiles/unity-populate.dir/depend:
	cd /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild /home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/CMakeFiles/unity-populate.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/unity-populate.dir/depend

