#include "character.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

Character create_character(){
    Character player;
    std::cout << "输入角色名: ";
    std::getline(std::cin,player.name);
    player.strength = 1+ rand() % 3;
    player.agility=1+rand() % 3;
    return player;
};

void show_status(const Character &c){
    std::cout<< "\n===" << c.name << " ==="
        << "\n生命值: "<< c.hp
        << "\n敏捷" << c.agility
        << "\n知识等级:"
        << "\n 左值:Lv." << c.knowledge.lvalue_mastery
        << "\n 右值:Lv." << c.knowledge.rvalue_analysis
        << "\n 函数指示器:Lv." << c.knowledge.func_designator
        << "\n 类型转换:Lv." << c.knowledge.type_conversion
        << "\n=====================\n";

};
