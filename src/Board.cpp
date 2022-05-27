#include "..\headers\Board.hpp"
#include <iostream>
#include "..\headers\Piece.hpp"
#include <memory>
#include "..\headers\TextureLoader.hpp"
#define BLACK_BISHOP_TEXTURE "..\\assets\\black_bioshop.png"
Board::Board()
{
    this->initBoard();
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
            cell.x = i; cell.y = j;
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

    sprite.setTexture(this->texture_loader.loadBlackBioshopTexture(BLACK_BISHOP_TEXTURE));
    sprite.setPosition({this->cells[0][0].cellRect.getPosition().x + 15, this->cells[0][0].cellRect.getPosition().y + 7});
    sprite.setScale(0.08, 0.08);

    this->pieces[0].setSprite(sprite);


    
   
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

    window.draw(this->pieces[0].getSprite());

    

}