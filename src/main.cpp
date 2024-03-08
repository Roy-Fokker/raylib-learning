
auto main() -> int
{
	constexpr auto screen_width  = 1280;
	constexpr auto screen_height = screen_width * 9 / 16;

	// Create the window
	raylib::InitWindow(screen_width, screen_height, "3D Camera");

	// Generate Random Columns
	constexpr auto max_columns = 20;

	auto column_heights   = std::array<float, max_columns>{};
	auto column_positions = std::array<Vector3, max_columns>{};
	auto column_colors    = std::array<Color, max_columns>{};

	for (auto &&[height, position, color] : std::views::zip(column_heights, column_positions, column_colors))
	{
		height   = static_cast<float>(GetRandomValue(1, 12));
		position = Vector3{ static_cast<float>(GetRandomValue(-15, 15)),   // x
			                height / 2.0f,                                 // y
			                static_cast<float>(GetRandomValue(-15, 15)) }; // z

		color = Color{ static_cast<unsigned char>(GetRandomValue(20, 255)), // r
			           static_cast<unsigned char>(GetRandomValue(10, 55)),  // g
			           30,                                                  // b
			           255 };                                               // a
	}

	DisableCursor(); // Hide Mouse inside window.

	// Camera setup
	auto camera_mode = CAMERA_FIRST_PERSON;
	auto camera      = raylib::Camera{
        Vector3{ 0.0f, 2.0f, 4.0f }, // Position
        Vector3{ 0.0f, 2.0f, 0.0f }, // Target
        Vector3{ 0.0f, 1.0f, 0.0f }, // Up
        60.0f,                       // field of view Y
        CAMERA_PERSPECTIVE           // projection type
	};

	SetTargetFPS(60);

	// Main Loop
	while (not WindowShouldClose())
	{
		auto key_pressed = GetKeyPressed();
		switch (key_pressed)
		{
		case KEY_ONE:
			camera_mode = CAMERA_FREE;
			break;

		case KEY_TWO:
			camera_mode = CAMERA_FIRST_PERSON;
			break;

		case KEY_THREE:
			camera_mode = CAMERA_THIRD_PERSON;
			break;

		case KEY_FOUR:
			camera_mode = CAMERA_ORBITAL;
			break;

		default:
			break;
		}

		// Call simple camera update function
		UpdateCamera(&camera, camera_mode);

		// Draw
		BeginDrawing();
		{
			ClearBackground(RAYWHITE);

			BeginMode3D(camera);
			{
				DrawPlane(Vector3{ 0.f, 0.f, 0.f }, Vector2{ 32.f, 32.f }, LIGHTGRAY); // Ground Plane
				DrawCube(Vector3{ -16.f, 2.5f, 0.f }, 1.f, 5.f, 32.f, BLUE);           // Blue Wall
				DrawCube(Vector3{ 16.f, 2.5f, 0.f }, 1.f, 5.f, 32.f, LIME);            // Green Wall
				DrawCube(Vector3{ 0.f, 2.5f, 16.f }, 32.f, 5.f, 1.f, GOLD);            // Yellow Wall

				// Draw columns
				for (auto &&[height, position, color] : std::views::zip(column_heights, column_positions, column_colors))
				{
					DrawCube(position, 2.f, height, 2.f, color);
					DrawCubeWires(position, 2.f, height, 2.f, color);
				}
			}
			EndMode3D();
		}
		EndDrawing();
	}

	CloseWindow();

	return 0;
}