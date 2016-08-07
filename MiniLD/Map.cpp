#include "Map.h"

int maxPoints = 0;

Map::Map()
{
	char tmp[14][36] = {
		{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
		{ '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#' },
		{ '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
		{ '#', '#', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#' },
		{ '#', '#', '.', '.', '#', '#', '.', '.', '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#', '#' },
		{ '#', '#', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#' },
		{ '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '.', '.', '#', '#' },
		{ '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '#', '#' },
		{ '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '#', '#', '.', '.', '#', '#', '#', '#', '#', '#' },
		{ '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '#', '#' },
		{ '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '#', '#' },
		{ '#', '#', '.', '.', '#', '#', '.', '.', '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '#', '#' },
		{ '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#' },
		{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
		
	};

	for (int y = 0; y < mapSizeY; y++) {
		for (int x = 0; x < mapSizeX; x++) {
			if (tmp[y][x] == '.') {
				maxPoints += 1;
			}
			map[x][y] = tmp[y][x];
		}
	}

	maxPoints /= 2;
}


Map::~Map()
{
}

void Map::draw(int lives) {
	int points = 0;

	std::cout << "Lives: " << lives << std::endl << std::endl;

	for (int y = 0; y < mapSizeY; y++) {
		for (int x = 0; x < mapSizeX; x++) {
			if (map[x][y] == '@') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			}
			else if (map[x][y] == '.') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				points += 1;
			}
			else if (map[x][y] == 'G') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			std::cout << map[x][y];
		}

		if (y == 0) {
			std::cout << "          Press 'W' to go up";
		}
		else if (y == 2) {
			std::cout << "          Press 'A' to go left";
		}
		else if (y == 4) {
			std::cout << "          Press 'S' to go down";
		}
		else if (y == 6) {
			std::cout << "          Press 'D' to go right";
		}
		else if (y == 12) {
			std::cout << "          Press 'Q' to quit";
		}

		std::cout << std::endl;
	}

	if (points == 0) {
		std::cout << std::endl << std::endl << "YOU'VE WIN !!!" << std::endl << std::endl << "Press 'R' to restart ...";
	}
	else if (lives == 0) {
		std::cout << std::endl << std::endl << "YOU'VE LOST !!!" << std::endl << std::endl << "Press 'R' to restart ...";
	}
	else {
		std::cout << std::endl << std::endl << "Pick up all the yellow points !" << std::endl << "Don't get eaten by the ghosts !";
	}

}
