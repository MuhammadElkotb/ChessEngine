#ifndef ROOK_H
#define ROOK_H
#include "Piece.hpp"
#include <set>
#include <unordered_map>

class Rook : public Piece
{
public:
    std::vector<std::pair<int, int>> moveCells();
};

#endif
