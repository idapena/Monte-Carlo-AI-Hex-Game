cmake_minimum_required(VERSION 3.27)
project(HexGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(game src/main.cpp
        src/common/Graph.tpp
        include/common/Graph.h
        include/game/Game.h
        src/game/HexGame.cpp
        include/game/HexGame.h
        include/enums/PlayerToken.h
        include/player/Player.h
        include/player/HumanPlayer.h
        include/enums/PlayingSide.h
        src/player/HumanPlayer.cpp
        src/game/HexBoard.cpp
        include/game/HexBoard.h
        include/utils/GlobalParameters.h
        src/common/GlobalParameters.cpp
        include/enums/CompiledOS.h
        include/common/AppFunctions.h
        src/common/AppFunctions.cpp
        src/game/GameSettings.cpp
        include/game/GameSettings.h
        include/algorithms/PathAlgorithm.h
        include/algorithms/DepthFirstSearch.h
        src/algorithms/DepthFirstSearch.tpp
        src/player/MonteCarloAIPlayer.cpp
        include/player/MonteCarloAIPlayer.h
)
