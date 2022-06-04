#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.hpp"

class Queen : public Piece
{
public:
    std::vector<std::pair<int, int>> moveCells();
};

#endif
