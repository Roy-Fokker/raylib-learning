cmake_minimum_required(VERSION 3.28)

# project and language to be used
project(raylib5-learnings
	LANGUAGES CXX
	HOMEPAGE_URL "https://roy-fokker.github.io/raylib5-learnings/"
	DESCRIPTION "C++23 based Project to learn Raylib 5.0.")

# Enable scan for dependencies
set(CXX_SCAN_FOR_MODULES ON)
# disable C++ extensions
set(CMAKE_CXX_EXTENSIONS OFF)
# force C++ version to 23
set(CMAKE_CXX_STANDARD 23)
# standard is required
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# executable source folder
add_subdirectory(src)