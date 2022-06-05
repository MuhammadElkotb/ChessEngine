#include "..\headers\Controller.hpp"
#include <vector>
#include <utility>
Controller::Controller() {}
Controller::~Controller() {}

std::vector<std::pair<int, int>> Controller::validateMove(Board &board, Piece *piece)
{
    std::vector<std::vector<std::pair<int, int>>> move_cells = piece->moveCells();
    std::vector<std::pair<int, int>> empty_move_cells;

    for (auto &v : move_cells)
    {
        for (auto &kv : v)
        {
            Cell *cell = board.getCellByPosition(kv.first, kv.second);
            if (board.getPositionPieceMap().find(cell) != board.getPositionPieceMap().end())
                break;
            empty_move_cells.push_back(kv);
        }
    }

    return empty_move_cells;
}

void Controller::drawMoveCells(Board &board, std::vector<std::pair<int, int>> &move_cells)
{

    for (auto &kv : move_cells)
    {
        Cell *cell = board.getCellByPosition(kv.first, kv.second);
        cell->cell_rect.setFillColor(sf::Color({147, 212, 166}));
    }
}

void Controller::resetColor(Board &board, std::vector<std::pair<int, int>> &move_cells)
{
    for (auto &kv : move_cells)
    {
        board.getCellByPosition(kv.first, kv.second)->cell_rect.setFillColor(board.getCellByPosition(kv.first, kv.second)->default_colour);
    }
}

void Controller::movePiece(Board &board, Piece *piece, std::pair<int, int> cell, std::vector<std::pair<int, int>> &move_cells)
{

    if (std::find(move_cells.begin(), move_cells.end(), cell) != move_cells.end())
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
