#include <iostream>
#include "..\headers\MACROS.hpp"
#include "..\headers\Board.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "..\headers\Controller.hpp"
#include <vector>
#include <utility>

int main()
{

    sf::ContextSettings settings;
    Board board;
    Controller controller;
    sf::RenderWindow appWindow(sf::VideoMode(800, 800), "Chess Engine", sf::Style::Titlebar | sf::Style::Close, settings);
    appWindow.setVerticalSyncEnabled(true);
    appWindow.setFramerateLimit(60);
    sf::Cursor cursor_hand;
    sf::Cursor cursor_defualt;
    cursor_hand.loadFromSystem(sf::Cursor::Hand);
    cursor_defualt.loadFromSystem(sf::Cursor::Arrow);

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

                std::vector<std::pair<int, int>> move_cells;
                std::vector<std::pair<int, int>> move_cells_after_check;
                Cell *cell_clicked = board.getCellByPosition(row, col);
                Piece *found_piece = board.getPieceByCell(cell_clicked);
                if (found_piece != NULL && !held_piece)
                {
                    if (found_piece->isWhite() == controller.whiteTurn)
                    {
                        held_piece = true;
                        current_cell = cell_clicked;
                        move_cells = controller.validateMove(board, board.getPositionPieceMap()[current_cell]);
                        move_cells_after_check = controller.nextMoveCheck(board, board.getPositionPieceMap()[current_cell], move_cells);
                    }
                }
                if (held_piece)
                {
                    float x_mouse = sf::Mouse::getPosition(appWindow).x - 20;
                    float y_mouse = sf::Mouse::getPosition(appWindow).y - 25;
                    Piece *current_piece = board.getPositionPieceMap()[current_cell];
                    current_piece->getSprite().setPosition(x_mouse, y_mouse);
                    controller.drawMoveCells(board, move_cells_after_check);
                }
                appWindow.setMouseCursor(cursor_hand);
            }
            if (event.type == sf::Event::MouseButtonReleased && held_piece)
            {
                std::vector<std::pair<int, int>> move_cells;

                int y = sf::Mouse::getPosition(appWindow).x / 100;
                int x = sf::Mouse::getPosition(appWindow).y / 100;
                held_piece = false;
                Piece *move_piece = board.getPositionPieceMap()[current_cell];
                Piece *move_piece2 = board.getPieceByCell(current_cell);
                log(move_piece);
                log(move_piece2);

                move_cells = controller.validateMove(board, move_piece);
                controller.resetColor(board, move_cells);
                std::vector<std::pair<int, int>> move_cells_after_check = controller.nextMoveCheck(board, move_piece, move_cells);
                controller.movePiece(board, move_piece, std::pair<int, int>(x, y), move_cells_after_check);

                appWindow.setMouseCursor(cursor_defualt);
            }
        }
        appWindow.clear();
        board.draw(appWindow);
        appWindow.display();
    }
}