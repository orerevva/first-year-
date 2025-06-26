#pragma once
#include <SFML/Graphics.hpp>

class Food
{
    private:
        sf::CircleShape shape;
    
    public:
        Food();
        void respawn();
        void draw(sf::RenderWindow& window);
        sf::Vector2f getPosition() const;
};
