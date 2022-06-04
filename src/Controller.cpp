#include "..\headers\Controller.hpp"
#include <vector>
#include <utility>
Controller::Controller() {}
Controller::~Controller() {}

std::set<std::pair<int, int>> Controller::validateMove(Board &board, Piece *piece)
{
    std::set<std::pair<int, int>> move_cells = piece->moveCells();
    std::set<std::pair<int, int>> empty_move_cells;

    for (auto &kv : move_cells)
    {
        Cell *cell = board.getCellByPosition(kv.first, kv.second);
        if (board.getPositionPieceMap().find(cell) != board.getPositionPieceMap().end())
            break;
        empty_move_cells.insert(kv);
    }
    return empty_move_cells;
}

void Controller::drawMoveCells(Board &board, std::set<std::pair<int, int>> &move_cells)
{

    for (auto &kv : move_cells)
    {
        Cell *cell = board.getCellByPosition(kv.first, kv.second);
        cell->cell_rect.setFillColor(sf::Color({147, 212, 166}));
    }
}

void Controller::resetColor(Board &board, std::set<std::pair<int, int>> &move_cells)
{
    for (auto &kv : move_cells)
    {
        board.getCellByPosition(kv.first, kv.second)->cell_rect.setFillColor(board.getCellByPosition(kv.first, kv.second)->default_colour);
    }
}

void Controller::movePiece(Board &board, Piece *piece, std::pair<int, int> cell, std::set<std::pair<int, int>> &move_cells)
{

    if (move_cells.find(cell) != move_cells.end())
    {
        board.getPositionPieceMap().erase(board.getCellByPosition(piece->getCell()->row, piece->getCell()->col));

        piece->move(board.getCellByPosition(cell.first, cell.second));
        piece->setFirstMove(false);
        board.getPositionPieceMap()[piece->getCell()] = piece;
    }
    else
    {
        piece->move(piece->getCell());
    }
}
