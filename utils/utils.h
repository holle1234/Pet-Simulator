#include <string>



struct Pet{
    std::string name;
    std::string type;
    int fullness {0};
    int happiness {0};
    int energy {10};
};


struct Treat{
    std::string type;
    int nutrition_level {1};
    int happiness {1};
};


struct Play{
    std::string type;
    int energy {1};
    int happiness {1};
};

struct Sleep{
    std::string type; // bad good etc..
    int energy {1};
};

std::ostream &operator<<(std::ostream &os, Pet &pet);

void feed_pet(Pet &pet, Treat &treat);

void play_pet(Pet &pet, Play &play);

void sleep_pet(Pet &pet, Sleep &sleep);
