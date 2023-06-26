#include "log.h"
#include "../csv/csv.h"
#include <string>
#include <array>
#include <vector>

// write pet status
bool write_state(const std::string filepath, const Pet& pet){
    csv::CSVWriter writer {filepath};
    if(!writer.open()){
        return false;
    }

    // write header
    writer.writeLine(HEADERS.begin(), HEADERS.end());

    // write data
    std::array<std::string, 5> data {pet.type,
                                    pet.name,
                                    std::to_string(pet.energy),
                                    std::to_string(pet.fullness),
                                    std::to_string(pet.happiness)};

    writer.writeLine(data.begin(), data.end());
    writer.close();
    return true;
}

// read pet status
bool read_state(const std::string& filepath, std::vector<std::string>& dest){
    csv::CSVReader reader {filepath, true};
    if (!reader.open()){
        return false;
    }

    // read data
    reader.readLine(dest);
    reader.close();
    return true;
}


Pet construct_pet(const std::string& filepath){
    Pet pet;
    std::vector<std::string> data;
    if (read_state(filepath, data)){
        pet.type = data[0];
        pet.name = data[1];
        pet.energy = std::stoi(data[2]);
        pet.fullness = std::stoi(data[3]);
        pet.happiness = std::stoi(data[4]);
    }
    return pet;
}