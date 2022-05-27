#include "..\headers\Piece.hpp"


Piece::Piece(){

}

Piece::~Piece(){
    
}


void Piece::setSprite(sf::Sprite sprite){
    this->sprite = sprite;
}

sf::Sprite Piece::getSprite(){
    return this->sprite;
}

