#ifndef BOARD_H
#define BOARD_H
#include <SFML\Graphics.hpp>
#include <vector>
#include <array>
#include "Piece.hpp"

class Board {

private:
    std::array<std::array<sf::RectangleShape, 8>, 8> cells;
    std::array<Piece, 32> pieces;
    float originX = 0;
    float originY = 0;
    void initBoard();
public:
    
    Board();
    ~Board();
    void draw(sf::RenderWindow& window);

};


#endif