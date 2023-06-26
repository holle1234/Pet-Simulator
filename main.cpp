#include "utils/utils.h"
#include <iostream>


int main(int argc, char const *argv[])
{
    Pet pet {"pepe", "dog", 50};
    Treat treat {10};
    feed_pet(pet, treat);
    std::cout << pet.fullness << " " << pet.happiness;

    return 0;
}
