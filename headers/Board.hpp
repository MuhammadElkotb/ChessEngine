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

class Board {

private:
    std::array<std::array<Cell, 8>, 8> cells;
    std::unordered_map<std::string, Piece> piecesMap;
    std::map<Cell*, Piece*> positionPieceMap;
    TextureLoader texture_loader;
    float originX = 0;
    float originY = 0;
    void initBoard();
    void initPieces();
    void setPiecesSprites();

public:
    Board();
    ~Board();
    void draw(sf::RenderWindow& window);
    TextureLoader& getTextureLoader();
    std::unordered_map<std::string, Piece>& getPiecesMap();
    Cell& getCellByPosition(int x, int y);
    Piece& getPieceByName(std::string name);
    std::map<Cell*, Piece*>& getPositionPieceMap();
};


#endif