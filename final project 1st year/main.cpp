#include <SFML/Graphics.hpp>
#include "snake.hpp"
#include "food.hpp"
#include "score.hpp"
#include "const.hpp"

int main()
{
    bool restartGame = true;
    while (restartGame)
    {
        sf::RenderWindow window(sf:: VideoMode(WIDTH, HEIGHT), "SNAKE GAME");
        window.setFramerateLimit(10);

        Snake snake;
        Food food;

        bool gameRunning = true;
        bool windowClosedUser = false;

        while (window.isOpen() && gameRunning)
        {
            sf::Event event;
            while(window.pollEvent(event)) //получает следующее событие из очереди
            {
                if (event.type == sf::Event::Closed) 
                {
                    window.close();
                    windowClosedUser = true;
                    restartGame = false;
                }
                if (event.type == sf::Event::KeyPressed)
                {
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                        snake.setDirection({0, -CELL_SIZE});
                        break;
                    case sf::Keyboard::Down:
                        snake.setDirection({0, CELL_SIZE});
                        break;
                    case sf::Keyboard::Left:
                        snake.setDirection({-CELL_SIZE, 0});
                        break;
                    case sf::Keyboard::Right:
                        snake.setDirection({CELL_SIZE, 0});
                        break;
                    }
                } 
            }

            if (windowClosedUser)
                break;

            snake.move();

            if(snake.getHeadPosition() == food.getPosition())
            {
                snake.grow();
                food.respawn();
            }

            if (snake.isGameOver())
            {
                int currentScore = snake.getSegments().size() - 1; 
                
                sf::Font font;
                font.loadFromFile("arial.ttf");

                std::string name = getPlayerName(window, font);

                std::vector<ScoreEntry> scores = loadHighScores("highscores.txt");
                scores.push_back({name, currentScore});
                std::sort(scores.begin(), scores.end(), compareScores);

                if (scores.size() > 5)
                {
                    scores.resize(5);
                }

                saveHighScores(scores, "highscores.txt");

                bool playAgain = showGameOverMenu(window, {name, currentScore}, scores);
                if(!playAgain)
                    return 0;
                else
                    gameRunning = false;
            }

            window.clear(sf::Color::Black);
            snake.draw(window);
            food.draw(window);
            window.display();
        }
    }

    return 0;
}