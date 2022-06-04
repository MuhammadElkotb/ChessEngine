#include "..\headers\Bioshop.hpp"

std::set<std::pair<int, int>> Bioshop::moveCells()
{

    std::set<std::pair<int, int>> move_cells;

    int row = this->cell->row;
    int col = this->cell->col;

    // moving down right
    while (row < 7 && col < 7)
    {
        row++;
        col++;
        move_cells.insert(std::pair<int, int>(row, col));
        }

    row = this->cell->row;
    col = this->cell->col;
    // moving left up
    while (row > 0 && col > 0)
    {
        row--;
        col--;
        move_cells.insert(std::pair<int, int>(row, col));
    }

    row = this->cell->row;
    col = this->cell->col;
    // movning right up
    while (row < 7 && col > 0)
    {
        row++;
        col--;
        move_cells.insert(std::pair<int, int>(row, col));
    }

    row = this->cell->row;
    col = this->cell->col;
    // moving left down
    while (col < 7 && row > 0)
    {
        row--;
        col++;
        move_cells.insert(std::pair<int, int>(row, col));
    }

    return move_cells;
}