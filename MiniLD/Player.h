#pragma once
#include "main.h"
#include "Map.h"

class Player
{
public:
	Player();
	~Player();

	void init();
	bool update();

public:
	bool restart, died;
	int lives;
	Map* map;
	COORD pos;
};

