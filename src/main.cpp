#include "../include/game/HexGame.h"
#include "../include/common/AppFunctions.h"
#include "../include/game/GameSettings.h"

void play_game() {
    Game *game = new HexGame();
    game->game_loop();
}

int main() {
    std::string title = "Monte Carlo Hex Game";

    while (true) {
        clear_console();
        print_menu_title(title);
        print_menu_option("1. Play the game");
        print_menu_option("2. Settings");
        print_menu_option("0. Exit");
        print_menu_title_sep(static_cast<int>(title.size()));

        char option = get_input<char>("Option:");

        switch (option) {
            case '1':
                play_game();
                break;
            case '2':
                GameSettings::configure_game();
                break;
            case '0':
                return 0;
            default:
                print_error("Invalid option!");
                break;
        }
    }
}
