#include "..\headers\Pawn.hpp"
#include <set>

Pawn::Pawn() {}
Pawn::~Pawn() {}

std::vector<std::vector<std::pair<int, int>>> Pawn::moveCells()
{
    int row = this->cell->row;
    int col = this->cell->col;

    std::vector<std::vector<std::pair<int, int>>> move_cells(3, std::vector<std::pair<int, int>>());
    if (this->white)
    {
        move_cells[0].push_back(std::pair<int, int>(row - 1, col));

        if (this->first_move)
        {
            move_cells[0].push_back(std::pair<int, int>(row - 2, col));
        }
        if(row > 0 && col > 0) move_cells[1].push_back(std::pair<int, int>(row - 1, col - 1));
        if(row > 0 && col < 7) move_cells[2].push_back(std::pair<int, int>(row - 1, col + 1));
    }
    else
    {
        move_cells[0].push_back(std::pair<int, int>(row + 1, col));

        if (this->first_move)
        {
            move_cells[0].push_back(std::pair<int, int>(row + 2, col));
        }
        if(row < 7 && col < 7) move_cells[1].push_back(std::pair<int, int>(row + 1, col + 1));
        if(row < 7 && col > 0) move_cells[2].push_back(std::pair<int, int>(row + 1, col - 1));
    }

    return move_cells;
}