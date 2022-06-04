#ifndef BIOSHOP_H
#define BIOSHOP_H
#include "Piece.hpp"

class Bioshop : public Piece
{
public:
    std::vector<std::pair<int, int>> moveCells();
};

#endif
