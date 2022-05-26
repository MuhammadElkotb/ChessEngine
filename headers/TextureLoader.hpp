#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H
#include <memory>
#include <SFML\Graphics.hpp>
#include <string>

class TextureLoader {

private:
    std::unique_ptr<sf::Texture> black_pawn;
    std::unique_ptr<sf::Texture> black_bioshop;
    std::unique_ptr<sf::Texture> black_knight;
    std::unique_ptr<sf::Texture> black_rook;
    std::unique_ptr<sf::Texture> black_queen;
    std::unique_ptr<sf::Texture> black_king;

    std::unique_ptr<sf::Texture> white_pawn;
    std::unique_ptr<sf::Texture> white_bioshop;
    std::unique_ptr<sf::Texture> white_knight;
    std::unique_ptr<sf::Texture> white_rook;
    std::unique_ptr<sf::Texture> white_queen;
    std::unique_ptr<sf::Texture> white_king;


public:
    TextureLoader();
    ~TextureLoader();
    std::unique_ptr<sf::Texture> getBlackPawnTexture();
    std::unique_ptr<sf::Texture> getBlackBioshopTexture();
    std::unique_ptr<sf::Texture> getBlackKnightTexture();
    std::unique_ptr<sf::Texture> getBlackRookTexture();
    std::unique_ptr<sf::Texture> getBlackQueenTexture();
    std::unique_ptr<sf::Texture> getBlackKingTexture();



    std::unique_ptr<sf::Texture> getWhitePawnTexture();
    std::unique_ptr<sf::Texture> getWhiteBioshopTexture();
    std::unique_ptr<sf::Texture> getWhiteKnightTexture();
    std::unique_ptr<sf::Texture> getWhiteRookTexture();
    std::unique_ptr<sf::Texture> getWhiteQueenTexture();
    std::unique_ptr<sf::Texture> getWhiteKingTexture();




    sf::Texture loadBlackPawnTexture(std::string path);
    sf::Texture loadBlackBioshopTexture(std::string path);
    sf::Texture loadBlackKnightTexture(std::string path);
    sf::Texture loadBlackRookTexture(std::string path);
    sf::Texture loadBlackQueenTexture(std::string path);
    sf::Texture loadBlackKingTexture(std::string path);

    sf::Texture loadWhitePawnTexture(std::string path);
    sf::Texture loadWhiteBioshopTexture(std::string path);
    sf::Texture loadWhiteKnightTexture(std::string path);
    sf::Texture loadWhiteRookTexture(std::string path);
    sf::Texture loadWhiteQueenTexture(std::string path);
    sf::Texture loadWhiteKingTexture(std::string path);


    

};




#endif