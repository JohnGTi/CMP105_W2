#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	// Render text
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error Loading Font\n";
	}

	mousePos.setFont(font);
	mousePos.setString(std::to_string(input->getMouseX()) + ", " + std::to_string(input->getMouseY()));
	mousePos.setCharacterSize(16);
	mousePos.setFillColor(sf::Color::Red);
	//mousePos.setStyle(sf::Text::Bold);
	mousePos.setPosition(1125, 5);
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W) == true)
	{
		input->setKeyUp(sf::Keyboard::W);
		std :: cout << "Double You was pressed big mahn.\n";
	}

	if (input->isKeyDown(sf::Keyboard::J) == true && input->isKeyDown(sf::Keyboard::K) == true && input->isKeyDown(sf::Keyboard::L) == true)
	{
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "Jickle.\n";
	}

	if (input->isKeyDown(sf::Keyboard::Enter) == true)
	{
		input->setKeyUp(sf::Keyboard::Enter);
		std::cout << "Sweet release.\n";
		window->close();
	}

	if (input->isMouseLDown() == true && drag == true)
	{
		x1 = input->getMouseX();
		y1 = input->getMouseY();
		drag = false;
	}

	if (input->isMouseLDown() == false && drag == false)
	{
		x2 = input->getMouseX();
		y2 = input->getMouseY();
		drag = true;
		allCalc = allCalc + 1;
	}

	if (allCalc > 0)
	{
		std::cout << x1 << ", " << y1 << " ; " << x2 << ", " << y2 << "\n";
		//c = static_cast<double>(y2 - y1) / static_cast<double>(x2 - x1);
		c = ((y2 - y1) * (y2 - y1)) + ((x2 - x1) * (x2 - x1));
		c = sqrt(c);
		std::cout << c << "\n";
		allCalc = allCalc - 1;
	}
	//std::cout << ((y2 - y1) / (x2 - x1)) << "\n";
	//std::string mousePos(std::to_string(input->getMouseX()) + ", " + std::to_string(input->getMouseY()));
}

// Update game objects
void Level::update()
{
	mousePos.setString(std::to_string(input->getMouseX()) + ", " + std::to_string(input->getMouseY()));
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(mousePos);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}