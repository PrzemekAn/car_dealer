#ifndef USER_INTERFACE
#define USER_INTERFACE
#include "defines.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <limits>

class UserInterface{
    public:
        enum Action{REGISTER, SELL, OVERVIEW, EXIT, INVALID_INPUT};
        void display_action_menu();
        Action get_action();
        void display_car_selection_menu();
        int get_selection();
        std::tuple<std::string, int ,float> get_car_details();
};


#endif