#include <iostream>
#include "misc.hpp"
#include "question.hpp"

std::string Hallway() {

    Question hallway_question("You are in the hallway. You see a door with a gold door knob in front of you, a stairway that goes down behind you, "
        "and a console table on you right. Which way do you go?", 
        {"To the stairway",
        "To the console",
        "To the door"});

    bool valid = true;

    while (valid) {
        hallway_question.Ask();
        switch (hallway_question.answer_) {
            case 1:
                return "stairway";
                break;
            case 2: 
                return "console";
                break;
            case 3:
                return "door";
                break;
            default:
                std::cout << "Invalid output! Try again.\n";
                valid = false;
        }
    }


}



std::string Door(const bool &has_gold_key) {
    if (has_gold_key) {
        return "freedom";
    } else {
       std::cout << "The door has a gold knob and is locked. You don't have the key. Search for it and come back with the key.\n";
       return "hallway";
    }
}