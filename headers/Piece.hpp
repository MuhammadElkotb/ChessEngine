#ifndef PIECE_H
#define PIECE_H
#include <SFML\Graphics.hpp>
#include "Cell.hpp"

class Piece
{
private:
    Cell *cell;
    sf::Sprite sprite;
    bool killed;

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
};

#endif