#include "utils.h"
#include <ostream>



std::ostream& operator<<(std::ostream& os, Pet& pet){
    os << pet.type << " " << pet.name << " energy: " << pet.energy <<
    " happiness: " << pet.happiness << " fullness " << pet.fullness;
    return os;
}

void feed_pet(Pet& pet, Treat& treat){
    // increase fullness
    pet.fullness += treat.nutrition_level;

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

void sleep_pet(Pet& pet, Sleep& sleep){
    // increase energy
    pet.energy += sleep.energy;
}