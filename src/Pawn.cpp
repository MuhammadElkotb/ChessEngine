#include "..\headers\Pawn.hpp"
#include <set>

Pawn::Pawn() {}
Pawn::~Pawn() {}

std::vector<std::pair<int, int>> Pawn::moveCells()
{
    std::vector<std::pair<int, int>> move_cells;
    if (this->white)
    {
        move_cells.push_back(std::pair<int, int>(this->cell->row - 1, this->cell->col));

        if (this->first_move)
        {
            move_cells.push_back(std::pair<int, int>(this->cell->row - 2, this->cell->col));
        }
    }
    else
    {
        move_cells.push_back(std::pair<int, int>(this->cell->row + 1, this->cell->col));

        if (this->first_move)
        {
            move_cells.push_back(std::pair<int, int>(this->cell->row + 2, this->cell->col));
        }
    }

    return move_cells;
}