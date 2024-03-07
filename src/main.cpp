
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