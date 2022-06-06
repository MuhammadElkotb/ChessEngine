#include "..\headers\Controller.hpp"
#include <vector>
#include <utility>
Controller::Controller()
{

    this->move_sound_buffer.loadFromFile(MOVE_SOUND);
    this->capture_sound_buffer.loadFromFile(CAPTURE_SOUND);
    this->illegal_sound_buffer.loadFromFile(ILLEGAL_SOUND);

    this->move_sound.setBuffer(this->move_sound_buffer);
    this->capture_sound.setBuffer(this->capture_sound_buffer);
    this->illegal_sound.setBuffer(this->illegal_sound_buffer);
}
Controller::~Controller()
{
}

std::vector<std::pair<int, int>> Controller::validateMove(Board &board, Piece *piece)
{
    std::vector<std::vector<std::pair<int, int>>> move_cells = piece->moveCells();
    std::vector<std::pair<int, int>> empty_move_cells;

    int move_index = 0;
    for (auto &v : move_cells)
    {
        for (auto &kv : v)
        {

            // check board boundries
            if (kv.first >= 0 && kv.first < 8 && kv.second >= 0 && kv.second < 8)
            {

                Cell *cell = board.getCellByPosition(kv.first, kv.second);

                // check if available move_cells has pieces or no, if yes then -->>
                if (board.getPositionPieceMap().find(cell) != board.getPositionPieceMap().end())
                {
                    if (piece->isPawn() && move_index == 0)
                        break;
                    if (board.getPositionPieceMap()[cell]->isWhite() != piece->isWhite())
                    {
                        empty_move_cells.push_back(kv);
                    }
                    break;
                }
                else
                {
                    if (piece->isPawn() && move_index > 0)
                    {
                        break;
                    }
                }

                empty_move_cells.push_back(kv);
            }
        }
        move_index++;
    }

    return empty_move_cells;
}

void Controller::drawMoveCells(Board &board, std::vector<std::pair<int, int>> &move_cells)
{

    for (auto &kv : move_cells)
    {
        Cell *cell = board.getCellByPosition(kv.first, kv.second);
        sf::Color color({147, 212, 166, 255});
        cell->cell_rect.setFillColor(color);
    }
}

void Controller::resetColor(Board &board, std::vector<std::pair<int, int>> &move_cells)
{
    for (auto &kv : move_cells)
    {
        board.getCellByPosition(kv.first, kv.second)->cell_rect.setFillColor(board.getCellByPosition(kv.first, kv.second)->default_colour);
    }
}

void Controller::movePiece(Board &board, Piece *piece, std::pair<int, int> cell, std::vector<std::pair<int, int>> &move_cells)
{

    if (std::find(move_cells.begin(), move_cells.end(), cell) != move_cells.end())
    {
        bool capture = false;
        Cell *move_cell = board.getCellByPosition(cell.first, cell.second);

        if (board.getPositionPieceMap().find(move_cell) != board.getPositionPieceMap().end())
        {
            if (board.getPositionPieceMap()[move_cell]->isWhite() != piece->isWhite())
            {
                Piece *eaten_piece = board.getPositionPieceMap()[move_cell];
                eaten_piece->kill();
                capture = true;
                this->capture_sound.play();
            }
        }

        board.getPositionPieceMap().erase(board.getCellByPosition(piece->getCell()->row, piece->getCell()->col));

        piece->move(move_cell);
        piece->setFirstMove(false);
        board.getPositionPieceMap()[move_cell] = piece;
        Cell *check_cell = this->checkCheckMate(board, piece, validateMove(board, piece));
        if (check_cell != NULL)
        {
            check_cell->cell_rect.setFillColor(sf::Color::Red);
        }
        if (!capture)
        {
            this->move_sound.play();
        }
    }
    else
    {
        piece->move(piece->getCell());
        this->illegal_sound.play();
    }
}

Cell *Controller::checkCheckMate(Board &board, Piece *piece, std::vector<std::pair<int, int>> move_cells)
{

    for (auto &kv : move_cells)
    {
        Cell *cell = board.getCellByPosition(kv.first, kv.second);
        if (board.getPositionPieceMap().find(cell) != board.getPositionPieceMap().end())
        {
            Piece *check_piece = board.getPositionPieceMap()[cell];
            if (check_piece->isKing() && (piece->isWhite() != check_piece->isWhite()))
            {
                return cell;
            }
            else
                cell->cell_rect.setFillColor(cell->default_colour);
        }
    }
    return NULL;
}

sf::Sound &Controller::getMoveSound()
{
    return this->move_sound;
}
