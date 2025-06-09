#include "file_handler.h"
#include <gtest/gtest.h>
#include <iostream>

#if 1
TEST(FileHandler, load_data){
    FileHandler fh("./tests/unit_tests/cars.csv");
    std::vector<CarRecord> records{fh.load_data()};
    
    for(const CarRecord& record: records){
        std::cout << record.model << " " << record.registration_year << " " << record.base_price << " " << record.is_available << record.price_drop << " " << record.current_price << " " << record.inclusion_date << std::endl;
    }
}
#endif

#if 1
TEST(FileHandler, save_data){
    FileHandler fh("./tests/unit_tests/cars.csv");
    std::vector<CarRecord> records{fh.load_data()};
    fh.save_data(records);
}
#endif
