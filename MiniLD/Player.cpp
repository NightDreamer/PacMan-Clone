#include "Player.h"

Player::Player()
{
}

void Player::init() {
	restart = false;
	died = false;
	lives = 3;
	pos.X = 16;
	pos.Y = 6;
	map->map[pos.X][pos.Y] = '@';
	map->map[pos.X + 1][pos.Y] = '@';
}


Player::~Player()
{
}

bool Player::update() {
	char input = _getch();

	switch (input) {
	case 'r':
		restart = true;
		break;
	case 'q':
		return false;
		break;
	case 'w':
		if (lives > 0) {
			if ((map->map[pos.X][pos.Y - 1] != '#' && map->map[pos.X + 1][pos.Y - 1] != '#') && (map->map[pos.X][pos.Y - 1] != 'G' && map->map[pos.X + 1][pos.Y - 1] != 'G')) {
				map->map[pos.X + 1][pos.Y] = ' ';
				map->map[pos.X][pos.Y] = ' ';
				pos.Y -= 1;
			}
		}
		break;
	case 'a':
		if (lives > 0) {
			if (map->map[pos.X - 2][pos.Y] != '#' && map->map[pos.X - 2][pos.Y] != 'G') {
				map->map[pos.X + 1][pos.Y] = ' ';
				map->map[pos.X][pos.Y] = ' ';
				pos.X -= 2;
			}
		}
		break;
	case 's':
		if (lives > 0) {
			if ((map->map[pos.X][pos.Y + 1] != '#' && map->map[pos.X + 1][pos.Y + 1] != '#') && (map->map[pos.X][pos.Y + 1] != 'G' && map->map[pos.X + 1][pos.Y + 1] != 'G')) {
				map->map[pos.X + 1][pos.Y] = ' ';
				map->map[pos.X][pos.Y] = ' ';
				pos.Y += 1;
			}
		}
		break;
	case 'd':
		if (lives > 0) {
			if (map->map[pos.X + 3][pos.Y] != '#' && map->map[pos.X + 3][pos.Y] != 'G') {
				map->map[pos.X + 1][pos.Y] = ' ';
				map->map[pos.X][pos.Y] = ' ';
				pos.X += 2;
			}
		}
		break;
	default:
		break;
	}

	map->map[pos.X][pos.Y] = '@';
	map->map[pos.X+1][pos.Y] = '@';

	return true;
}
