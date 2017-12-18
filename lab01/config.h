#pragma once
#include"stdafx.h"
struct Config{
	int windowX					= 900;
	int windowY					= 980;
	int rows					= 30;
	int cols					= 30;
	int rect_width				= 30;
	int rect_height				= 30;
	int textX					= 400;
	int textY					= 903;
	sf::Color bg_color			= sf::Color::Black;
	sf::Color t_color			= sf::Color::Black;
	sf::Color f_color			= sf::Color::White;
	std::string window_name		= "lbs black hole";
};
