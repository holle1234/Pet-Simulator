#include "./utils/utils.h"
#include "./filelog/log.h"
#include <iostream>
#include <array>


const std::string savepath {"pet.log"};
const std::array<std::string, 7> MENU_OPTIONS {"1. Sleep", "2. Eat", "3. Play", "4. View", "5. Save", "6. Load", "7. Quit"}; 


/* 
Virtual Pet Simulator
Application that will simulate taking care of a virtual pet.

Features:
    feeding
    sleeping
    playing
    saving and loading pet data

 */

enum class EnumMenuOptions{

    sleep,
    eat, 
    play,
    view,
    save,
    load,
    quit,
};



void print_menu(){
    std::cout << "Main menu\n";
    for (auto &&i : MENU_OPTIONS){
        std::cout << i << "\n";
    }
    std::cout << "Choose action: ";
}


bool valid_choice(int choice){
    if (choice <= MENU_OPTIONS.size() && choice >= 1){
        return true;
    }
    return false;
}

int mainMenu(){
    std::string row;
    int choice {-1};

    while (!valid_choice(choice)){
        print_menu();
        std::getline(std::cin, row);
        try{
            choice = std::stoi(row);
        }
        catch(const std::invalid_argument& e){
            continue;
        }
    }
    return choice;
}




int main(int argc, char const *argv[])
{
    Pet pet {"pedro", "dog"};
    Treat treat {"small treat", 1,1};
    Sleep sleep {"good nap", 5};
    Play play {"rope-pull", 2, 3};

    while (true){
        int ichoice = mainMenu() - 1;
        EnumMenuOptions echoice = static_cast<EnumMenuOptions>(ichoice);

        switch (echoice){
            case EnumMenuOptions::eat :{
                feed_pet(pet, treat);
                break;
            }
            case EnumMenuOptions::sleep :{
                sleep_pet(pet, sleep);
                break;
            }
            case EnumMenuOptions::play :{
                play_pet(pet, play);
                break;
            }        
            case EnumMenuOptions::view :{
                std::cout << pet << "\n";
                break;
            }

            case EnumMenuOptions::load :{
                pet = construct_pet(savepath);
                break;
            }

            case EnumMenuOptions::save :{
                write_state(savepath, pet);
                break;
            }
            case EnumMenuOptions::quit :{
                return 0;
            }

            default:
                break;
        }
    }


    return 0;
}
