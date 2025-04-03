#ifndef QUESTION_RESULT_H
#define QUESTION_RESULT_H
#include <ios>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
struct QuestionResult{
    int question_index;
    std::string selected_answer;
    bool is_correct;
    float time_used;
    std::vector<int> option_order;
    int question_difficulty;
    std::string question_hash;

    std::string to_string() const {
        std::stringstream ss;
        ss<<"Q"<<question_index << " [" << (is_correct ? "√" : "×") << "]"
            << std::fixed<< std::setprecision(1)<<time_used << "s (难度:"
            << question_difficulty<<")";
        return ss.str();
    }
};
#endif
