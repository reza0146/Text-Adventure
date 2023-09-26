#include <string>
#include <vector>

class Question {

    private:
    std::string question_string_;
    
    public:
    std::string question_;
    std::vector<std::string> choices_;
    int answer_;


    private:
    std::string BuildQuestionString();

    public:
    Question(std::string new_question, std::vector<std::string> new_choices, int new_answer = 0);
    void Ask();
    std::string get_question_string();

};