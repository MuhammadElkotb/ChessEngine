#include "..\headers\Bioshop.hpp"
std::vector<std::vector<std::pair<int, int>>> Bioshop::moveCells()
{

    std::vector<std::vector<std::pair<int, int>>> move_cells;

    int row = this->cell->row;
    int col = this->cell->col;

    // moving down right
    move_cells.push_back(std::vector<std::pair<int, int>>());
    while (row < 7 && col < 7)
    {
        row++;
        col++;
        move_cells[0].push_back(std::pair<int, int>(row, col));
    }

    move_cells.push_back(std::vector<std::pair<int, int>>());

    row = this->cell->row;
    col = this->cell->col;
    // moving left up
    while (row > 0 && col > 0)
    {
        row--;
        col--;
        move_cells[1].push_back(std::pair<int, int>(row, col));
    }
    move_cells.push_back(std::vector<std::pair<int, int>>());

    row = this->cell->row;
    col = this->cell->col;
    // movning right up
    while (row < 7 && col > 0)
    {
        row++;
        col--;
        move_cells[2].push_back(std::pair<int, int>(row, col));
    }
    move_cells.push_back(std::vector<std::pair<int, int>>());

    row = this->cell->row;
    col = this->cell->col;
    // moving left down
    while (col < 7 && row > 0)
    {
        row--;
        col++;
        move_cells[3].push_back(std::pair<int, int>(row, col));
    }

  
    return move_cells;
}