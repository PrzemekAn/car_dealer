#include "user_interface.h"

void UserInterface::display_action_menu(){
    std::cout << "\n>>>>> CAR DEALER X <<<<<\n\n";
    std::cout << " 1. Register new car.\n 2. Sell a car.\n 3. Overview.\n 4. Exit\n";
    std::cout << "\nYour choice: ";
}

UserInterface::Action UserInterface::get_action(){
    std::string choice{};
    try{
        std::cin >> choice;
        if(choice != "1" && choice != "2" && choice != "3" && choice != "4"){
            throw(choice);
        }
    }catch(std::string value){
        std::cerr << "Incorrect value: " << value << " Try again!\n";
        return INVALID_INPUT;
    }

    if(choice == "1")
        return REGISTER;
    if(choice == "2")
        return SELL;
    if(choice == "3")
        return OVERVIEW;
    if(choice == "4")
        return EXIT;
    
    return INVALID_INPUT;
    
}

void UserInterface::display_car_selection_menu(){
    std::cout << "\nAvailable cars:\n";
}

int UserInterface::get_selection(){
    int selection{};

    do{
        std::cout << "\nYour choice: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while(!(std::cin >> selection) || selection < 0);

    return selection;
}

std::tuple<std::string, int ,float> UserInterface::get_car_details(){
    std::string model{};
    int year{};
    float price{};
    std::cout << "Car Details:\n";
    std::cout << "Model: ";
    std::cin >> model;
    do{
        std::cout << "Registration year: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(!(std::cin >> year) || year < 1885 || year > 2025 );
    
    do{
        std::cout << "Price: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while(!(std::cin >> price) || price < 0);

    return std::make_tuple(model, year, price);
}
