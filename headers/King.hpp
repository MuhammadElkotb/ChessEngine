#ifndef KING_H
#define KING_H
#include "Piece.hpp"
#include <set>
#include <unordered_map>


class King : public Piece
{
public:
    std::vector<std::vector<std::pair<int, int>>> moveCells();
};

#endif
