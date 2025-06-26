#include "snake.hpp"
#include "const.hpp"

Snake::Snake() 
{
    segments.push_back(sf::RectangleShape(sf::Vector2f(CELL_SIZE, CELL_SIZE)));
    segments[0].setFillColor(sf::Color::Green);
    segments[0].setPosition(WIDTH / 2, HEIGHT / 2);

    direction = {CELL_SIZE, 0}; // начальное направление вправо
}

void Snake::move() 
{
    for (int i = segments.size() - 1; i > 0; --i) 
    {
        segments[i].setPosition(segments[i - 1].getPosition());
    }
    segments[0].move(direction);
}

void Snake::setDirection(sf::Vector2f newDir)
{
    if(newDir != -direction)
    {
        direction = newDir;
    }
}

void Snake::grow()
{
    sf::RectangleShape newSegment(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    newSegment.setFillColor(sf::Color::Green);
    
    if (segments.size() == 1) 
    {
        sf::Vector2f tailPos = segments[0].getPosition() - direction;
        newSegment.setPosition(tailPos);
    }
    else
    {
        sf::Vector2f lastPos = segments.back().getPosition();
        sf::Vector2f prevPos = segments[segments.size() - 2].getPosition();
        sf::Vector2f offset = lastPos - prevPos; 
        newSegment.setPosition(lastPos + offset);
    }

    segments.push_back(newSegment);
}

void Snake::draw(sf::RenderWindow& window) // чтобы не копировать окно
{
    for(int i = 0; i < segments.size(); i++) 
    {
        window.draw(segments[i]);
    }
}

sf::Vector2f Snake::getHeadPosition() const 
{
    return segments[0].getPosition();
}

const std::vector<sf::RectangleShape>& Snake::getSegments() const
{
    return segments;
}

bool Snake::isGameOver() const
{
    sf::Vector2f headPosition = segments[0].getPosition();
    if (headPosition.x < 0 || headPosition.y < 0 || headPosition.x >= WIDTH || headPosition.y >= HEIGHT)
    {
        return true;
    }

    for(int i = 1; i <segments.size(); i++)
    {
        if(headPosition == segments[i].getPosition())
        {
            return true;
        }
    }

    return false;
}

