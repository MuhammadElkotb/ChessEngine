#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.hpp"
#include <set>
#include <unordered_map>


class Knight : public Piece
{
public:
    std::vector<std::vector<std::pair<int, int>>> moveCells();
};

#endif
