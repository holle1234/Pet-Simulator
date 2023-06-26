#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../utils/utils.h"


/* 
Test if values that shouldn't be changed remain unchanged and 
values that should change will change as intendend.

 */

Pet pet {"pedro", "dog", 1, 1, 1}; // name type fullness happiness energy

TEST_CASE("TEST FEEDING"){
    Pet pet_after = pet; // make a copy and compare
    Treat treat {"steak", 2, 1}; // type nutrition happiness
    feed_pet(pet_after, treat);
    CHECK(pet_after.name == pet.name);
    CHECK(pet_after.energy == pet.energy);
    CHECK(pet_after.fullness == pet.fullness + treat.nutrition_level);
    CHECK(pet_after.happiness == pet.happiness + treat.happiness);
};

TEST_CASE("TEST SLEEPING"){
    Pet pet_after = pet; // make a copy and compare
    Sleep sleep {"good", 5}; // type energy
    sleep_pet(pet_after, sleep);
    CHECK(pet_after.name == pet.name);
    CHECK(pet_after.energy == pet.energy + sleep.energy);
    CHECK(pet_after.fullness == pet.fullness);
    CHECK(pet_after.happiness == pet.happiness);
};

TEST_CASE("TEST PLAYING"){
    Pet pet_after = pet; // make a copy and compare
    Play play {"rope-pull", 5, 5}; // type energy happiness
    play_pet(pet_after, play);
    CHECK(pet_after.name == pet.name);
    CHECK(pet_after.energy >= 0);
    CHECK(pet_after.fullness == pet.fullness);
    CHECK(pet_after.happiness == pet.happiness + play.happiness);
};