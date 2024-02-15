#ifndef HEXGAME_HUMANPLAYER_H
#define HEXGAME_HUMANPLAYER_H

#include <iostream>
#include "Player.h"

/**
 * @brief A human player implementation that uses the `Player` interface.
 */
class HumanPlayer : public Player {
public:
    explicit HumanPlayer(PlayingSide side) :
            Player(PlayerToken::PLAYER, side) {};

    int get_next_move(const HexBoard &board) const override;
};

#endif //HEXGAME_HUMANPLAYER_H
