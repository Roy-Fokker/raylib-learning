#pragma once

#include <raylib.h>

// Supress some warnings in raylib-cpp and how it wraps raylib
// there is probably a better way to do this
#pragma warning(push)
#pragma warning(disable : 4018) // '>=': signed/unsigned mismatch
#pragma warning(disable : 4458) // declaration of {class_method} hides {parent_class} class member
#pragma warning(disable : 4505) // unreferenced function with internal linkage has been removed
#include <raylib-cpp.hpp>
#pragma warning(pop)
