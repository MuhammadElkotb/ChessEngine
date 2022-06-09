#ifndef BOARD_H
#define BOARD_H
#include <SFML\Graphics.hpp>
#include <vector>
#include <array>
#include <unordered_map>
#include <string>
#include "Piece.hpp"
#include "Cell.hpp"
#include "TextureLoader.hpp"

class Board
{

private:
    std::array<std::array<Cell, 8>, 8> cells;
    std::array<Piece *, 32> pieces;
    std::unordered_map<Cell *, Piece *> positionPieceMap;
    TextureLoader texture_loader;
    float originX = 0;
    float originY = 0;
    void initBoard();
    void initPieces();
    void setPiecesSprites();

public:
    Board();
    ~Board();
    void draw(sf::RenderWindow &window);
    TextureLoader &getTextureLoader();
    Cell *getCellByPosition(int row, int col);
    Piece* getPieceByCell(Cell* cell);
    std::unordered_map<Cell *, Piece *> &getPositionPieceMap();

};

#endif