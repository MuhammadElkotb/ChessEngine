#include <iostream>
#include "..\headers\Board.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

int main(){

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    Board Board;
    sf::RenderWindow appWindow(sf::VideoMode(800, 800), "Chess Engine", sf::Style::Titlebar | sf::Style::Close, settings);


    sf::Cursor cursor;
    cursor.loadFromSystem(sf::Cursor::Hand);

    appWindow.setMouseCursor(cursor);

    sf::CircleShape circle(30);

    circle.setFillColor(sf::Color::Red);
    circle.setPosition(50, 60);


    while(appWindow.isOpen()){
        sf::Event event;

        while(appWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                appWindow.close();
            }
        }

        appWindow.clear();
        Board.draw(appWindow);
        appWindow.display();

    }
 
}