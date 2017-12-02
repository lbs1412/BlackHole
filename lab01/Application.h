#pragma once
#include"stdafx.h"
class Application {
public:
	Application(const Config&);
	void runLoop();
	void handleEvent();
private:
	sf::RenderWindow window;
	Grid grid;
	TextArea text;
};
