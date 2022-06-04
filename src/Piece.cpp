#include "..\headers\Piece.hpp"
#include "..\headers\MACROS.hpp"
Piece::Piece()
{
    this->killed = false;
}

Piece::~Piece()
{
}

void Piece::setSprite(sf::Sprite sprite)
{

    this->sprite = sprite;
    this->sprite.setScale(0.07, 0.07);
    this->sprite.setPosition({this->cell->cell_rect.getPosition().x + 17, this->cell->cell_rect.getPosition().y + 15});
}

void Piece::move(Cell *cell)
{
    this->setCell(cell);
    this->sprite.setPosition({this->cell->cell_rect.getPosition().x + 17, this->cell->cell_rect.getPosition().y + 15});
}

sf::Sprite &Piece::getSprite()
{
    return this->sprite;
}

Cell *Piece::getCell()
{
    return this->cell;
}

void Piece::setCell(Cell *cell)
{
    this->cell = cell;
}

void Piece::kill()
{
    this->cell = nullptr;
    this->killed = true;
}

bool Piece::isKilled()
{
    return this->killed;
}

bool Piece::isFirstMove()
{
    return this->first_move;
}
bool Piece::isWhite()
{
    return this->white;
}
void Piece::setFirstMove(bool first_move)
{
    this->first_move = first_move;
}
void Piece::setWhite(bool white)
{
    this->white = white;
}
