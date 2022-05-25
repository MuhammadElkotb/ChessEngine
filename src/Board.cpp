#include "..\headers\Board.hpp"
#include <iostream>
#include "..\headers\Piece.hpp"
#include <memory>
Board::Board()
{
    this->initBoard();
    this->tempTexture = std::make_unique<sf::Texture>();
    this->tempTexture->loadFromFile("..\\assets\\w_pawn_png_shadow_1024px.png");
    this->initPieces();
    

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
    sf::Sprite sprite;
    sprite.setTexture(*this->tempTexture);
    sprite.setScale(0.1, 0.1);
    sprite.setPosition(60, 60);
    this->tempSprite = sprite;
}

Board::~Board()
{
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
    
    window.draw(this->tempSprite);

}