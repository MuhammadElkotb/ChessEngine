#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H
#include <memory>
#include <SFML\Graphics.hpp>
#include <string>
#define BLACK_BISHOP_TEXTURE "..\\assets\\black_bioshop.png"
#define BLACK_KNIGHT_TEXTURE "..\\assets\\black_knight.png"
#define BLACK_ROOK_TEXTURE "..\\assets\\black_rook.png"
#define BLACK_KING_TEXTURE "..\\assets\\black_king.png"
#define BLACK_QUEEN_TEXTURE "..\\assets\\black_queen.png"
#define BLACK_PAWN_TEXTURE "..\\assets\\black_pawn.png"

#define WHITE_BISHOP_TEXTURE "..\\assets\\white_bioshop.png"
#define WHITE_KNIGHT_TEXTURE "..\\assets\\white_knight.png"
#define WHITE_ROOK_TEXTURE "..\\assets\\white_rook.png"
#define WHITE_KING_TEXTURE "..\\assets\\white_king.png"
#define WHITE_QUEEN_TEXTURE "..\\assets\\white_queen.png"
#define WHITE_PAWN_TEXTURE "..\\assets\\white_pawn.png"

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