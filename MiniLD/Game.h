#pragma once
#include "main.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
	Game();
	~Game();

	bool update();
	void restart(bool);

public:
	int died;
	Map*	map;
	Player* player;
	Enemy *e1, *e2, *e3, *e4;
};

