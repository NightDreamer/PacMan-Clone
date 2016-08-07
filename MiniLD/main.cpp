#include "main.h"
#include "Game.h"

bool running = true;

void clear();

int main() {
	COORD dim;
	dim.X = 800;
	dim.Y = 600;
	SetConsoleDisplayMode(GetConsoleWindow(), CONSOLE_WINDOWED_MODE, &dim);
	SetConsoleTitle(L"PacMan Clone - MiniLD #45");

	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = true;
	cci.dwSize = 100;
	SetConsoleCursorInfo(GetConsoleWindow(), &cci);

	clear();

	Game* game = new Game();
	game->map->draw(game->player->lives);

	while (running) {
		LockWindowUpdate(GetConsoleWindow());

		clear();
		if (!game->update()) {
			running = false;
		}

		LockWindowUpdate(NULL);

		Sleep(5);
	}

	delete game;
	return 0;
}

void clear() {
	system("cls");
}