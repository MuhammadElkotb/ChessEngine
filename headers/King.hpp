#ifndef KING_H
#define KING_H
#include "Piece.hpp"
#include <vector>
class King : public Piece
{
    public:
        std::vector<std::pair<int, int>> moveCells();
};

#endif
