#ifndef HEXGAME_PLAYER_H
#define HEXGAME_PLAYER_H

#include "../enums/PlayingSide.h"
#include "../enums/PlayerToken.h"
#include "../game/HexBoard.h"


/**
 * @brief A player interface for the game.
 */
class Player {
public:
    const PlayingSide side; /** Tile Orientation for the player. */
    const PlayerToken token; /** Token that is used to describe the player pn the board. */

    /**
     * @brief A player interface for the game.
     *
     * @param side: Player side in the board.
     * @param token: Player token on the board.
    */
    explicit Player(PlayerToken token, PlayingSide side) :
            token(token),
            side(side) {};

    virtual ~Player() = default;

    /**
     * @brief Ask for the next move of the player.
     *
     * @return Returns the next move for the player.
     */
    virtual int get_next_move(const HexBoard &board) const = 0;
};

#endif //HEXGAME_PLAYER_H
