#include "utils.h"



void feed_pet(Pet& pet, Treat& treat){
    // decrease hunger
    int new_hunger = pet.fullness - treat.nutrition_level;
    pet.fullness = new_hunger < 0 ? 0 : new_hunger;

    // increase happiness
    pet.happiness += 1;

    
}