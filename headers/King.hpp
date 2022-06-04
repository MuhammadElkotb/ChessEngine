#ifndef KING_H
#define KING_H
#include "Piece.hpp"
#include <set>
class King : public Piece
{
public:
    std::set<std::pair<int, int>> moveCells();
};

#endif
