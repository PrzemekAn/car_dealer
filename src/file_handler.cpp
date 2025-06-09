#include "file_handler.h"

FileHandler::FileHandler(std::string path): m_file_path{path}{};

std::vector<CarRecord> FileHandler::load_data(){
    std::ifstream file;
    file.open(m_file_path, std::ios::in);
    if(!file.is_open()) {
        std::cerr << "File is not open\n";
        return {};
    }

    std::string header{};
    std::getline(file, header); // ignore csv header
    
    std::vector<CarRecord> records{};
    CarRecord cr;
    while(file >> cr){
        records.push_back(cr);
    }
    
    return records;
}

void FileHandler::save_data(const std::vector<CarRecord>& records){
    std::fstream file;
    file.open(m_file_path, std::ios::out | std::ofstream::trunc);
    if(!file.is_open()) std::cerr << "File is not open\n";

    file << "Model,RegistrationYear,Base Price,Price Drop,Current Price,Is Available,Inclusion Date\n";
    for(const CarRecord& record: records){
        file << record.model << "," << record.registration_year << "," << record.base_price << "," << record.price_drop << "," << record.current_price << "," << record.is_available << "," << record.inclusion_date << "\n";
    }
    file.close();
}

