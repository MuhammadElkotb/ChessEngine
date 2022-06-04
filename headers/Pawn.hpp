#ifndef PAWN_H
#define PAWN_H
#include "Piece.hpp"
#include <set>
class Pawn : public Piece
{
private:
    

public:
    Pawn();
    ~Pawn();
    std::set<std::pair<int, int>> moveCells();
    
};

#endif
