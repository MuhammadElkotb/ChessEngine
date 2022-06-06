#ifndef PIECE_H
#define PIECE_H
#include <SFML\Graphics.hpp>
#include "Cell.hpp"
#include <utility>
#include <set>
#include <array>

class Piece
{
protected:
    Cell *cell;
    sf::Sprite sprite;
    bool killed = false;
    bool first_move = true;
    bool white;
    bool pawn = false;
    bool king = false;

public:
    Piece();
    ~Piece();
    Cell *getCell();
    void setCell(Cell *cell);
    void setSprite(sf::Sprite sprite);
    sf::Sprite &getSprite();
    void move(Cell *cell);
    bool isKilled();
    void kill();
    virtual std::vector<std::vector<std::pair<int, int>>> moveCells() = 0;
    bool isWhite();
    bool isFirstMove();
    void setWhite(bool white);
    void setFirstMove(bool first_move);
    bool isPawn();
    void setPawn(bool pawn);
    bool isKing();
    void setKing(bool king);
};

#endif