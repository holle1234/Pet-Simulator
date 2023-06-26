#include <string>



struct Pet{
    std::string name;
    std::string type;
    int fullness {0};
    int happiness {0};
};


struct Treat{
    int nutrition_level {1};
};

void feed_pet(Pet &pet, Treat &treat);
