#include <stdio.h>
#include "include/raylib.h"

int main () {
	printf("Hello, World!");
	
	InitWindow(400, 400, "My Game");

	while (!WindowShouldClose()){

		BeginDrawing();

		ClearBackground(WHITE);

		EndDrawing();

	}

	CloseWindow();

	return 0;
}
