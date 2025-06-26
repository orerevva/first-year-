#include "food.hpp"
#include "const.hpp"
    

Food::Food()
{
    shape.setRadius(CELL_SIZE / 2);
    shape.setFillColor(sf::Color::Red);
    respawn();
}

void Food::respawn()
{
    int x = rand() % (WIDTH / CELL_SIZE) * CELL_SIZE; // чтобы в пределах сетки появлялась
    int y = rand() % (HEIGHT / CELL_SIZE) * CELL_SIZE;
    shape.setPosition(x, y);
}

void Food::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::Vector2f Food::getPosition() const
{
    return shape.getPosition();
}

