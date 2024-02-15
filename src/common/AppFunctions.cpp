#include <string>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include "../../include/utils/GlobalParameters.h"

void print_menu_title(const std::string &title) {
    int size = 9;
    for (int i = 0; i < size; ++i) {
        std::cout << "#";
    }

    std::cout << " " << std::setw(static_cast<int>(title.size()) - 1) << title << " ";

    for (int i = 0; i < size; ++i) {
        std::cout << "#";
    }
    std::cout << std::endl;
}

void print_menu_title_sep(const int &size) {
    int print_size = (size < 20 ? 20 : size) + 20;
    for (int i = 0; i < print_size; ++i) {
        std::cout << "#";
    }

    std::cout << std::endl;
}

void print_menu_option(const std::string &option) {
    std::cout << "  " << option << std::endl;
}

void print_message(const std::string &message) {
    std::cout << message << std::endl;
}

void wait_for_enter(const std::string &message) {
    std::cout << message << std::endl;
    std::string line;
    std::getline(std::cin, line);
    std::cout << std::endl;
}

void print_error(const std::string &message) {
    std::cout << message << std::endl;
    std::string line = "Press enter to continue...";
    std::getline(std::cin, line);
}

void clear_console() {
    if (GlobalParameters::is_running_on_windows())
        std::system("cls");
    else
        std::system("clear");
}