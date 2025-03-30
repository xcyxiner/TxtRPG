#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

    using namespace std;
struct Character{
    string name; 
    int hp;
    int strength;
    int agility;
};
Character create_character(){
    Character player;
    cout<<"give your name: ";
    getline(cin,player.name);
    srand(time(nullptr));
    player.hp=100;
    player.strength=1;
    player.agility=1;
    return player;
}
void show_status(const Character &c){
cout<<"\n* "<<c.name<<"'s info *"
    <<"\nhp: "<<c.hp
    <<"\nstrength: "<<c.strength
    <<"\nagility: "<<c.agility<<endl;
}

int main(){
    std::cout<<"start game!"<<endl;
    Character player=create_character();
    show_status(player);
    return 0;
}

