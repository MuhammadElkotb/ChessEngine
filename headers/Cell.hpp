#ifndef CELL_H
#define CELL_H
#include <SFML\Graphics.hpp>


struct Cell
{
    sf::RectangleShape cell_rect;
    sf::Color default_colour;
    int row;
    int col;
};

#endif
