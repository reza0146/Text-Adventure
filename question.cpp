#include <iostream>

#include "question.hpp"

Question::Question(std::string new_question, std::vector<std::string> new_choices, int new_answer) : question_(new_question), choices_(new_choices), answer_(0) {

    question_string_ = BuildQuestionString();
}

std::string Question::BuildQuestionString() {
    
    std::string choices_string;
    
    for (int i = 0; i < choices_.size(); i++) {
        choices_string = choices_string + "\t" + std::to_string(i+1) + ") " + choices_[i] + "\n";
    }

    return question_ + "\n" + choices_string;
}


std::string Question::get_question_string() {
    return question_string_;
}

void Question::Ask() {
    std::cout << question_string_;
    std::cin >> answer_;
}