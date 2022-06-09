#include "..\headers\Controller.hpp"
#include "..\headers\King.hpp"

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
                if (board.getPieceByCell(cell) != NULL)
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

        if (board.getPieceByCell(move_cell) != NULL)
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
        this->recolorKing(board, piece);
        if (piece->isWhite())
            white_check = false;
        else
            black_check = false;

        this->whiteTurn = !this->whiteTurn;
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
                if (check_piece->isWhite())
                    white_check = true;
                else
                    black_check = true;
                return cell;
            }
            else
            {
                cell->cell_rect.setFillColor(cell->default_colour);
            }
        }
    }
    return NULL;
}

std::vector<std::pair<int, int>> Controller::nextMoveCheck(Board &board, Piece *piece, std::vector<std::pair<int, int>> &move_cells)
{
    std::vector<std::pair<int, int>> move_cell_ret;

    Piece *king;

    // look for your own king
    for (auto &kv : board.getPositionPieceMap())
    {
        if (kv.second->isWhite() == piece->isWhite())
        {
            if (kv.second->isKing())
            {
                king = kv.second;
                break;
            }
        }
    }
    Cell *real_cell = piece->getCell();

    for (const std::pair<int, int> &cell : move_cells)
    {
        bool found_check_cell = false;

        piece->setCell(board.getCellByPosition(cell.first, cell.second));
        board.getPositionPieceMap().erase(real_cell);

        bool found_piece = false;
        Piece *piece_cell = board.getPieceByCell(board.getCellByPosition(cell.first, cell.second));

        if (piece_cell != NULL)
        {
            board.getPositionPieceMap().erase(board.getCellByPosition(cell.first, cell.second));
        }
        else
        {
            board.getPositionPieceMap()[board.getCellByPosition(cell.first, cell.second)] = piece;
        }

        for (const auto &kv : board.getPositionPieceMap())
        {
            if (piece->isWhite() != kv.second->isWhite())
            {
                std::vector<std::pair<int, int>> move_cells_enemy = this->validateMove(board, kv.second);

                for (const std::pair<int, int> &cell_pos : move_cells_enemy)
                {
                    if (king->getCell() == board.getCellByPosition(cell_pos.first, cell_pos.second))
                    {
                        found_check_cell = true;
                        break;
                    }
                }
            }
            if (found_check_cell)
                break;
        }
        if (piece_cell != NULL)
            board.getPositionPieceMap()[board.getCellByPosition(cell.first, cell.second)] = piece_cell;
        else
        {
            board.getPositionPieceMap().erase(board.getCellByPosition(cell.first, cell.second));
        }
        board.getPositionPieceMap()[real_cell] = piece;
        if (!found_check_cell)
            move_cell_ret.push_back(std::pair<int, int>(cell.first, cell.second));
        piece->setCell(real_cell);
    }
    piece->setCell(real_cell);
    return move_cell_ret;
}

void Controller::recolorKing(Board &board, Piece *piece)
{
    std::unordered_map<Cell *, Piece *> cell_piece_map = board.getPositionPieceMap();

    for (auto &kv : cell_piece_map)
    {
        if (piece->isWhite() == kv.second->isWhite())
        {
            if (kv.second->isKing())
            {
                kv.second->getCell()->cell_rect.setFillColor(kv.second->getCell()->default_colour);
                break;
            }
        }
    }
}

/*bool Controller::checkWin(Board &board, bool white)
{
    bool win = true;
    for (auto &kv : board.getPositionPieceMap())
    {

        if (kv.second->isWhite() != white)
        {
            std::vector<std::pair<int, int>> move_cells = this->validateMove(board, kv.second);
            std::vector<std::pair<int, int>> move_cells_after_check = this->nextMoveCheck(board, kv.second, move_cells);

            if (move_cells_after_check.size() > 0)
                return false;
        }
    }
    return win;
}*/

sf::Sound &Controller::getMoveSound()
{
    return this->move_sound;
}
