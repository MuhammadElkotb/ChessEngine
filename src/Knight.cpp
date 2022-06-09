#include "..\headers\Knight.hpp"

std::vector<std::vector<std::pair<int, int>>> Knight::moveCells()
{

   std::vector<std::vector<std::pair<int, int>>> move_cells(8, std::vector<std::pair<int, int>>());

   int row = this->cell->row;
   int col = this->cell->col;

   // moving up left
   if (row > 0 && col > 0)
   {
      move_cells[0].push_back(std::pair<int, int>(row - 1, col - 2));
      move_cells[1].push_back(std::pair<int, int>(row - 2, col - 1));
   }

   // moving right up
   if (row > 0 && col < 7)
   {
      move_cells[2].push_back(std::pair<int, int>(row - 2, col + 1));
      move_cells[3].push_back(std::pair<int, int>(row - 1, col + 2));
   }

   // moving right down
   if (row < 7 && col < 7)
   {
      move_cells[4].push_back(std::pair<int, int>(row + 1, col + 2));
      move_cells[5].push_back(std::pair<int, int>(row + 2, col + 1));
   }

   // moving left down
   if (row < 7 && col > 0)
   {
      move_cells[6].push_back(std::pair<int, int>(row + 2, col - 1));
      move_cells[7].push_back(std::pair<int, int>(row + 1, col - 2));
   }

   return move_cells;
}