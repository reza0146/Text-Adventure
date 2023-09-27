#include <iostream>
#include "misc.hpp"
#include "question.hpp"

std::string Hallway() {

    Question hallway_question("======\nYou are in the hallway. You see a door with a gold door knob that says exit on it in front of you and "
        "a stairway that goes down behind you. There is an open door in the beginning of stairway with a brass knob."
        "You also see a console table on your right. Which way do you go?", 
        {"To the stairway",
        "To the console",
        "To the door"});

    bool valid = true;

    while (true) {
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
            case 999: 
                return "exit";
                break;
            default:
                std::cout << "Invalid output! Try again. Input 999 to exit the game.\n";
        }
    }


}



std::string Door(const bool &gold_key) {

    if (gold_key) {
        return "freedom";
    } else {
       std::cout << "The door has a gold knob and is locked. You don't have the key. Search for it and come back with the key.\n";
       return "hallway";
    }
}


std::string Console(bool &brass_key, bool &candle) {

    Question console_question("======\nThere is a lightened candle on the console. Also, the candle has a drawer. What do you want to do?",
        {"Pick up the candle",
        "Open the drawer",
        "Go back to hallway"});


    while (console_question.answer_ != 3) {

        console_question.Ask();
        
        switch (console_question.answer_) {
            case 1:
                std::cout << "Candle is yours! You will carry it during your exploration.\n";
                candle = true;
                break;
            case 2:
                std::cout << "Inside the drawer there was a brass key. It's yours now!\n";
                brass_key = true;
                break;
            case 3:
                return "hallway";
                break;
            case 999:
                return "exit";
                break;
            default:
                std::cout << "Invalid output! Try again. Input 999 to exit the game.\n";
        }
    } 
}

std::string StairWay(bool &brass_key, bool &candle, bool &gold_key) {
    
    std::cout << "======\nYou approach the stairway going down to a basement. The way to the basement is dark and you cannot see what's down there." 
        "You take the courage and slowly go down. Suddenly, Boom! The door on top of the stairway behind you closes and locks.\n";
    
    
    


    if (!candle) {
        std::cout << "======\nIt's dark and you cannot see anything. Your only way is to try to open the door behind you.\n";
        
        
    }
}

std::string BasementDoor(const bool &brass_key) {
    
    if (brass_key) {
        std::cout << "You are lucky. You have the brass key that you took from the console's drawer and it openes the basement door. "  
            "You open the door and go back to the hallway\n";
        return "hallway";
        


    }
}