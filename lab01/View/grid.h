#pragma once
#include "../stdafx.h"
typedef std::vector<sf::RectangleShape> vr;
typedef std::vector<bool> vb;

class Grid {
private:
	std::vector<vr> g;
	int rows,cols,width,height;
public:
	std::vector<vb> vis;
public:
	Grid(int,int,int,int);
	~Grid();
	void init();
	void Grid::drawGrid(sf::RenderWindow&);
	sf::RectangleShape& getRect(int,int);
	void controlGrid(sf::RenderWindow&);
};
