#ifndef BIOSHOP_H
#define BIOSHOP_H
#include "Piece.hpp"
#include <set>
#include <unordered_map>

class Bioshop : public Piece
{
public:
    std::vector<std::vector<std::pair<int, int>>> moveCells();
};

#endif
