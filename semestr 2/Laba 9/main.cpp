#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "GAME");
	window.setFramerateLimit(60);

	sf::Font font;
	font.loadFromFile("calibri.ttf");

	Game game;
	game.setPosition(50.f, 50.f);

	sf::Event event;
	int move_counter = 0;	

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) 
                window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left) 
                    game.Move(Direction::Left);
				if (event.key.code == sf::Keyboard::Right) 
                    game.Move(Direction::Right);
				if (event.key.code == sf::Keyboard::Up) 
                    game.Move(Direction::Up);
				if (event.key.code == sf::Keyboard::Down) 
                    game.Move(Direction::Down);
	
				if (event.key.code == sf::Keyboard::F2)
				{
					game.Init();
					move_counter = 100;
				}
			}
		}

		if (move_counter-- > 0) 
            game.Move((Direction)(rand() % 4));

		window.clear();
		window.draw(game);
		window.display();
	}
	return 0;
}

