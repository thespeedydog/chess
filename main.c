#include <stdio.h>
#include "include/include.h"


void Setup(){

}

int main () {
	printf("Hello, World!");

	InitWindow(400, 400, "My Game");

	Setup();

	while (!WindowShouldClose()){

		BeginDrawing();

		ClearBackground(WHITE);

		EndDrawing();

	}

	CloseWindow();

	return 0;
}
