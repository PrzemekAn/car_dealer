#ifndef CAR_DEALER
#define CAR_DEALER
#include "car_record.h"
#include "file_handler.h"
#include "defines.h"
#include <vector>
#include <iostream>
#include <tuple>
#include <functional>

#define MAX_PRICE_DROP 20

using CarRecordRefWrapper = std::reference_wrapper<CarRecord>;

void display_results(const std::vector<CarRecord>& records);
void display_results(const std::vector<CarRecordRefWrapper> records);

class CarDealer{
    private:
        void update_price_drop(CarRecord& cr);
    public:
        CarDealer(FileHandler fh);
        const std::vector<CarRecord>& all_cars();
        std::vector<CarRecordRefWrapper> available_cars();
        std::vector<CarRecordRefWrapper> sold_cars();
        void add_car_record(std::tuple<std::string, int, float> cr_data);
        void mark_as_sold(int index);
        void db_update();
        void overview();
        void update_prices();
    private:
        std::vector<CarRecord>  m_car_records{};
        FileHandler             m_file_handler;
};

#endif