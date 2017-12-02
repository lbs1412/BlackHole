#pragma once
class TextArea {
private:
	sf::Font font;
	sf::Text text;
public:
	TextArea(int,int);
	~TextArea();
	sf::Font getFont();
	sf::Text getText();
	void drawText(sf::RenderWindow&);
	void controlText(std::vector<std::vector<bool>>&);
};
