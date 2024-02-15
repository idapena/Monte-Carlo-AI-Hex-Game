#ifndef HEXGAME_PLAYINGSIDE_H
#define HEXGAME_PLAYINGSIDE_H

#include <string>

enum class PlayingSide {
    HORIZONTAL = 0,
    VERTICAL = 1
};

class PlayingSideHandler {
public:
    static std::string to_string(PlayingSide player_side) {
        return player_side == PlayingSide::HORIZONTAL ? "HORIZONTAL" : "VERTICAL";
    }
};


#endif //HEXGAME_PLAYINGSIDE_H
