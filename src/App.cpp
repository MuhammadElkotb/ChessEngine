#include <iostream>
#include "..\headers\Board.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

int main()
{

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
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
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                int y = sf::Mouse::getPosition(appWindow).x / 100;
                int x = sf::Mouse::getPosition(appWindow).y / 100;
                if (event.type == sf::Event::MouseMoved)
                {
                    if (board.getPositionPieceMap().find(&board.getCellByPosition(x, y)) != board.getPositionPieceMap().end())
                    {
                        held_piece = true;
                        board.getPositionPieceMap()[&board.getCellByPosition(x, y)]->getSprite().setPosition(sf::Mouse::getPosition(appWindow).x, sf::Mouse::getPosition(appWindow).y);
                    }
                }
                
            }
            else{
                held_piece = false;

            }
        }
        appWindow.clear();
        board.draw(appWindow);
        appWindow.display();
    }
}