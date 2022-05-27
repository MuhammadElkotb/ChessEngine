#ifndef PIECE_H
#define PIECE_H
#include <SFML\Graphics.hpp>
#include "Cell.hpp"

class Piece {
private:
    Cell cell;
    sf::Sprite sprite;
    sf::Texture texture;
public:
    Piece();
    ~Piece();
    Cell getCell();
    void setCell(const Cell& cell);
    void setSprite(sf::Sprite sprite);
    sf::Sprite getSprite();
    
    
};

#endif