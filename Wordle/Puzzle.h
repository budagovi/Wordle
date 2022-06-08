#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Puzzle {
private:
	Vector2f size;
	Vector2f position;
	int outlineThickness;
	Color fillColor;
	Color outlineColor;
public:
	Puzzle( Vector2f Size, Vector2f Position, int Thickness, Color fill, Color outline) {
		RectangleShape shape;
		size = Size;
		position = Position;
		outlineThickness = Thickness;
		fillColor = fill;
		outlineColor = outline;

		
		
	}

	void setFillColor(Color c) {
		fillColor = c;
	}

	RectangleShape shape () {
		RectangleShape shape;
		shape.setSize(size);
		shape.setPosition(position);
		shape.setOutlineThickness(outlineThickness);
		shape.setFillColor(fillColor);
		shape.setOutlineColor(outlineColor);

		return shape;
	}


};
