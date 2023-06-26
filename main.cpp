#include "./utils/utils.h"
#include "./filelog/log.h"
#include <iostream>


const std::string savepath {"pet.log"};


int main(int argc, char const *argv[])
{
    Pet pet {"pepe", "dog", 50};
    Play play {"run", 1, 2};
    Treat treat {"ham", 1, 2};
    std::cout << pet;

    write_state(savepath, pet);
    Pet newPet = construct_pet(savepath);
    std::cout << newPet;


    return 0;
}
