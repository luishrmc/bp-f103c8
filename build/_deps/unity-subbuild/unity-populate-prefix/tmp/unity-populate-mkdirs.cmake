# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-src"
  "/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-build"
  "/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix"
  "/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/tmp"
  "/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/src/unity-populate-stamp"
  "/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/src"
  "/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/src/unity-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/src/unity-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/lumac/learning/stm/bp-f103c8/build/_deps/unity-subbuild/unity-populate-prefix/src/unity-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
