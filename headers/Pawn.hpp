#ifndef PAWN_H
#define PAWN_H
#include "Piece.hpp"
#include <set>
#include <unordered_map>

class Pawn : public Piece
{
private:
    

public:
    Pawn();
    ~Pawn();
    std::vector<std::vector<std::pair<int, int>>> moveCells();
    
};

#endif
