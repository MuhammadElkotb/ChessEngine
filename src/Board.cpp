#include "..\headers\Board.hpp"
#include <iostream>
#include "..\headers\Piece.hpp"
#include <memory>
#include "..\headers\TextureLoader.hpp"

Board::Board()
{
    this->initBoard();
    this->initPieces();

    for (Piece &piece : this->pieces)
    {
        this->positionPieceMap[piece.getCell()] = &piece;
    }
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
            cell.row = i;
            cell.col = j;
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
    int pos = 0;

    for (int i = 0; i < 8; i++)
    {
        Piece blackPawn;
        blackPawn.setCell(this->getCellByPosition(1, pos++));
        blackPawn.setSprite(sf::Sprite(this->texture_loader.getBlackPawnTexture()));
        this->pieces[i] = blackPawn;
    }
    pos = 0;
    for (int i = 8; i < 16; i++)
    {
        Piece whitePawn;
        whitePawn.setCell(this->getCellByPosition(6, pos++));
        whitePawn.setSprite(sf::Sprite(this->texture_loader.getWhitePawnTexture()));
        this->pieces[i] = whitePawn;
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

    pos = 0;

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
    int piece_ctr = 16;
    this->pieces[piece_ctr++] = blackRook1;
    this->pieces[piece_ctr++] = blackKnight1;
    this->pieces[piece_ctr++] = blackBioshop1;
    this->pieces[piece_ctr++] = blackKing;
    this->pieces[piece_ctr++] = blackQueen;
    this->pieces[piece_ctr++] = blackBioshop2;
    this->pieces[piece_ctr++] = blackKnight2;
    this->pieces[piece_ctr++] = blackRook2;

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

    this->pieces[piece_ctr++] = whiteRook1;
    this->pieces[piece_ctr++] = whiteKnight1;
    this->pieces[piece_ctr++] = whiteBioshop1;
    this->pieces[piece_ctr++] = whiteKing;
    this->pieces[piece_ctr++] = whiteQueen;
    this->pieces[piece_ctr++] = whiteBioshop2;
    this->pieces[piece_ctr++] = whiteKnight2;
    this->pieces[piece_ctr++] = whiteRook2;
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

    for (Piece &piece : this->pieces)
    {
        if (!piece.isKilled())
            window.draw(piece.getSprite());
    }
}

TextureLoader &Board::getTextureLoader()
{
    return this->texture_loader;
}

Cell *Board::getCellByPosition(int row, int col)
{
    return &this->cells[row][col];
}

std::map<Cell *, Piece *> &Board::getPositionPieceMap()
{
    return this->positionPieceMap;
}