#ifndef BOARD_H
#define BOARD_H
#include <SFML\Graphics.hpp>
#include <vector>
#include <array>
#include "Piece.hpp"
#include "Cell.hpp"


class Board {

private:
    std::array<std::array<Cell, 8>, 8> cells;
    std::array<Piece, 32> pieces;
    float originX = 0;
    float originY = 0;
    void initBoard();
    void initPieces();

public:
    Board();
    ~Board();
    void draw(sf::RenderWindow& window);
    sf::Sprite tempSprite;
    std::unique_ptr<sf::Texture> tempTexture;

};








#endif