#include "Enemy.h"

Enemy::Enemy()
{
	
}

void Enemy::init() {
	int x = 0, y = 0;

	if (map->map[2][1] != 'G') {
		x = 2;
		y = 1;
	}
	else if (map->map[2][12] != 'G') {
		x = 2;
		y = 12;
	}
	else if (map->map[32][1] != 'G') {
		x = 32;
		y = 1;
	}
	else if(map->map[32][12] != 'G') {
		x = 32;
		y = 12;
	}

	pos.X = x;
	pos.Y = y;

	lastChar = map->map[pos.X][pos.Y];
	map->map[pos.X][pos.Y] = 'G';
	map->map[pos.X+1][pos.Y] = 'G';	
}


Enemy::~Enemy()
{
}

void Enemy::update() {
	// MOVING
	map->map[pos.X][pos.Y] = lastChar;
	map->map[pos.X + 1][pos.Y] = lastChar;

loopPoint:

	int dir = rand() % 4; // 0 = up, 1 = down, 2 = left, 3 = right

	switch (dir) {
	case 0:
		if (map->map[pos.X][pos.Y - 1] != '#' && map->map[pos.X][pos.Y - 1] != 'G') {
			pos.Y -= 1;
		}
		else {
			goto loopPoint;
		}
		break;
	case 1:
		if (map->map[pos.X][pos.Y + 1] != '#' && map->map[pos.X][pos.Y + 1] != 'G') {
			pos.Y += 1;
		}
		else {
			goto loopPoint;
		}
		break;
	case 2:
		if (map->map[pos.X - 2][pos.Y] != '#' && map->map[pos.X - 2][pos.Y] != 'G') {
			pos.X -= 2;
		}
		else {
			goto loopPoint;
		}
		break;
	case 3:
		if (map->map[pos.X + 2][pos.Y] != '#' && map->map[pos.X + 2][pos.Y] != 'G') {
			pos.X += 2;
		}
		else {
			goto loopPoint;
		}
		break;
	default:
		break;
	}

	if (map->map[pos.X][pos.Y] == '@') {
		player->died = true;
	}
	else {
		lastChar = map->map[pos.X][pos.Y];
	}

	map->map[pos.X][pos.Y] = 'G';
	map->map[pos.X + 1][pos.Y] = 'G';

	if (map->map[pos.X - 1][pos.Y] == '@' || map->map[pos.X + 2][pos.Y] == '@' || map->map[pos.X][pos.Y - 1] == '@' || map->map[pos.X][pos.Y + 1] == '@') {
		player->died = true;
	}
}
