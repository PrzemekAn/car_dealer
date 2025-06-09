#ifndef CAR_RECORD
#define CAR_RECORD
#include "defines.h"
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>

struct CarRecord{
    std::string model{};
    int         registration_year{};
    float       base_price{};
    float       price_drop{};
    float       current_price{};
    bool        is_available{};
    std::time_t inclusion_date{};
    friend std::istream& operator>>(std::istream& input, CarRecord& cr){
        std::string line{};
        if(!std::getline(input, line)) return input;

        std::istringstream ss(line);

        std::getline(ss, cr.model, ',');
        ss >> cr.registration_year;
        ss.ignore();
        ss >> cr.base_price;
        ss.ignore();
        ss >> cr.price_drop;
        ss.ignore();
        ss >> cr.current_price;
        ss.ignore();
        ss >> cr.is_available;
        ss.ignore();
        ss >> cr.inclusion_date;

        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, const CarRecord& cr){
        output << std::left << std::setw(MODEL_CULUMN_WIDTH) <<  cr.model;
        output << std::left << std::setw(YEAR_CULUMN_WIDTH) << cr.registration_year;
        output << std::left << std::setw(PRICE_CULUMN_WIDTH) << cr.current_price;

        return output;
    }
};


#endif

