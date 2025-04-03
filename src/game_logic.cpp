#include "game_logic.h"
#include <iostream>
#include <chrono>
#include <algorithm>
#include "utilities.h"

QuestionResult ask_question(const Question& q, int index) {
    using namespace std::chrono;
    auto start = steady_clock::now();
    
    std::vector<int> order = shuffle_options(q.options.size());
    
    std::cout << "\n=== 题目 [" << q.difficulty << "星] ===" << std::endl;
    std::cout << q.text << std::endl;
    for (size_t i = 0; i < order.size(); ++i) {
        std::cout << i+1 << ") " << q.options[order[i]] << std::endl;
    }

    int choice;
    do {
        std::cout << "选择答案 (1-" << order.size() << "): ";
        std::cin >> choice;
        std::cin.ignore();
    } while(choice < 1 || choice > static_cast<int>(order.size()));

    auto end = steady_clock::now();
    float duration = duration_cast<std::chrono::duration<float>>(end - start).count();

    QuestionResult res;
    res.question_index = index;
    res.selected_answer = q.options[order[choice-1]];
    res.is_correct = (order[choice-1] == q.correct_index);
    res.time_used = duration;
    res.option_order = order;
    res.question_difficulty = q.difficulty;
    res.question_hash = q.hash;
    
    return res;
}

void knowledge_battle(Character& player, Monster& monster) {
    std::cout << "\n遭遇 " << monster.name << "！知识对决开始！\n";
    
    for (size_t i = 0; i < monster.questions.size(); ++i) {
        QuestionResult res = ask_question(monster.questions[i], i);
        player.battle_log.push_back(res);

        if (res.is_correct) {
            int base_exp = 10 * res.question_difficulty;
            float time_bonus = std::max(5.0f - res.time_used, 0.0f);
            int total_exp = static_cast<int>(base_exp + time_bonus);
            
            switch(monster.type) {
                case LVALUE_CASE: 
                    player.knowledge.lvalue_mastery += total_exp;
                    break;
               case RVALUE_CASE:
                    player.knowledge.rvalue_analysis += total_exp;
                    break;
                case FUNC_DESIGNATOR:
                    player.knowledge.func_designator += total_exp;
                    break;
                case MODIFIABLE_LVALUE:
                    player.knowledge.type_conversion += total_exp;
                    break;
            }
            
            std::cout << "正确！获得 " << total_exp << " 经验！\n";
        } else {
            player.hp -= 15 * res.question_difficulty;
            std::cout << "错误！受到 " << 15*res.question_difficulty << " 点伤害！\n";
        }
        
        if (player.hp <= 0) {
            std::cout << "角色已倒下！游戏结束！\n";
            exit(0);
        }
    }
}
