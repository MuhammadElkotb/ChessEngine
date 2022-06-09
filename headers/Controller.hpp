#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Board.hpp"
#include <vector>
#include <utility>
#include <SFML\Audio.hpp>
#include "MACROS.hpp"

class Controller
{
private:
    sf::SoundBuffer move_sound_buffer;
    sf::SoundBuffer capture_sound_buffer;
    sf::SoundBuffer illegal_sound_buffer;

    sf::Sound move_sound;
    sf::Sound capture_sound;
    sf::Sound illegal_sound;

    bool black_check = false;
    bool white_check = false;

public:
    Controller();
    ~Controller();
    std::vector<std::pair<int, int>> validateMove(Board &board, Piece *piece);
    void drawMoveCells(Board &board, std::vector<std::pair<int, int>> &move_cells);
    void resetColor(Board &board, std::vector<std::pair<int, int>> &move_cells);
    void movePiece(Board &board, Piece *piece, std::pair<int, int> cell, std::vector<std::pair<int, int>> &move_cells);
    std::vector<std::pair<int, int>> nextMoveCheck(Board &board, Piece *piece, std::vector<std::pair<int, int>> &move_cells);
    Cell *checkCheckMate(Board &board, Piece *piece, std::vector<std::pair<int, int>> move_cells);
    void recolorKing(Board &board, Piece *piece);
    bool checkWin(Board &board, bool white);
    sf::Sound &getMoveSound();

    bool whiteTurn = true;
};

#endif