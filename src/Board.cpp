#include "..\headers\Board.hpp"
#include <iostream>
Board::Board()
{
    this->initBoard();
}

void Board::initBoard()
{
    bool even = true;
    float posX = this->originX;
    float posY = this->originY;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            sf::RectangleShape cell(sf::Vector2f(100, 100));
            if(even) cell.setFillColor({238,238,210});
            else cell.setFillColor({118,150,86});
            cell.setPosition({posX, posY});
            posX += 100;
            this->cells[i][j] = cell;
            if(j != 7) even = !even;
        }
        posY += 100;
        posX = this->originX;
    }
}

Board::~Board()
{
}

void Board::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            window.draw(this->cells[i][j]);
        }
    }
    
}