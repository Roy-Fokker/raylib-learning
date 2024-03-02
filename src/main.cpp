#include <fmt/core.h>
#include <print>
#include <filesystem>

auto main() -> int
{
	std::println("Running in: {}", std::filesystem::current_path().generic_string());
	fmt::println("Hello World");
}