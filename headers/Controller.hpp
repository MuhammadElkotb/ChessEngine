#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Board.hpp"
#include <vector>
#include <utility>
class Controller
{

public:
    Controller();
    ~Controller();
    std::set<std::pair<int, int>> validateMove(Board &board, Piece *piece);
    void drawMoveCells(Board &board, std::set<std::pair<int, int>> &move_cells);
    void resetColor(Board &board, std::set<std::pair<int, int>> &move_cells);
    void movePiece(Board &board, Piece* piece, std::pair<int, int> cell, std::set<std::pair<int, int>>& move_cells);
};

#endif