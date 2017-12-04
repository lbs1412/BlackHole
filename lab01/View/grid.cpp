#include "../stdafx.h"

Grid::Grid(int rows, int cols, int width, int height){
	this->rows = rows;
	this->cols = cols;
	this->vis.clear();this->vis.resize(rows);
	for (int i = 0; i < rows; i++)vis[i].resize(cols);
	vr r;
	for (int i = 0; i < rows; i++) {
		r.clear();
		for (int j = 0; j < cols; j++) {
			sf::RectangleShape rect;
			rect.setFillColor(sf::Color::White);
			rect.setPosition(width * i, height * j);
			rect.setSize(sf::Vector2f(width, height));
			rect.setOutlineColor(sf::Color::Cyan);
			rect.setOutlineThickness(0.6);
			r.push_back(rect);
		}
		this->g.push_back(r);
	}
}
Grid::~Grid(){}
void Grid::init() {
	
}
sf::RectangleShape& Grid::getRect(int i,int j) {
	return g[i][j];
}
void Grid::drawGrid(sf::RenderWindow& window) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			window.draw(g[i][j]);
		}
	}
}
void Grid::controlGrid(sf::RenderWindow& window) {
	auto pos = sf::Mouse::getPosition(window);
	int x = pos.x /rows, y = pos.y / cols;
	if (!(x >= 0 && x < rows&&y >= 0 && y < cols))return;
	static bool pressed = false;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		Sleep(90);
		this->vis[x][y] = !this->vis[x][y];
		this->g[x][y].setFillColor(vis[x][y]? sf::Color::Black: sf::Color::White);
	}
}
