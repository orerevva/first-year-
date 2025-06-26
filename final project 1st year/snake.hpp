#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Snake
{
    private:
        std::vector<sf::RectangleShape> segments;
        sf::Vector2f direction;
       

    public:
        Snake();
        void move(); 
        void setDirection(sf::Vector2f newDir);
        void grow();
        void draw(sf::RenderWindow& window);
        sf::Vector2f getHeadPosition() const;
        const std::vector<sf::RectangleShape>& getSegments() const;
        bool isGameOver() const;
};
