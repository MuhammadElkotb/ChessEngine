#ifndef PIECE_H
#define PIECE_H
#include <SFML\Graphics.hpp>
class Piece {


private:
    sf::Sprite sprite;
    sf::Texture texture;
public:
    Piece();
    ~Piece();
    
};

#endif