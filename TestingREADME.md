/* TODO: Update with how to create tests, etc */

A small explanation/ reminder on running the tests. Based on GoogleTest

## Running Tests

### in a shell terminal
cd <repo containing CMakeLists.txt>

### set up the build directory
cmake -S . -B build

### build tests
cmake --build build

### enter directory, run the tests, leave directory
pushd build/ && ctest && popd