#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H
#include <memory>
#include <SFML\Graphics.hpp>
#include <string>
#include "MACROS.hpp"

class TextureLoader
{

private:
    sf::Texture black_pawn;
    sf::Texture black_bioshop;
    sf::Texture black_knight;
    sf::Texture black_rook;
    sf::Texture black_queen;
    sf::Texture black_king;

    sf::Texture white_pawn;
    sf::Texture white_bioshop;
    sf::Texture white_knight;
    sf::Texture white_rook;
    sf::Texture white_queen;
    sf::Texture white_king;

public:
    TextureLoader();
    ~TextureLoader();

    sf::Texture &getBlackPawnTexture();
    sf::Texture &getBlackBioshopTexture();
    sf::Texture &getBlackKnightTexture();
    sf::Texture &getBlackRookTexture();
    sf::Texture &getBlackQueenTexture();
    sf::Texture &getBlackKingTexture();

    sf::Texture &getWhitePawnTexture();
    sf::Texture &getWhiteBioshopTexture();
    sf::Texture &getWhiteKnightTexture();
    sf::Texture &getWhiteRookTexture();
    sf::Texture &getWhiteQueenTexture();
    sf::Texture &getWhiteKingTexture();
};

#endif