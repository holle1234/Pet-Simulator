#if !defined(LOG)
#define LOG

#include "../utils/utils.h"
#include <array>
#include <string>
#include <vector>


// headers for writing to .csv
const std::array<std::string, 5> HEADERS {"type", "name", "energy", "fullness", "happiness"};



// write to csv
bool write_state(const std::string filepath, const Pet &pet);

// read from csv
bool read_state(const std::string &filepath, std::vector<std::string>& dest);

// construct a pet object from file contents 
Pet construct_pet(const std::string &filepath);




#endif // LOG

