#include "..\headers\TextureLoader.hpp"
#include <iostream>
TextureLoader::TextureLoader()
{
    
 
    this->black_pawn.loadFromFile(BLACK_PAWN_TEXTURE);
    this->black_pawn.setSmooth(true);

    this->black_bioshop.loadFromFile(BLACK_BISHOP_TEXTURE);
    this->black_bioshop.setSmooth(true);

    this->black_knight.loadFromFile(BLACK_KNIGHT_TEXTURE);
    this->black_knight.setSmooth(true);

    this->black_rook.loadFromFile(BLACK_ROOK_TEXTURE);
    this->black_rook.setSmooth(true);

    this->black_queen.loadFromFile(BLACK_QUEEN_TEXTURE);
    this->black_queen.setSmooth(true);

    this->black_king.loadFromFile(BLACK_KING_TEXTURE);
    this->black_king.setSmooth(true);

    this->white_pawn.loadFromFile(WHITE_PAWN_TEXTURE);
    this->white_pawn.setSmooth(true);

    this->white_bioshop.loadFromFile(WHITE_BISHOP_TEXTURE);
    this->white_bioshop.setSmooth(true);

    this->white_knight.loadFromFile(WHITE_KNIGHT_TEXTURE);
    this->white_knight.setSmooth(true);

    this->white_rook.loadFromFile(WHITE_ROOK_TEXTURE);
    this->white_rook.setSmooth(true);

    this->white_queen.loadFromFile(WHITE_QUEEN_TEXTURE);
    this->white_queen.setSmooth(true);

    this->white_king.loadFromFile(WHITE_KING_TEXTURE);
    this->white_king.setSmooth(true);
}

TextureLoader::~TextureLoader()
{
}

sf::Texture &TextureLoader::getBlackPawnTexture()
{
    return this->black_pawn;
}

sf::Texture &TextureLoader::getBlackBioshopTexture()
{
    return this->black_bioshop;
}

sf::Texture &TextureLoader::getBlackKnightTexture()
{
    return this->black_knight;
}


sf::Texture &TextureLoader::getBlackRookTexture()
{
    return this->black_rook;
}

sf::Texture &TextureLoader::getBlackQueenTexture()
{
    return this->black_queen;
}

sf::Texture &TextureLoader::getBlackKingTexture()
{
    return this->black_king;
}

sf::Texture &TextureLoader::getWhitePawnTexture()
{
    return this->white_pawn;
}

sf::Texture &TextureLoader::getWhiteBioshopTexture()
{
    return this->white_bioshop;
}

sf::Texture &TextureLoader::getWhiteKnightTexture()
{
    return this->white_knight;
}

sf::Texture &TextureLoader::getWhiteRookTexture()
{
    return this->white_rook;
}

sf::Texture &TextureLoader::getWhiteQueenTexture()
{
    return this->white_queen;
}

sf::Texture &TextureLoader::getWhiteKingTexture()
{
    return this->white_king;
}