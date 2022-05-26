#include "..\headers\TextureLoader.hpp"

TextureLoader::TextureLoader()
{
    this->black_pawn = std::make_unique<sf::Texture>();
    this->black_bioshop = std::make_unique<sf::Texture>();
    this->black_knight = std::make_unique<sf::Texture>();
    this->black_rook = std::make_unique<sf::Texture>();
    this->black_queen = std::make_unique<sf::Texture>();
    this->black_king = std::make_unique<sf::Texture>();

    this->white_pawn = std::make_unique<sf::Texture>();
    this->white_bioshop = std::make_unique<sf::Texture>();
    this->white_knight = std::make_unique<sf::Texture>();
    this->white_rook = std::make_unique<sf::Texture>();
    this->white_queen = std::make_unique<sf::Texture>();
    this->white_king = std::make_unique<sf::Texture>();
}

TextureLoader::~TextureLoader()
{
}

std::unique_ptr<sf::Texture> TextureLoader::getBlackBioshopTexture(){
    return std::move(this->black_bioshop);
}

sf::Texture TextureLoader::loadBlackPawnTexture(std::string path)
{
    (*this->black_pawn).loadFromFile(path);
    return *this->black_pawn; 
}

sf::Texture TextureLoader::loadBlackBioshopTexture(std::string path)
{
    (*this->black_bioshop).loadFromFile(path);
    return *this->black_bioshop; 
}

sf::Texture TextureLoader::loadBlackKnightTexture(std::string path)
{
    (*this->black_knight).loadFromFile(path);
    return *this->black_knight; 
}

sf::Texture TextureLoader::loadBlackRookTexture(std::string path)
{
    (*this->black_rook).loadFromFile(path);
    return *this->black_rook; 
}

sf::Texture TextureLoader::loadBlackQueenTexture(std::string path)
{
    (*this->black_queen).loadFromFile(path);
    return *this->black_queen; 
}

sf::Texture TextureLoader::loadBlackKingTexture(std::string path)
{
    (*this->black_king).loadFromFile(path);
    return *this->black_king; 
}


sf::Texture TextureLoader::loadWhitePawnTexture(std::string path)
{
    (*this->white_pawn).loadFromFile(path);
    return *this->white_pawn; 
}

sf::Texture TextureLoader::loadWhiteBioshopTexture(std::string path)
{
    (*this->white_bioshop).loadFromFile(path);
    return *this->white_bioshop; 
}

sf::Texture TextureLoader::loadWhiteKnightTexture(std::string path)
{
    (*this->white_knight).loadFromFile(path);
    return *this->white_knight; 
}

sf::Texture TextureLoader::loadWhiteRookTexture(std::string path)
{
    (*this->white_rook).loadFromFile(path);
    return *this->white_rook; 
}

sf::Texture TextureLoader::loadWhiteQueenTexture(std::string path)
{
    (*this->white_queen).loadFromFile(path);
    return *this->white_queen; 
}

sf::Texture TextureLoader::loadWhiteKingTexture(std::string path)
{
    (*this->white_king).loadFromFile(path);
    return *this->white_king; 
}