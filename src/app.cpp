#include "app.h"

void App::run(std::string path){
    UserInterface::Action action{UserInterface::INVALID_INPUT};
    UserInterface ui;
    CarDealer cd{FileHandler(path)};
    do{
        ui.display_action_menu();
        action = ui.get_action();
        switch(action){
            case UserInterface::INVALID_INPUT:
                continue;
            case UserInterface::REGISTER:
                cd.add_car_record(ui.get_car_details());
                std::cout << "\nNew Car Added!\n";
                break;
            case UserInterface::SELL:
                ui.display_car_selection_menu();
                cd.update_prices();
                display_results(cd.available_cars());
                cd.mark_as_sold(ui.get_selection());
                break;
            case UserInterface::OVERVIEW:
                cd.update_prices();
                cd.overview();
                break;
        }
    }
    while (action != UserInterface::EXIT);
}