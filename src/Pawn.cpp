#include "..\headers\Pawn.hpp"
#include <set>

Pawn::Pawn() {}
Pawn::~Pawn() {}

std::vector<std::vector<std::pair<int, int>>> Pawn::moveCells()
{
    std::vector<std::vector<std::pair<int, int>>> move_cells;
    move_cells.push_back(std::vector<std::pair<int, int>>());
    if (this->white)
    {
        move_cells[0].push_back(std::pair<int, int>(this->cell->row - 1, this->cell->col));

        if (this->first_move)
        {
            move_cells[0].push_back(std::pair<int, int>(this->cell->row - 2, this->cell->col));
        }
    }
    else
    {
        move_cells[0].push_back(std::pair<int, int>(this->cell->row + 1, this->cell->col));

        if (this->first_move)
        {
            move_cells[0].push_back(std::pair<int, int>(this->cell->row + 2, this->cell->col));
        }
    }

    return move_cells;
}