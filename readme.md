# Learning Raylib5 using C++25

## Uses
- vcpkg for package management.
- ninja for build engine.
- CMake with CMakePresets for build generator. Hopefully, using "Modern CMake" practices.
- C++ modules enabled.
- clang-tidy and clang-format

## Dependencies
- [Raylib 5.0](https://github.com/raysan5/raylib)
- [raylib-cpp](https://github.com/RobLoach/raylib-cpp) C++ wrapper for Raylib

## to be figured out
- linux configuration
- C++ STD modules

## Sub-project
- Initial Setup
  - simple clean project, creates window using Raylib 5, via Raylib_Cpp.
  - Raylib_Cpp is consumed via [Find Package/FetchContent](cmake/FindRaylib_Cpp.cmake).
  - Raylib and Raylib_Cpp are part of precompiled header for executable.
  - C++23 STD headers are used via precompiled headers via [std23](std23/CMakeLists.txt) library.
- 