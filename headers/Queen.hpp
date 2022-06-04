#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.hpp"
#include <set>
#include <unordered_map>


class Queen : public Piece
{
public:
    std::vector<std::pair<int, int>> moveCells();
};

#endif
