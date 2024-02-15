/**
 * @file HexGame.cpp
 * @brief Implementation file for the HexGame class.
 */

#include <memory>
#include "../../include/game/HexGame.h"
#include "../../include/common/AppFunctions.h"
#include "../../include/player/HumanPlayer.h"
#include "../../include/player/MonteCarloAIPlayer.h"

bool HexGame::end_game() const {
    return end_game_;
}

void HexGame::init() {
    // Set up board
    board_ = std::make_unique<HexBoard>(GameSettings::get_board_size());

    // Select a path algorithm
    path_algorithm_ = std::make_unique<DepthFirstSearch<int, PlayerToken>>();

    // Add players
    players_.push_back(std::make_unique<HumanPlayer>(GameSettings::get_player_side()));
    players_.push_back(std::make_unique<MonteCarloAIPlayer>(GameSettings::get_ai_side(), *path_algorithm_));
}

void HexGame::update() {
    std::string title = "Hex Game Board";

    while (!end_game()) {
        clear_console();

        // Render board
        std::cout << *board_;
        print_menu_option("Player -> Orientation: " + PlayingSideHandler::to_string(GameSettings::get_player_side()) +
                          " | Token: " + board_->get_player_token(PlayerToken::PLAYER) + ") ");
        print_menu_option("AI -> Orientation: " + PlayingSideHandler::to_string(GameSettings::get_ai_side()) +
                          " | Token: " + board_->get_player_token(PlayerToken::AI) + ") ");
        std::cout << std::endl;
        
        // Render menu
        print_menu_title(title);

        print_menu_option("1. Play");
        print_menu_option("0. Back");
        print_menu_title_sep(static_cast<int>(title.size()));
        char option = get_input<char>("Option:");

        switch (option) {
            case '1':
                for (const auto &player: players_) {
                    // Process player turn
                    process_player_turn(*player);

                    // Analyse board
                    analyse_board(*player);

                    // Check end condition
                    if (end_game()) break;
                }
                break;
            case '0':
                end_game_ = true;
                break;
            default:
                print_error("Invalid option!");
                break;
        }
    }
}

void HexGame::dispose() {

}

void HexGame::process_player_turn(const Player &player) {
    int pos;
    while (true) {
        // Get player next move
        pos = player.get_next_move(*board_);

        // Check if the move is valid
        if (!board_->is_tile_free(pos)) {
            print_error("Invalid position!");
            continue;
        }

        // Update the tile
        board_->update_tile(pos, player.token);
        break;
    }
}

void HexGame::analyse_board(const Player &player) {
    // Get player information
    SidePaths<int> paths = board_->get_sides_paths(player.side);
    const PlayerToken player_token = player.token;

    // Analyse board
    std::set<int> path = path_algorithm_->get_path(
            board_->get_board_graph(),
            paths.starting_positions,
            paths.ending_positions,
            [player_token](const PlayerToken &token) { return token == player_token; }
    );

    // Check if there is a winner
    if (!path.empty()) {
        end_game_summary(player, path);
        end_game_ = true;
    }
}

void HexGame::end_game_summary(const Player &player, const std::set<int> &path) {
    clear_console();
    print_menu_title("End game summary");
    print_menu_option("Winner: " + PlayerTokenHandler::to_string(player.token));
    print_menu_option("Orientation: " + PlayingSideHandler::to_string(player.side));
    print_menu_option("Token: " + std::string{board_->get_player_token(player.token)});
    std::cout << "  Sequence: ";
    for (auto n: path)
        std::cout << "(" << n / board_->tiles_per_side + 1 << ", " << n % board_->tiles_per_side + 1 << ") ";
    std::cout << std::endl;
    print_menu_option("Board: ");
    std::cout << *board_;
    wait_for_enter("Press enter to continue...");
}

