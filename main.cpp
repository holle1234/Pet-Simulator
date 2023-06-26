#include "utils/utils.h"
#include <iostream>


int main(int argc, char const *argv[])
{
    Pet pet {"pepe", "dog", 50};
    Play play {"run", 1, 2};
    Treat treat {"ham", 1, 2};
    std::cout << pet;


    return 0;
}
