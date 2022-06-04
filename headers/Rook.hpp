#ifndef ROOK_H
#define ROOK_H
#include "Piece.hpp"
#include <set>
class Rook : public Piece
{
public:
    std::set<std::pair<int, int>> moveCells();
};

#endif
