#ifndef FILE_HANDLER
#define FILE_HANDLER
#include "car_record.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

class FileHandler{
    public:
        FileHandler(std::string path);
        std::vector<CarRecord> load_data();
        void save_data(const std::vector<CarRecord>& records);
        
    private:
        std::string m_file_path;
};


#endif