#include <iostream>
#include <cstdlib>
#include <ctime>
#include "./headFile/character.h"
#include "./headFile/ending.h"
using namespace std;

string printChange(int change){
    string out = "";
    if(change > 0){
        out = "(+" + to_string(change) + ')';
    }
    else if(change < 0){
        out = '(' + to_string(change) + ')';
    }
    return out;
}
///////////////////////////////////////////////////
Character :: Character() : value1(INI_VAL), value2(INI_VAL), value3(INI_VAL), value4(INI_VAL) {
    chV1.push_back(INI_VAL);
    chV2.push_back(INI_VAL);
    chV3.push_back(INI_VAL);
    chV4.push_back(INI_VAL);
    name = "";
}
void Character :: catchItem(Item item){}
vector<Item> Character :: getItem(){}

////////////////////////////////////////////////////

void Player::catchItem(Item item)
{
    itemList.push_back(item);
}

int Character::getEnemyChoice(){}

vector<Item> Player :: getItem()
{
    return itemList;
}

Player::Player(): Character(){
    name = "玩家";
}

void Player :: updateValues(int change1, int change2, int change3, int change4)
{
    value1 += change1;
    value2 += change2;
    value3 += change3;
    value4 += change4;
    chV1.push_back(value1);
    chV2.push_back(value2);
    chV3.push_back(value3);
    chV4.push_back(value4);
    cout << "<" <<  name << "> " << endl;
    cout << "經濟: " << value1 << printChange(change1) << "  ";
    cout << "聲望: " << value2 << printChange(change2) << "  ";
    cout << "外交: " << value3 << printChange(change3) << "  ";
    cout << "社會發展: " << value4 << printChange(change4) << "  ";
    cout << endl;
    //
    Ending :: checkForEnding(*this);
}
/////////////////////////////////////////////
Enemy::Enemy(): Character(){
    name = "敵人";
}
void Enemy::updateValues(int change1, int change2, int change3, int change4)
{
    value1 += change1;
    value2 += change2;
    value3 += change3;
    value4 += change4;
    chV1.push_back(value1);
    chV2.push_back(value2);
    chV3.push_back(value3);
    chV4.push_back(value4);
    cout << "<" <<  name << "> " << endl;
    cout << "經濟: " << value1 << printChange(change1) << "  ";
    cout << "聲望: " << value2 << printChange(change2) << "  ";
    cout << "外交: " << value3 << printChange(change3) << "  ";
    cout << "社會發展: " << value4 << printChange(change4) << "  ";
    cout << endl;
    //
    // Ending :: checkForEnding(*this);
}
int Enemy::getEnemyChoice(){
    // Seed the random number generator
    srand(std::time(0));
    // Generate and return a random number (1 or 2)
    return (rand() % 2) + 1;
}

