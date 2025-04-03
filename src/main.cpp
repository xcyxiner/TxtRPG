#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.h"
#include "monster.h"
#include "game_logic.h"

using namespace std;
int main(){
    srand(time(nullptr));
    std::cout<<"=== C++知识大冒险 ===\n"<<endl;
    Character player=create_character();
    show_status(player);

       auto campaign = generate_campaign();
    for (auto& monster : campaign) {
        knowledge_battle(player, monster);
        show_status(player);
        
        std::cout << "\n=== 战斗记录 ===\n";
        for (const auto& log : player.battle_log) {
            std::cout << log.to_string() << std::endl;
        }
    }

    std::cout << "\n恭喜通关！最终状态：";
    show_status(player); 
    return 0;
}

