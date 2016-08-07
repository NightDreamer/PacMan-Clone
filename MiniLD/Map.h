#pragma once
#include "main.h"

const int mapSizeX = 36, mapSizeY = 14;

class Map
{
public:
	Map();
	~Map();

	void draw(int lives);

public:
	char map[mapSizeX][mapSizeY];
};

