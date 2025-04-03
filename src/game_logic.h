#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
#include "character.h"
#include "monster.h"
#include <chrono>
QuestionResult ask_question(const Question& q,int index);
void knowledge_battle(Character& player,Monster& monster);
#endif
