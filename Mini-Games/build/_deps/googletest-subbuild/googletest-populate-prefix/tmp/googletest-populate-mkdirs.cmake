# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "N:/Code Repositories/Testing Adding Build System and Testing/Mini-Games/build/_deps/googletest-src"
  "N:/Code Repositories/Testing Adding Build System and Testing/Mini-Games/build/_deps/googletest-build"
  "N:/Code Repositories/Testing Adding Build System and Testing/Mini-Games/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "N:/Code Repositories/Testing Adding Build System and Testing/Mini-Games/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "N:/Code Repositories/Testing Adding Build System and Testing/Mini-Games/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "N:/Code Repositories/Testing Adding Build System and Testing/Mini-Games/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "N:/Code Repositories/Testing Adding Build System and Testing/Mini-Games/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "N:/Code Repositories/Testing Adding Build System and Testing/Mini-Games/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "N:/Code Repositories/Testing Adding Build System and Testing/Mini-Games/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
