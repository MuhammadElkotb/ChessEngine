#include "..\headers\Queen.hpp"

std::vector<std::vector<std::pair<int, int>>> Queen::moveCells()
{
    std::vector<std::vector<std::pair<int, int>>> move_cells(8, std::vector<std::pair<int, int>>());

    int row = this->cell->row;
    int col = this->cell->col;

    // moving down right
    while (row < 7 && col < 7)
    {
        row++;
        col++;
        move_cells[0].push_back(std::pair<int, int>(row, col));
    }


    row = this->cell->row;
    col = this->cell->col;
    // moving left up
    while (row > 0 && col > 0)
    {
        row--;
        col--;
        move_cells[1].push_back(std::pair<int, int>(row, col));
    }

    row = this->cell->row;
    col = this->cell->col;
    // movning right up
    while (row < 7 && col > 0)
    {
        row++;
        col--;
        move_cells[2].push_back(std::pair<int, int>(row, col));
    }

    row = this->cell->row;
    col = this->cell->col;
    // moving left down
    while (col < 7 && row > 0)
    {
        row--;
        col++;
        move_cells[3].push_back(std::pair<int, int>(row, col));
    }

    row = this->cell->row;
    col = this->cell->col;
    // moving right
    while (col < 7)
    {
        col++;
        move_cells[4].push_back(std::pair<int, int>(row, col));
    }


    row = this->cell->row;
    col = this->cell->col;
    // moving left
    while (col > 0)
    {
        col--;
        move_cells[5].push_back(std::pair<int, int>(row, col));
    }

    row = this->cell->row;
    col = this->cell->col;
    // movning up
    while (row > 0)
    {
        row--;
        move_cells[6].push_back(std::pair<int, int>(row, col));
    }

    row = this->cell->row;
    col = this->cell->col;
    // moving down
    while (row < 7)
    {
        row++;
        move_cells[7].push_back(std::pair<int, int>(row, col));
    }

    return move_cells;
}