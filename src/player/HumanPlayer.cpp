/**
 * @file HumanPlayer.cpp
 * @brief Implementation file for human player class.
 */

#include "../../include/player/HumanPlayer.h"
#include "../../include/common/AppFunctions.h"


int HumanPlayer::get_next_move(const HexBoard &board) const {
    int row = 0, col = 0;

    while (true) {
        print_message("Select your: ");

        row = get_input<int>("Row to play: ");
        if (row < 1 || row > board.tiles_per_side) {
            print_error("Invalid row value!");
            continue;
        }

        col = get_input<int>("Col to play: ");
        if (col < 1 || col > board.tiles_per_side) {
            print_error("Invalid col value!");
            continue;
        }

        break;
    }
    return (row - 1) * board.tiles_per_side + col - 1;
}