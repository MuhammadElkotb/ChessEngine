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

                int col = sf::Mouse::getPosition(appWindow).x / 100;
                int row = sf::Mouse::getPosition(appWindow).y / 100;
                if (row < 0 || row > 7 || col < 0 || col > 7)
                    break;

                Cell *cell_clicked = board.getCellByPosition(row, col);
                bool found_piece = board.getPositionPieceMap().find(cell_clicked) != board.getPositionPieceMap().end();
                if (found_piece && !held_piece)
                {
                    held_piece = true;
                    current_cell = cell_clicked;
                }
                if (held_piece)
                {
                    // log(current_cell);
                    float x_mouse = sf::Mouse::getPosition(appWindow).x - 7;
                    float y_mouse = sf::Mouse::getPosition(appWindow).y - 15;
                    Piece *current_piece = board.getPositionPieceMap()[current_cell];
                    current_piece->getSprite().setPosition(x_mouse, y_mouse);
                    if (current_piece->getCell()->row == 1)
                    {
                        board.getCellByPosition(current_cell->row + 1, current_cell->col)->cellRect.setFillColor(sf::Color({105, 54, 123}));
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                log("RELEASED MOUSE EVENT");
                held_piece = false;
                int y = sf::Mouse::getPosition(appWindow).x / 100;
                int x = sf::Mouse::getPosition(appWindow).y / 100;
                Piece *temp_piece = board.getPositionPieceMap()[current_cell];
                temp_piece->move(current_cell);
            }
        }
        appWindow.clear();
        board.draw(appWindow);
        appWindow.display();
    }
}