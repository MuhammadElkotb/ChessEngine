#include "..\headers\Piece.hpp"


Piece::Piece(){

}

Piece::~Piece(){
    
}


void Piece::setSprite(sf::Sprite sprite){

    this->sprite = sprite;
    this->sprite.setScale(0.07, 0.07);
    this->sprite.setPosition({this->cell.cellRect.getPosition().x + 17, this->cell.cellRect.getPosition().y + 15});
}

sf::Sprite& Piece::getSprite(){
    return this->sprite;
}


Cell& Piece::getCell(){
    return this->cell;
}

void Piece::setCell(Cell& cell){
    this->cell = cell;
}

