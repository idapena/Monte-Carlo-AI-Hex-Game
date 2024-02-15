#ifndef HEXGAME_APPFUNCTIONS_H
#define HEXGAME_APPFUNCTIONS_H

#include <string>
#include <iostream>
#include <limits>
#include "../utils/GlobalParameters.h"

/**
 * @brief Prints a title on the screen.
 *
 * @param title Title to be displayed and formatted like a menu.
 */
void print_menu_title(const std::string &title);

/**
 * @brief Prints a title separator on screen.
 *
 * @param size The size of the title to used as reference.
 */
void print_menu_title_sep(const int &size);

/**
 * @brief Prints a option on the screen.
 *
 * @param title Subtitle to be displayed and formatted like a menu option.
 */
void print_menu_option(const std::string &option);

/**
 * @brief Waits for enter to continue.
 */
void wait_for_enter(const std::string &message);

/**
 * @brief Prints a message on the screen.
 *
 * @param message Message to be displayed.
 */
void print_message(const std::string &message);

/**
 * @brief Prints a error message on the screen.
 *
 * @param message Message to be displayed.
 */
void print_error(const std::string &message);

/**
 * @brief Clears console messages.
 */
void clear_console();


/**
 * @brief Get an input from the console
 *
 * @tparam T Type of the input that is expected (casted).
 * @param prompt Message to be displayed.
 * @return The input with the given type `T`
 */
template<typename T>
T get_input(const std::string &prompt) {
    T input;
    std::cout << ">> " << prompt << " ";

    while (!(std::cin >> input)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        print_error("Invalid input. Please try again: ");
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
}

#endif //HEXGAME_APPFUNCTIONS_H
