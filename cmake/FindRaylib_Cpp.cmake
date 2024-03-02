# Check that project is already consuming raylib
find_package(raylib CONFIG REQUIRED)

# if not consuming raylib error out
if (NOT raylib_FOUND)
	message(FATAL_ERROR "[Error]: Could not find raylib.")
endif()

# load fetchcontent cmake
include(FetchContent)

# get appropriate version of raylib-cpp from github.
set(RAYLIB_CPP_VERSION v5.0.1)  # git commit hash: f865785fee2cb18da6ad6a9012a2993a73f2a2b1
FetchContent_Declare(
	raylib_cpp
	GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
	GIT_TAG ${RAYLIB_CPP_VERSION}
	FIND_PACKAGE_ARGS NAMES raylib_cpp # tell cmake to make it available via find_package
)
# make it available to project
FetchContent_MakeAvailable(raylib_cpp)

message("\n"
	"The package raylib_cpp ${RAYLIB_CPP_VERSION} provides CMake targets: \n\n"
	"	find_package(raylib_cpp)\n"
	"	target_link_libraries(main PRIVATE raylib_cpp)\n"
)