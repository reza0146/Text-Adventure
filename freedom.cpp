#include <iostream>
#include <map>

#include "misc.hpp"
#include "question.hpp"

int main() {

    bool has_gold_key = false;
    bool has_brass_key = false;
    bool has_candle = false;

    std::map<std::string, int> state_map({{"hallway", 1}, 
        {"door", 2},
        {"console", 3},
        {"stairway", 4},
        {"exit", 999}});


    std::cout << "====Welcom to the game====\n";
    std::cout << "!At any point in the game type 999 to exit!\n";
    std::cout << "You wake up in the middle of a hallway. You don't remember anything and your goal is to find the way outside the building.\n";

    bool exit = false;
    std::string state = "hallway";



    while (!exit) {

        switch (state_map[state]) {
            case 1: //hallway
                state = Hallway();
                break;
            case 2: //door
                state = Door(has_gold_key);
                break;
            case 3: //console
                state = Console(has_brass_key, has_candle);
                break;
            case 4: //stairway
                state = StairWay(has_brass_key, has_candle, has_gold_key);
                break;
            case 999:
                std::cout << "Goodbye!\n";
                exit = true;
            
        }

    }

}