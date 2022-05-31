#include <iostream>
#include "..\headers\Board.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

int main()
{

    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;
    Board board;
    sf::RenderWindow appWindow(sf::VideoMode(800, 800), "Chess Engine", sf::Style::Titlebar | sf::Style::Close, settings);

    int ctr = 0;
    bool held_piece = false;
    while (appWindow.isOpen())
    {
        sf::Event event;

        while (appWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                appWindow.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                int y = sf::Mouse::getPosition(appWindow).x / 100;
                int x = sf::Mouse::getPosition(appWindow).y / 100;
            }
        }
        appWindow.clear();
        board.draw(appWindow);
        appWindow.display();
    }
}