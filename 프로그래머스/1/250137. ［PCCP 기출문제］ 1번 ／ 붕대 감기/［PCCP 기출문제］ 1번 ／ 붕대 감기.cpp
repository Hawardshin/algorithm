#include <string>
#include <vector>
#include<iostream>
using namespace std;
// t*x + y
int getHeal(int time, int cast_time, int heal_per_sec, int addtion){
    int cast_n = time/cast_time;//몇번 시전할 수 있는지.
    return (time * heal_per_sec) + (cast_n *addtion);
}

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int max_health = health;
    int bef_time = 0;
    for(int i=0;i<attacks.size();i++){
        int heal = getHeal(attacks[i][0] - bef_time, 
                           bandage[0], bandage[1], bandage[2]);
        bef_time = attacks[i][0]+1;
        cout <<"heal:"<< heal <<"\n";
        health += heal;
        health = min(health,max_health);
        cout<<"after heal:" << health << "\n";
        health-=attacks[i][1];
        if (health <= 0)
            return -1;
        cout << "after attack: " << health<<"\n";
    }
    return health;
}