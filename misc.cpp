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
                std::cout << "Invalid input! Try again. Input 999 to exit the game.\n";
        }
    } 
}

std::string StairWay(const bool &brass_key, const bool &candle, bool &gold_key) {
    
    Question basement_question("You see a mini vault in one corner of the basement and a desk on the other other corner. There is a letter on the desk. What do you want to do?",
    {"Go to the mini vault",
    "Go to the desk and examine the letter",
    "Go back to the hallway (You will have a basement door that's locked behind you!)"});

    std::cout << "======\nYou approach the stairway going down to a basement. The way to the basement is dark and you cannot see what's down there." 
        "You take the courage and slowly go down. Suddenly, Boom! The door on top of the stairway behind you closes and locks.\n";

    std::string vault_back = "";

    if (!candle) {
        std::cout << "======\nIt's dark and you cannot see anything."
        "You do not have anything to lighten the room and start exploring."
        "Your only way is to try to open the locked door behind you and go back to hallway.\n";
        return BasementDoor(brass_key);
    } else {
        std::cout << "Luckily you have a candle in your hand that lightens the room and you can start exploring.\n";
        
        while (basement_question.answer_ != 3) {
            
            basement_question.Ask();
            switch (basement_question.answer_) {
                case 1: {
                    vault_back = Vault(gold_key);
                    if (vault_back == "exit") {
                        return "exit";
                    } else {
                        continue;
                    }
                }
                    break;
                case 2: 
                    Desk();
                    break;
                case 3: 
                    return "hallway";
                case 999:
                    return "exit";
                default:
                    std::cout << "Invalid input! Try again. Input 999 to exit the game.\n";
            }

        }

    }
}

std::string BasementDoor(const bool &brass_key) {
    
    if (brass_key) {
        std::cout << "You are lucky. You have the brass key that you took from the console's drawer and it openes the basement door. "  
            "You open the door and go back to the hallway.\n";
        return "hallway";
    } else {
        std::cout << "Unfortunately, you do not have the key to unlock the basement door and you will be stuck in there for a long time and god knows what will happen to you."
        "Try the game again!\n";
        return "exit";
    }

}

std::string Vault(bool &gold_key) {
    
    if (gold_key) {
        std::cout << "The vault is open and you have the gold key. There is nothing here for you.\n";
        return "basement";
    } else {

        std::cout << "The mini vault has a digital keypad and you need a passcode to open it. It should be an 8 digit passcode.\n";
        
        int attempts = 0;
        
        std::cout << "If you enter more than three wrong passwords, the game will be over.\nTo go back to the basement, enter 111.\n";

        Question passcode_question("Enter the passcode: ", {});

        while (passcode_question.answer_ != 20230928 && attempts < 3) {
            passcode_question.Ask();
            if (passcode_question.answer_ == 111) {
                break;
            }
            attempts++;
        }

        if (attempts == 3) {
            std::cout << "Too many wrong attempts. Game Over.\n";
            return "exit";
        } else if (passcode_question.answer_ == 111) {
            return "basement";
        } else {
            std::cout << "The passcode was correct! You open the vault and find a gold key. The key is yours now.\n";
            gold_key = true;
            return "basement";
        }
    }
}

void Desk() {
    std::cout << "You see a letter on the desk that says:\n\tDear player, you do not have much time. Hurry!\nReza\n2023 09 28\n";
}