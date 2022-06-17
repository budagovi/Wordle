#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class text {
private:
	Text text;
	Font font;
	int charSize;
	Color fillColor;
	Text::Style style;
	Vector2f position;
	string line;

public:
	//DEFAULT CONSTRUCTOR FOR DISPALY TEXT
	void createText(Font f, int s, Color c, Text::Style st, Vector2f p, string l) {
		font = f;
		charSize = s;
		fillColor = c;
		style = st;
		position = p;
		line = l;

		text.setFont(font);
		text.setCharacterSize(charSize);
		text.setFillColor(fillColor);
		text.setStyle(style);
		text.setPosition(position);
		text.setString(line);
	}

	//METHOD TO GET DRAWABLE TEXT
	Text getText() {
		return text;
	}
};

