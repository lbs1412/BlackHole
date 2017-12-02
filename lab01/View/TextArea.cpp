#include "../stdafx.h"

sf::Font TextArea::getFont() {
	return this->font;
}
sf::Text TextArea::getText() {
	return this->text;
}
TextArea::TextArea(int x,int y):font(),text() {
	this->font.loadFromFile("Res/fonts/CONSOLA.TTF");
	this->text = sf::Text();
	text.setFont(font);
	this->text.setCharacterSize(15);
	this->text.setStyle(sf::Text::Bold);
	this->text.setFillColor(sf::Color::Red);
	this->text.setPosition(x, y);
}
TextArea::~TextArea() {};
void TextArea::drawText(sf::RenderWindow& window) {
	window.draw(text);
}
void TextArea::controlText(std::vector<vb>&vis) {
	std::string ans = getAnswer(vis);
	this->text.setString(ans);
}