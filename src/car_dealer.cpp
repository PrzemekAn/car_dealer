#include "car_dealer.h"

CarDealer::CarDealer(FileHandler fh): m_file_handler{fh}, m_car_records{fh.load_data()} {}

const std::vector<CarRecord>& CarDealer::all_cars(){
    return m_car_records;
}

std::vector<CarRecordRefWrapper> CarDealer::available_cars(){
    std::vector<std::reference_wrapper<CarRecord>> available_cars{};
    for(CarRecord& cr: m_car_records){
        if(cr.is_available){
            available_cars.push_back(std::ref(cr));
        }
    }
    return available_cars;
}

std::vector<CarRecordRefWrapper> CarDealer::sold_cars(){
    std::vector<std::reference_wrapper<CarRecord>> sold_cars{};
    for(CarRecord& cr: m_car_records){
        if(!cr.is_available){
            sold_cars.push_back(std::ref(cr));
        }
    }
    return sold_cars;
}

void CarDealer::add_car_record(std::tuple<std::string, int, float> cr_data){
    std::time_t timestamp;
    std::time(&timestamp);
    
    CarRecord cr;
    cr.model = std::get<std::string>(cr_data);
    cr.registration_year = std::get<int>(cr_data);
    cr.base_price = std::get<float>(cr_data);
    cr.price_drop = 0;
    cr.current_price = cr.base_price;
    cr.inclusion_date = timestamp;
    cr.is_available = 1;

    m_car_records.push_back(cr);
    db_update();
}

void CarDealer::mark_as_sold(int index){
    if(index < 0 || index > available_cars().size()){
        std::cerr << "Given index is out of range\n";
        return;
    }
    
    available_cars()[index-1].get().is_available = 0;
    db_update();
}

void CarDealer::db_update(){
    m_file_handler.save_data(m_car_records);
}

void CarDealer::overview(){
    std::cout << "\nAvailable cars:\n";
    display_results(available_cars());

    std::cout << "\nSold cars:\n";
    display_results(sold_cars());
}

void CarDealer::update_prices(){
    for(CarRecord& cr: m_car_records){
        if(cr.is_available == 0) continue;
        if(cr.price_drop < MAX_PRICE_DROP) update_price_drop(cr);
        if(cr.price_drop == 0) continue;

        cr.current_price = cr.base_price - cr.base_price * cr.price_drop / 100; 
    }
    db_update();
}

void CarDealer::update_price_drop(CarRecord& cr){
    std::time_t timestamp;
    std::time(&timestamp);
    std::time_t diff = timestamp - cr.inclusion_date;

    if(cr.price_drop == MAX_PRICE_DROP) return;
    
    // 2020 seconds is the time difference between timestamp and inclusion_date in which cr.price_drop would reach  20(%)
    if(diff >= 2020){
        cr.price_drop = MAX_PRICE_DROP;
        return;
    }
    else{
        if(diff >= 30){
            cr.price_drop = ((diff/10)-2) * 0.1f;
        }
    }

}

// helper functions
void display_results(const std::vector<CarRecord>& records){
    int index = 1;
    std::cout << std::left << std::setw(ID_COLUMN_WIDTH) << "Id";
    std::cout << std::left << std::setw(MODEL_CULUMN_WIDTH) << "Model";
    std::cout << std::left << std::setw(YEAR_CULUMN_WIDTH) << "Registration Year";
    std::cout << std::left << std::setw(PRICE_CULUMN_WIDTH) << "Price" << std::endl;
    for(const CarRecord& record: records){
        std::cout << std::left << std::setw(ID_COLUMN_WIDTH) << index << record << std::endl;
        ++index;
    }
}

void display_results(const std::vector<CarRecordRefWrapper> records){
    int index = 1;
    std::cout << std::left << std::setw(ID_COLUMN_WIDTH) << "Id";
    std::cout << std::left << std::setw(MODEL_CULUMN_WIDTH) << "Model";
    std::cout << std::left << std::setw(YEAR_CULUMN_WIDTH) << "Registration Year";
    std::cout << std::left << std::setw(PRICE_CULUMN_WIDTH) << "Price" << std::endl;
    for(std::reference_wrapper<CarRecord> record: records){
        std::cout << std::left << std::setw(ID_COLUMN_WIDTH) << index << record.get() << std::endl;
        ++index;
    }
}