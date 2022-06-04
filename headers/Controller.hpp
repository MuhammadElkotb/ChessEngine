#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Board.hpp"

class Controller
{

private:
    Board *board;

public:
    void validateMove();
};

#endif