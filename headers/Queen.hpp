#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.hpp"
#include <set>

class Queen : public Piece
{
public:
    std::set<std::pair<int, int>> moveCells();
};

#endif
