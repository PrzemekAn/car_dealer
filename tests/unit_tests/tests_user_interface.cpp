#include "user_interface.h"
#include <gtest/gtest.h>

#if 1
TEST(UserInterface, display_action_menu){
    UserInterface ui;
    ui.display_action_menu();
}
#endif

#if 1
TEST(UserInterface, get_action){
    UserInterface ui;
    UserInterface::Action res = ui.get_action();
    switch(res){
        case UserInterface::Action::REGISTER:
            std::cout << "REGISTER\n";
            break;
        case UserInterface::Action::SELL:
            std::cout << "SELL\n";
            break;
        case UserInterface::Action::OVERVIEW:
            std::cout << "OVERVIEW\n";
            break;
        case UserInterface::Action::EXIT:
            std::cout << "EXIT\n";
            break;
        case UserInterface::Action::INVALID_INPUT:
            std::cout << "INVALID_INPUT\n";
            break;
    }
}
#endif

#if 1
TEST(UserInterface, display_car_selection_menu){
    UserInterface ui;
    ui.display_car_selection_menu();
}
#endif

#if 1
TEST(UserInterface, get_selection){
    UserInterface ui;
    int selection{ui.get_selection()};

    std::cout << selection << std::endl;
}

#endif

#if 1
TEST(UserInterface, get_car_details){
    UserInterface ui;
    std::tuple<std::string, int , float> details {ui.get_car_details()};

    std::cout << "Car details: \n";
    std::cout << "Model: " << std::get<std::string>(details) << std::endl;
    std::cout << "Registration year: " << std::get<int>(details) << std::endl;
    std::cout << "Price: " << std::get<float>(details) << std::endl;
}
#endif