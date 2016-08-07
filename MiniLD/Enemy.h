#pragma once
#include "Map.h"
#include "Player.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	void init();
	void update();

public:
	COORD pos;
	char lastChar;

	Map* map;
	Player* player;
};

