/**
 *  @file GameSettings.cpp
 *  @brief Contains game configuration functions
 */

#include "../../include/game/GameSettings.h"
#include "../../include/common/AppFunctions.h"

int GameSettings::board_size = 11;
PlayingSide GameSettings::player_side = PlayingSide::HORIZONTAL;
int GameSettings::ai_samples_per_move = 100;

void GameSettings::configure_game() {
    std::string title = "Game configuration menu";

    while (true) {
        clear_console();
        print_menu_title(title);
        print_menu_option("1. Set board size (Current: " + std::to_string(board_size) + " tiles per side)");
        print_menu_option("2. Set player side (Current: " + PlayingSideHandler::to_string(player_side) + ")");
        print_menu_option(
                "3. Set AI difficulty (Current: " + std::to_string(ai_samples_per_move) + " samples per move)");
        print_menu_option("0. Back");
        print_menu_title_sep(title.size());

        char option = get_input<char>("Option:");

        switch (option) {
            case '1':
                configure_board_size();
                break;
            case '2':
                configure_playing_side();
                break;
            case '3':
                configure_AI_difficulty();
                break;
            case '0':
                return;
            default:
                print_error("Invalid option!");
                break;
        }
    }
};

void GameSettings::configure_board_size() {
    int size;
    std::string title = "Board size configuration";

    while (true) {
        clear_console();
        print_menu_title(title);
        print_menu_option("Enter the board size between 3 and 11 tiles");
        print_menu_title_sep(title.size());
        size = get_input<int>("Option:");

        if (size < 3 || size > 11) {
            print_error("Invalid board size!");
            continue;
        }
        break;
    }
    board_size = size;
}

void GameSettings::configure_AI_difficulty() {
    char difficulty;
    std::string title = "AI difficulty configuration";

    while (true) {
        clear_console();
        print_menu_title(title);
        print_menu_option("1. Easy mode (100 samples per move)");
        print_menu_option("2. Standard mode (200 samples per move)");
        print_menu_option("3. Hard mode (500 samples per move)");
        print_menu_option("4. Professional mode (1000 samples per move)");
        print_menu_option("0. Back");
        print_menu_title_sep(static_cast<int>(title.size()));
        difficulty = get_input<char>("Option:");

        switch (difficulty) {
            case '1':
                ai_samples_per_move = 100;
                return;
            case '2':
                ai_samples_per_move = 200;
                return;
            case '3':
                ai_samples_per_move = 500;
                return;
            case '4':
                ai_samples_per_move = 1000;
                return;
            case '0':
                return;
            default:
                print_error("Invalid option!");
                break;
        }
    }
}

void GameSettings::configure_playing_side() {
    char orientation;
    std::string title = "Playing side configuration";

    while (true) {
        clear_console();
        print_menu_title(title);
        print_menu_option("h. Play horizontally");
        print_menu_option("v. Play vertically");
        print_menu_option("0. Back");
        print_menu_title_sep(static_cast<int>(title.size()));
        orientation = get_input<char>("Option: ");

        switch (std::tolower(orientation)) {
            case 'h':
                player_side = PlayingSide::HORIZONTAL;
                return;
            case 'v':
                player_side = PlayingSide::VERTICAL;
                return;
            case '0':
                return;
            default:
                print_error("Invalid option!");
                break;
        }
    }
}

int GameSettings::get_board_size() {
    return board_size;
}

PlayingSide GameSettings::get_player_side() {
    return player_side;
}

PlayingSide GameSettings::get_ai_side() {
    return player_side == PlayingSide::HORIZONTAL ? PlayingSide::VERTICAL : PlayingSide::HORIZONTAL;
}

int GameSettings::get_ai_samples_per_move() {
    return ai_samples_per_move;
}