#include "..\headers\Board.hpp"
#include <iostream>
#include "..\headers\Piece.hpp"
#include <memory>
#include "..\headers\TextureLoader.hpp"


Board::Board()
{
    this->initBoard();
    this->initPieces();
}

Board::~Board()
{
}

void Board::initBoard()
{
    bool even = true;
    float posX = this->originX;
    float posY = this->originY;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Cell cell;
            sf::RectangleShape cellRect(sf::Vector2f(100, 100));
            if (even)
                cellRect.setFillColor({238, 238, 210});
            else
                cellRect.setFillColor({118, 150, 86});
            cellRect.setPosition({posX, posY});
            posX += 100;
            cell.cellRect = cellRect;
            cell.x = i;
            cell.y = j;
            this->cells[i][j] = cell;

            if (j != 7)
                even = !even;
        }
        posY += 100;
        posX = this->originX;
    }
}

void Board::initPieces()
{

    // init Black and White pawns in their intial positions
    for (int i = 0; i < 8; i++)
    {
        Piece blackPawn;
        blackPawn.setCell(this->getCellByPosition(1, i));
        blackPawn.setSprite(sf::Sprite(this->texture_loader.getBlackPawnTexture()));
        this->piecesMap["bP" + std::to_string(i)] = blackPawn;
        Piece whitePawn;
        whitePawn.setCell(this->getCellByPosition(6, i));
        whitePawn.setSprite(sf::Sprite(this->texture_loader.getWhitePawnTexture()));
        this->piecesMap["wP" + std::to_string(i)] = whitePawn;
    }

    // init Black Pieces in their intial positions left to right
    Piece blackRook1;
    Piece blackKnight1;
    Piece blackBioshop1;
    Piece blackKing;
    Piece blackQueen;
    Piece blackBioshop2;
    Piece blackKnight2;
    Piece blackRook2;
    int pos = 0;
    blackRook1.setCell(this->getCellByPosition(0, pos++));
    blackKnight1.setCell(this->getCellByPosition(0, pos++));
    blackBioshop1.setCell(this->getCellByPosition(0, pos++));
    blackKing.setCell(this->getCellByPosition(0, pos++));
    blackQueen.setCell(this->getCellByPosition(0, pos++));
    blackBioshop2.setCell(this->getCellByPosition(0, pos++));
    blackKnight2.setCell(this->getCellByPosition(0, pos++));
    blackRook2.setCell(this->getCellByPosition(0, pos++));


    blackRook1.setSprite(sf::Sprite(this->texture_loader.getBlackRookTexture()));
    blackKnight1.setSprite(sf::Sprite(this->texture_loader.getBlackKnightTexture()));
    blackBioshop1.setSprite(sf::Sprite(this->texture_loader.getBlackBioshopTexture()));
    blackKing.setSprite(sf::Sprite(this->texture_loader.getBlackKingTexture()));
    blackQueen.setSprite(sf::Sprite(this->texture_loader.getBlackQueenTexture()));
    blackBioshop2.setSprite(sf::Sprite(this->texture_loader.getBlackBioshopTexture()));
    blackKnight2.setSprite(sf::Sprite(this->texture_loader.getBlackKnightTexture()));
    blackRook2.setSprite(sf::Sprite(this->texture_loader.getBlackRookTexture()));

    this->piecesMap["bR1"] = blackRook1;
    this->piecesMap["bN1"] = blackKnight1;
    this->piecesMap["bB1"] = blackBioshop1;
    this->piecesMap["bK"] = blackKing;
    this->piecesMap["bQ"] = blackQueen;
    this->piecesMap["bB2"] = blackBioshop2;
    this->piecesMap["bN2"] = blackKnight2;
    this->piecesMap["bR2"] = blackRook2;

  


    // init White Pieces in their intial positions left to right
    Piece whiteRook1;
    Piece whiteKnight1;
    Piece whiteBioshop1;
    Piece whiteKing;
    Piece whiteQueen;
    Piece whiteBioshop2;
    Piece whiteKnight2;
    Piece whiteRook2;

    pos = 0;
    whiteRook1.setCell(this->getCellByPosition(7, pos++));
    whiteKnight1.setCell(this->getCellByPosition(7, pos++));
    whiteBioshop1.setCell(this->getCellByPosition(7, pos++));
    whiteKing.setCell(this->getCellByPosition(7, pos++));
    whiteQueen.setCell(this->getCellByPosition(7, pos++));
    whiteBioshop2.setCell(this->getCellByPosition(7, pos++));
    whiteKnight2.setCell(this->getCellByPosition(7, pos++));
    whiteRook2.setCell(this->getCellByPosition(7, pos++));

    whiteRook1.setSprite(sf::Sprite(this->texture_loader.getWhiteRookTexture()));
    whiteKnight1.setSprite(sf::Sprite(this->texture_loader.getWhiteKnightTexture()));
    whiteBioshop1.setSprite(sf::Sprite(this->texture_loader.getWhiteBioshopTexture()));
    whiteKing.setSprite(sf::Sprite(this->texture_loader.getWhiteKingTexture()));
    whiteQueen.setSprite(sf::Sprite(this->texture_loader.getWhiteQueenTexture()));
    whiteBioshop2.setSprite(sf::Sprite(this->texture_loader.getWhiteBioshopTexture()));
    whiteKnight2.setSprite(sf::Sprite(this->texture_loader.getWhiteKnightTexture()));
    whiteRook2.setSprite(sf::Sprite(this->texture_loader.getWhiteRookTexture()));

    this->piecesMap["wR1"] = whiteRook1;
    this->piecesMap["wN1"] = whiteKnight1;
    this->piecesMap["wB1"] = whiteBioshop1;
    this->piecesMap["wK"] = whiteKing;
    this->piecesMap["wQ"] = whiteQueen;
    this->piecesMap["wB2"] = whiteBioshop2;
    this->piecesMap["wN2"] = whiteKnight2;
    this->piecesMap["wR2"] = whiteRook2;


    for(auto& kv : this->piecesMap){
        this->positionPieceMap[&this->getCellByPosition(kv.second.getCell().x, kv.second.getCell().y)] = &kv.second;
    }
}

void Board::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            window.draw(this->cells[i][j].cellRect);
        }
    }
    for(auto& kv : this->piecesMap){
        window.draw(kv.second.getSprite());
    }
}

TextureLoader &Board::getTextureLoader()
{
    return this->texture_loader;
}

Cell &Board::getCellByPosition(int x, int y)
{
    return this->cells[x][y];
}

Piece& Board::getPieceByName(std::string name){
    return this->piecesMap[name];
}

std::map<Cell*, Piece*>& Board::getPositionPieceMap(){
    return this->positionPieceMap;
}