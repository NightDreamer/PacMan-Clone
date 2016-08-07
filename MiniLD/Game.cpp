#include "Game.h"


Game::Game()
{
	map = new Map();

	player = new Player();
	player->map = map;
	player->init();

	e1 = new Enemy();
	e1->map = map;
	e1->player = player;
	e1->init();

	e2 = new Enemy();
	e2->map = map;
	e2->player = player;
	e2->init();

	e3 = new Enemy();
	e3->map = map;
	e3->player = player;
	e3->init();

	e4 = new Enemy();
	e4->map = map;
	e4->player = player;
	e4->init();

	died = 0;
}


Game::~Game()
{
	delete e4;
	delete e3;
	delete e2;
	delete e1;
	delete player;
	delete map;
}

void Game::restart(bool died) {
	system("cls");

	if (!died) {
		this->died = 0;

		delete e4;
		delete e3;
		delete e2;
		delete e1;
		delete map;

		map = new Map();

		delete player;
		player = new Player();
		player->map = map;
		player->init();

		e1 = new Enemy();
		e1->map = map;
		e1->player = player;
		e1->init();

		e2 = new Enemy();
		e2->map = map;
		e2->player = player;
		e2->init();

		e3 = new Enemy();
		e3->map = map;
		e3->player = player;
		e3->init();

		e4 = new Enemy();
		e4->map = map;
		e4->player = player;
		e4->init();
	}
	else {
		this->died += 1;

		map->map[e4->pos.X][e4->pos.Y] = e4->lastChar;
		map->map[e4->pos.X + 1][e4->pos.Y] = e4->lastChar;
		map->map[e3->pos.X][e3->pos.Y] = e3->lastChar;
		map->map[e3->pos.X + 1][e3->pos.Y] = e3->lastChar;
		map->map[e2->pos.X][e2->pos.Y] = e2->lastChar;
		map->map[e2->pos.X + 1][e2->pos.Y] = e2->lastChar;
		map->map[e1->pos.X][e1->pos.Y] = e1->lastChar;
		map->map[e1->pos.X + 1][e1->pos.Y] = e1->lastChar;
		map->map[player->pos.X][player->pos.Y] = ' ';
		map->map[player->pos.X + 1][player->pos.Y] = ' ';

		delete e4;
		delete e3;
		delete e2;
		delete e1;

		delete player;
		player = new Player();
		player->map = map;
		player->init();
		player->lives -= this->died;

		e1 = new Enemy();
		e1->map = map;
		e1->player = player;
		e1->init();

		e2 = new Enemy();
		e2->map = map;
		e2->player = player;
		e2->init();

		e3 = new Enemy();
		e3->map = map;
		e3->player = player;
		e3->init();

		e4 = new Enemy();
		e4->map = map;
		e4->player = player;
		e4->init();
	}
}

bool Game::update() {
	// LOGIC
	if (player->died) {
		restart(true);
	}

	if (!player->update()) {
		return false;
	}

	if (player->restart) {
		restart(false);
	}

	if (player->lives > 0 && !player->died) {
		e1->update();
		e2->update();
		e3->update();
		e4->update();
	}

	// RENDERING
	map->draw(player->lives);
	return true;
}
