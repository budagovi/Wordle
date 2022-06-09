#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Button {
private:
	RectangleShape button;
	Vector2f position;
	Vector2f size;
	Event e;
	Color fillColor;
	string link;
	Texture texture;
public:
	void createButton(Vector2f Position, Vector2f Size, Event E, Color FillColor, const sf::Texture & Texture) {
		size = Size;
		position = Position;
		e = E;
		fillColor = FillColor;
		
		

		button.setPosition(position);
		button.setSize(size);
		button.setFillColor(fillColor);
		button.setTexture(&Texture);

	}

	RectangleShape getButton() {
		return button;
	}

	bool isClicked() {
		if (e.mouseButton.x > position.x && e.mouseButton.x < position.x + size.x && e.mouseButton.y>position.y && e.mouseButton.y < position.y + size.y) return true;
		else return false;
	}
	
	
};

