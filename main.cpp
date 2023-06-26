#include "utils/utils.h"
#include <iostream>


int main(int argc, char const *argv[])
{
    Pet pet {"pepe", "dog", 50};
    Play treat {"ham", 1, 2};
    std::cout << pet.energy << " " << pet.happiness << "\n";
    play_pet(pet, treat);
    std::cout << pet.energy << " " << pet.happiness;

    return 0;
}
