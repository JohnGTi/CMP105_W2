#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>

class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// Add your object here
	sf::Font font;
	sf::Text mousePos;

	bool drag = true;
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	int allCalc = 0;
	double c = 0;
};