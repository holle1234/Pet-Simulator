#include "utils.h"



void feed_pet(Pet& pet, Treat& treat){
    // decrease hunger
    int new_hunger = pet.fullness - treat.nutrition_level;
    pet.fullness = new_hunger < 0 ? 0 : new_hunger;

    // increase happiness
    pet.happiness += treat.happiness;
}

void play_pet(Pet& pet, Play& play){
    // decrease energy
    int new_energy = pet.energy - play.energy;
    pet.energy = new_energy < 0 ? 0 : new_energy;

    // increase happiness
    pet.happiness += play.happiness;
}