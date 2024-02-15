#ifndef HEXGAME_GLOBALPARAMETERS_H
#define HEXGAME_GLOBALPARAMETERS_H

#include "../enums/CompiledOS.h"

class GlobalParameters {
public:
    static CompiledOS environment;

    /**
     * @brief Check if the application is running over a windows environment.
     *
     * @return Returns `true` if the applications is running on a windows environment, else `false`.
     */
    static bool is_running_on_windows();

    /**
     * @brief Check if the application is running over a linux environment.
     *
     * @return Returns `true` if the applications is running on a linux environment, else `false`.
     */
    static bool is_running_on_linux();
};


#endif //HEXGAME_GLOBALPARAMETERS_H
