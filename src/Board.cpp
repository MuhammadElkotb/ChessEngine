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
    sf::Sprite sprite;

    

}