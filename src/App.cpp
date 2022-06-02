#include <iostream>
#include "..\headers\Board.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#define log(X) std::cout << X << std::endl
int main()
{

    sf::ContextSettings settings;
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
            Cell *current_cell;

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                int y = sf::Mouse::getPosition(appWindow).x / 100;
                int x = sf::Mouse::getPosition(appWindow).y / 100;
                Cell *cell_clicked = board.getCellByPosition(x, y);
                bool found_piece = board.getPositionPieceMap().find(cell_clicked) != board.getPositionPieceMap().end();
                if (found_piece && !held_piece)
                {
                    held_piece = true;
                    current_cell = cell_clicked;
                }
                if (held_piece)
                {
                    // log(current_cell);
                    float x_mouse = sf::Mouse::getPosition(appWindow).x;
                    float y_mouse = sf::Mouse::getPosition(appWindow).y;
                    board.getPositionPieceMap()[current_cell]->getSprite().setPosition(x_mouse, y_mouse);
                }
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                log("RELEASED MOUSE EVENT");
                held_piece = false;
                int y = sf::Mouse::getPosition(appWindow).x / 100;
                int x = sf::Mouse::getPosition(appWindow).y / 100;
                Cell *temp_cell = board.getCellByPosition(x, y);
                Piece *temp_piece;
                temp_piece = board.getPositionPieceMap()[current_cell];
                board.getPositionPieceMap().erase(current_cell);
                board.getPositionPieceMap()[temp_cell] = temp_piece;
            }
        }
        appWindow.clear();
        board.draw(appWindow);
        appWindow.display();
    }
}