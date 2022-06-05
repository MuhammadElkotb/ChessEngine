#include "..\headers\Board.hpp"
#include <iostream>
#include "..\headers\Piece.hpp"
#include <memory>
#include "..\headers\TextureLoader.hpp"
#include "..\headers\MACROS.hpp"
#include "..\headers\Pawn.hpp"
#include "..\headers\Bioshop.hpp"
#include "..\headers\Rook.hpp"
#include "..\headers\Knight.hpp"
#include "..\headers\King.hpp"
#include "..\headers\Queen.hpp"

Board::Board()
{
    this->initBoard();
    this->initPieces();
    log("BEFORE");
    for (Piece *&piece : this->pieces)
    {
        this->positionPieceMap[piece->getCell()] = piece;
    }
    log("After");
}

Board::~Board()
{
    for (int i = 0; i < 32; i++)
    {
        delete (this->pieces[i]);
    }
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
            cell.cell_rect = cellRect;
            cell.default_colour = cellRect.getFillColor();
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
        this->pieces[i] = new Pawn;
        this->pieces[i]->setWhite(false);
        this->pieces[i]->setCell(this->getCellByPosition(1, pos++));
        this->pieces[i]->setSprite(sf::Sprite(this->texture_loader.getBlackPawnTexture()));
    }
    pos = 0;
    for (int i = 8; i < 16; i++)
    {
        this->pieces[i] = new Pawn;
        this->pieces[i]->setWhite(true);
        this->pieces[i]->setCell(this->getCellByPosition(6, pos++));
        this->pieces[i]->setSprite(sf::Sprite(this->texture_loader.getWhitePawnTexture()));
    }

    // init Black Pieces in their intial positions left to right
    int piece_ctr = 16;
    pos = 0;

    this->pieces[piece_ctr] = new Rook;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(0, pos++));
    this->pieces[piece_ctr]->setWhite(false);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getBlackRookTexture()));

    this->pieces[piece_ctr] = new Knight;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(0, pos++));
    this->pieces[piece_ctr]->setWhite(false);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getBlackKnightTexture()));

    this->pieces[piece_ctr] = new Bioshop;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(0, pos++));
    this->pieces[piece_ctr]->setWhite(false);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getBlackBioshopTexture()));

    this->pieces[piece_ctr] = new King;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(0, pos++));
    this->pieces[piece_ctr]->setWhite(false);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getBlackKingTexture()));

    this->pieces[piece_ctr] = new Queen;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(0, pos++));
    this->pieces[piece_ctr]->setWhite(false);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getBlackQueenTexture()));

    this->pieces[piece_ctr] = new Bioshop;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(0, pos++));
    this->pieces[piece_ctr]->setWhite(false);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getBlackBioshopTexture()));

    this->pieces[piece_ctr] = new Knight;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(0, pos++));
    this->pieces[piece_ctr]->setWhite(false);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getBlackKnightTexture()));

    this->pieces[piece_ctr] = new Rook;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(0, pos++));
    this->pieces[piece_ctr]->setWhite(false);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getBlackRookTexture()));

    pos = 0;

    // init White Pieces in their intial positions left to right

    this->pieces[piece_ctr] = new Rook;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(7, pos++));
    this->pieces[piece_ctr]->setWhite(true);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getWhiteRookTexture()));

    this->pieces[piece_ctr] = new Knight;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(7, pos++));
    this->pieces[piece_ctr]->setWhite(true);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getWhiteKnightTexture()));

    this->pieces[piece_ctr] = new Bioshop;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(7, pos++));
    this->pieces[piece_ctr]->setWhite(true);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getWhiteBioshopTexture()));

    this->pieces[piece_ctr] = new King;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(7, pos++));
    this->pieces[piece_ctr]->setWhite(true);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getWhiteKingTexture()));

    this->pieces[piece_ctr] = new Queen;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(7, pos++));
    this->pieces[piece_ctr]->setWhite(true);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getWhiteQueenTexture()));

    this->pieces[piece_ctr] = new Bioshop;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(7, pos++));
    this->pieces[piece_ctr]->setWhite(true);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getWhiteBioshopTexture()));

    this->pieces[piece_ctr] = new Knight;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(7, pos++));
    this->pieces[piece_ctr]->setWhite(true);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getWhiteKnightTexture()));

    this->pieces[piece_ctr] = new Rook;
    this->pieces[piece_ctr]->setCell(this->getCellByPosition(7, pos++));
    this->pieces[piece_ctr]->setWhite(true);
    this->pieces[piece_ctr++]->setSprite(sf::Sprite(this->texture_loader.getWhiteRookTexture()));
}

void Board::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            window.draw(this->cells[i][j].cell_rect);
        }
    }

    for (Piece *&piece : this->pieces)
    {
        if (!piece->isKilled())
            window.draw(piece->getSprite());
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

std::unordered_map<Cell *, Piece *> &Board::getPositionPieceMap()
{
    return this->positionPieceMap;
}