#include "car_dealer.h"
#include <gtest/gtest.h>
#include <iostream>

#if 1
TEST(CarDealer, all_cars){
    CarDealer cd(FileHandler("./tests/unit_tests/cars.csv"));
    std::cout << "All cars:\n";
    display_results(cd.all_cars());
}
#endif

#if 1
TEST(CarDealer, available_cars){
    CarDealer cd(FileHandler("./tests/unit_tests/cars.csv"));
    std::cout << "Available cars:\n";
    display_results(cd.available_cars());
}
#endif

#if 1
TEST(CarDealer, sold_cars){
    CarDealer cd(FileHandler("./tests/unit_tests/cars.csv"));
    std::cout << "Sold cars:\n";
    display_results(cd.sold_cars());
}
#endif

#if 1
TEST(CarDealer, add_car_record){
    CarDealer cd(FileHandler("./tests/unit_tests/cars.csv"));
    cd.add_car_record(std::make_tuple("Tesla", 2020, 66546.0f));

    EXPECT_EQ(cd.all_cars()[cd.all_cars().size()-1].model,  "Tesla");
    EXPECT_EQ(cd.all_cars()[cd.all_cars().size()-1].registration_year, 2020);
}
#endif

#if 1
TEST(CarDealer, mark_as_sold){
    CarDealer cd(FileHandler("./tests/unit_tests/cars.csv"));
    cd.available_cars()[1].get().is_available = 1;
    cd.mark_as_sold(1);

    EXPECT_EQ(cd.all_cars()[1].is_available, 1);
    
}
#endif

#if 1
TEST(CarDealer, db_update){
    CarDealer cd(FileHandler("./tests/unit_tests/cars.csv"));
    cd.add_car_record(std::make_tuple("Tesla", 2020, 66546.0f));
    cd.db_update();
}
#endif

#if 1
TEST(CarDealer, overview){
    CarDealer cd(FileHandler("./tests/unit_tests/cars.csv"));
    cd.overview();
}
#endif

#if 1
TEST(CarDealer, update_prices){
    CarDealer cd(FileHandler("./tests/unit_tests/cars.csv"));
    cd.update_prices();
}
#endif