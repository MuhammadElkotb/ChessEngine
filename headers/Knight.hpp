#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.hpp"

class Knight : public Piece
{
public:
    std::vector<std::pair<int, int>> moveCells();
};

#endif
