#ifndef BIOSHOP_H
#define BIOSHOP_H
#include "Piece.hpp"
#include <set>
class Bioshop : public Piece
{
public:
    std::set<std::pair<int, int>> moveCells();
};

#endif
