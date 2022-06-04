#ifndef PAWN_H
#define PAWN_H
#include "Piece.hpp"

class Pawn : public Piece
{
public:
    std::vector<std::pair<int, int>> moveCells();
};

#endif
