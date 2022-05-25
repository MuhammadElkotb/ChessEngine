#include "..\headers\Piece.hpp"


Piece::Piece(){

}

Piece::~Piece(){
    
}




void Piece::setTexture(sf::Texture texture){
    this->texture = texture;
}
void Piece::setSprite(sf::Sprite sprite){
    this->sprite = sprite;
}

sf::Sprite Piece::getSprite(){
    return this->sprite;
}

sf::Texture Piece::getTexture(){
    return this->texture;
}
