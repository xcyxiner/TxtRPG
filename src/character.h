#ifndef  CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>
#include "question_result.h"

struct Character{
    std::string name;
    int hp=100;
    int strength;
    int agility;
    int level=1;
    int exp=0;

    struct {
        int lvalue_mastery=0;
        int rvalue_analysis=0;
        int func_designator=0;
        int type_conversion=0;
    } knowledge;

    std::vector<QuestionResult> battle_log;
};

Character create_character();
void show_status(const Character &c);
#endif
