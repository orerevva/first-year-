#include <SFML/Graphics.hpp>
#include <iostream>
#define PI acos(-1)

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::RectangleShape shape(sf::Vector2f(120.f, 50.f));
    sf::CircleShape triangle(150.f,3);
    sf::CircleShape circle(100.f);

    triangle.setFillColor(sf::Color::Red);
    shape.setFillColor(sf::Color::White);
    circle.setFillColor(sf::Color::Magenta);

    triangle.setPosition(300,600);
    circle.setPosition(700,500);
    shape.setPosition(550, 250);
    
    float setY = 150.f * (1 - std::sqrt(3) / 3); 

    triangle.setOrigin(150.f, 150.f - setY); 
    circle.setOrigin(100.f, 100.f);
    shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
    
    
    sf::Clock clock;
    float w = 100;
    float t_previous = 0;
    float t2 = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float t = clock.getElapsedTime().asSeconds();
        float dt = t - t_previous;
        t_previous = t;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
        {
            shape.rotate(w*dt);
            circle.rotate(w*dt);
            triangle.rotate(w*dt);
            t2 += dt;
            std::cout << t2 << std::endl;
          
        }
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            shape.rotate(-w*dt);
            circle.rotate(-w*dt);
            triangle.rotate(-w*dt);
            t2 += dt;
            std::cout << t2 << std::endl;
        }

        window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(triangle);
        window.draw(circle);
        window.display();
    }
}