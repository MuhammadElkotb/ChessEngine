#include "..\headers\Board.hpp"
#include <iostream>
#include "..\headers\Piece.hpp"
#include <memory>
#include "..\headers\TextureLoader.hpp"

#define BLACK_BISHOP_TEXTURE "..\\assets\\black_bioshop.png"
#define BLACK_KNIGHT_TEXTURE "..\\assets\\black_knight.png"
#define BLACK_ROOK_TEXTURE "..\\assets\\black_rook.png"
#define BLACK_KING_TEXTURE "..\\assets\\black_king.png"
#define BLACK_QUEEN_TEXTURE "..\\assets\\black_queen.png"
#define BLACK_PAWN_TEXTURE "..\\assets\\black_pawn.png"

#define WHITE_BISHOP_TEXTURE "..\\assets\\white_bioshop.png"
#define WHITE_KNIGHT_TEXTURE "..\\assets\\white_knight.png"
#define WHITE_ROOK_TEXTURE "..\\assets\\white_rook.png"
#define WHITE_KING_TEXTURE "..\\assets\\white_king.png"
#define WHITE_QUEEN_TEXTURE "..\\assets\\white_queen.png"
#define WHITE_PAWN_TEXTURE "..\\assets\\white_pawn.png"

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
        blackPawn.setSprite(sf::Sprite(this->texture_loader.loadBlackPawnTexture(BLACK_PAWN_TEXTURE)));
        this->piecesMap["bP" + std::to_string(i)] = blackPawn;
        Piece whitePawn;
        whitePawn.setCell(this->getCellByPosition(6, i));
        whitePawn.setSprite(sf::Sprite(this->texture_loader.loadWhitePawnTexture(WHITE_PAWN_TEXTURE)));
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

    blackRook1.setSprite(sf::Sprite(this->texture_loader.loadBlackRookTexture(BLACK_ROOK_TEXTURE)));
    blackKnight1.setSprite(sf::Sprite(this->texture_loader.loadBlackKnightTexture(BLACK_BISHOP_TEXTURE)));
    blackBioshop1.setSprite(sf::Sprite(this->texture_loader.loadBlackBioshopTexture(BLACK_KNIGHT_TEXTURE)));
    blackKing.setSprite(sf::Sprite(this->texture_loader.loadBlackKingTexture(BLACK_KING_TEXTURE)));
    blackQueen.setSprite(sf::Sprite(this->texture_loader.loadBlackQueenTexture(BLACK_QUEEN_TEXTURE)));
    blackBioshop2.setSprite(sf::Sprite(this->texture_loader.loadBlackBioshopTexture(BLACK_KNIGHT_TEXTURE)));
    blackKnight2.setSprite(sf::Sprite(this->texture_loader.loadBlackKnightTexture(BLACK_BISHOP_TEXTURE)));
    blackRook2.setSprite(sf::Sprite(this->texture_loader.loadBlackRookTexture(BLACK_ROOK_TEXTURE)));

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

    whiteRook1.setSprite(sf::Sprite(this->texture_loader.loadWhiteRookTexture(WHITE_ROOK_TEXTURE)));
    whiteKnight1.setSprite(sf::Sprite(this->texture_loader.loadWhiteKnightTexture(WHITE_BISHOP_TEXTURE)));
    whiteBioshop1.setSprite(sf::Sprite(this->texture_loader.loadWhiteBioshopTexture(WHITE_KNIGHT_TEXTURE)));
    whiteKing.setSprite(sf::Sprite(this->texture_loader.loadWhiteKingTexture(WHITE_KING_TEXTURE)));
    whiteQueen.setSprite(sf::Sprite(this->texture_loader.loadWhiteQueenTexture(WHITE_QUEEN_TEXTURE)));
    whiteBioshop2.setSprite(sf::Sprite(this->texture_loader.loadWhiteBioshopTexture(WHITE_KNIGHT_TEXTURE)));
    whiteKnight2.setSprite(sf::Sprite(this->texture_loader.loadWhiteKnightTexture(WHITE_BISHOP_TEXTURE)));
    whiteRook2.setSprite(sf::Sprite(this->texture_loader.loadWhiteRookTexture(WHITE_ROOK_TEXTURE)));

    this->piecesMap["wR1"] = whiteRook1;
    this->piecesMap["wN1"] = whiteKnight1;
    this->piecesMap["wB1"] = whiteBioshop1;
    this->piecesMap["wK"] = whiteKing;
    this->piecesMap["wQ"] = whiteQueen;
    this->piecesMap["wB2"] = whiteBioshop2;
    this->piecesMap["wN2"] = whiteKnight2;
    this->piecesMap["wR2"] = whiteRook2;
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