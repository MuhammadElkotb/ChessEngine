#ifndef CELL_H
#define CELL_H
#include <SFML\Graphics.hpp>

typedef struct Cell {
    sf::RectangleShape cellRect;
    int x;
    int y;
} Cell;


#endif
