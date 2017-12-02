#include "stdafx.h"
Application::Application(const Config& config)
	: grid(config.rows, config.cols, config.rect_width, config.rect_height)
	, text(config.textX, config.textY)
	, window(sf::VideoMode(config.windowX, config.windowY), config.window_name)
{
	
}
void Application::runLoop() {
	while (window.isOpen()) {
		handleEvent();
		grid.controlGrid(window);
		text.controlText(grid.vis);
		window.clear(sf::Color::Black);
		grid.drawGrid(window);
		text.drawText(window);
		window.display();
	}
}
void Application::handleEvent() {
	sf::Event e;
	while (window.pollEvent(e)) {
		switch (e.type){
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (e.key.code == ('Q' || 'q' || sf::Keyboard::Escape)) {
				window.close();
				break;
			}
		default:
			break;
		}
	}
}