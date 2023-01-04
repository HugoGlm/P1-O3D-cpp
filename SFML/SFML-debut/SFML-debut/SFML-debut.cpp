#include <iostream>
#include <SFML/Graphics.hpp>

int Forme()
{
    sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");

    // d�finit un cercle
    sf::CircleShape shape(50.0f);
    shape.setFillColor(sf::Color::Green);

    // d�finit un rectangle
    sf::RectangleShape rectangle(sf::Vector2f(120.0f, 50.0f));
    rectangle.setSize(sf::Vector2f(100.f, 100.f));
    rectangle.setFillColor(sf::Color::Red);

    // d�finit un triangle
    sf::CircleShape triangle(80.f, 3);

    // d�finit un carr�
    sf::CircleShape square(80.f, 4);

    // d�finit un octogone
    sf::CircleShape octagon(80.f, 8);

    // d�finit un convex
    sf::ConvexShape convex;

    // d�finit le nombre de points
    convex.setPointCount(5);

    // d�finit les points
    convex.setPoint(0, sf::Vector2f(0.f, 0.f));
    convex.setPoint(1, sf::Vector2f(150.f, 10.f));
    convex.setPoint(2, sf::Vector2f(120.f, 90.f));
    convex.setPoint(3, sf::Vector2f(30.f, 100.f));
    convex.setPoint(4, sf::Vector2f(0.f, 50.f));

    convex.setFillColor(sf::Color::Green);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(convex);
        window.display();
    }

    return 0;
}

int Texture()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

    sf::Texture texture;
    sf::Sprite sprite;

    texture.loadFromFile("C:/Users/GUIL2804/Pictures/CLS.png");
    sprite.setTexture(texture, false);

    sf::CircleShape shape(200.0f);
    shape.setTexture(&texture);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}

int main()
{
    Texture();
}