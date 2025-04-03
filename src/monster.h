#ifndef MONSTER_H
#define MONSTER_H
#include <algorithm>
#include <vector>
#include <string>
#include "question_result.h"
enum KnowledgeType{
LVALUE_CASE,
RVALUE_CASE,
FUNC_DESIGNATOR,
MODIFIABLE_LVALUE
};
struct Question{
    std::string text;
    std::vector<std::string> options;
    int correct_index;
    int difficulty;
    std::string hash;
};

struct Monster{
    std::string name;
    KnowledgeType type;
    int difficulty;
    std::vector<Question> questions;
};

std::vector<Monster> generate_campaign();
#endif
