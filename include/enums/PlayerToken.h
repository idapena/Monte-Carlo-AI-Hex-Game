#ifndef HEXGAME_PLAYERTOKEN_H
#define HEXGAME_PLAYERTOKEN_H

#include <string>

/**
 * @brief Represents a owner token.
 */
enum class PlayerToken {
    NONE = 0,
    PLAYER = 1,
    AI = 2,
};

class PlayerTokenHandler {
public:
    static std::string to_string(PlayerToken token) {
        switch (token) {
            case PlayerToken::PLAYER:
                return "PLAYER";
            case PlayerToken::AI:
                return "AI";
            default:
                return "NONE";
        }
    }
};


#endif //HEXGAME_PLAYERTOKEN_H
