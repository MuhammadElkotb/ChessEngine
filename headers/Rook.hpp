#ifndef ROOK_H
#define ROOK_H
#include "Piece.hpp"

class Rook : public Piece
{
public:
    std::vector<std::pair<int, int>> moveCells();
};

#endif
