#include <print>

// Supress some warnings in raylib-cpp and how it wraps raylib
// there is probably a better way to do this
#pragma warning(push)
#pragma warning(disable : 4018) // '>=': signed/unsigned mismatch
#pragma warning(disable : 4458) // declaration of {class_method} hides {parent_class} class member
#pragma warning(disable : 4505) // unreferenced function with internal linkage has been removed
#include <raylib-cpp.hpp>
#pragma warning(pop)

auto main() -> int
{
	// Initialization
	//--------------------------------------------------------------------------------------
	constexpr auto screenWidth  = 800;
	constexpr auto screenHeight = 450;
	constexpr auto targetFPS    = 60;

	auto textColor = raylib::Color::LightGray();
	auto window    = raylib::Window(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(targetFPS);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!window.ShouldClose())
	{ // Detect window close button or ESC key
		// Update
		//----------------------------------------------------------------------------------
		// Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		{
			window.ClearBackground(RAYWHITE);
			textColor.DrawText("Congrats! You created your first window!", 190, 200, 20);
		}
		EndDrawing();
		//----------------------------------------------------------------------------------
	}
	return 0;
}