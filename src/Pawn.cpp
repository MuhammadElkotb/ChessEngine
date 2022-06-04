#include "..\headers\Pawn.hpp"
#include <set>
Pawn::Pawn() {}
Pawn::~Pawn() {}

std::set<std::pair<int, int>> Pawn::moveCells()
{
    std::set<std::pair<int, int>> move_cells;
    if (this->white)
    {
        move_cells.insert(std::pair<int, int>(this->cell->row - 1, this->cell->col));

        if (this->first_move)
        {
            move_cells.insert(std::pair<int, int>(this->cell->row - 2, this->cell->col));
        }
    }
    else
    {
        move_cells.insert(std::pair<int, int>(this->cell->row + 1, this->cell->col));

        if (this->first_move)
        {
            move_cells.insert(std::pair<int, int>(this->cell->row + 2, this->cell->col));
        }
    }

    return move_cells;
}