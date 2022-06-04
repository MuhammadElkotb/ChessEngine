#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.hpp"
#include <set>
class Knight : public Piece
{
public:
    std::set<std::pair<int, int>> moveCells();
};

#endif
