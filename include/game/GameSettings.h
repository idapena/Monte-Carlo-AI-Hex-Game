#ifndef HEXGAME_GAMESETTINGS_H
#define HEXGAME_GAMESETTINGS_H


#include "../enums/PlayingSide.h"

/**
 * @brief This class stores global game configuration.
 */
class GameSettings {
public:
    /**
     * @brief Prompts model configuration menu.
     */
    static void configure_game();

    /**
     * @brief Gets the number of tiles for each side of the board.
     *
     * @return Returns an integer value that represents the number of tiles that the board should have for each side.
     */
    static int get_board_size();

    /**
     * @brief Gets the playing side of the player.
     *
     * @return Returns a enumerate that represents the playing side of the player.
     */
    static PlayingSide get_player_side();

    /**
     * @brief Gets the playing side of the AI.
     *
     * @return Returns a enumerate that represents the playing side of the AI.
     */
    static PlayingSide get_ai_side();

    /**
     * @brief Gets the number of samples that the AI is going to do for each move.
     *
     * @return Returns an integer value that represents the number of samples that the AI is going to do for each move.
     */
    static int get_ai_samples_per_move();

private:
    static int board_size;
    static PlayingSide player_side;
    static int ai_samples_per_move;

    static void configure_board_size();

    static void configure_AI_difficulty();

    static void configure_playing_side();
};

#endif //HEXGAME_GAMESETTINGS_H
