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
    name = "";
}
void Character :: catchItem(Item item){}
const bool* Character :: getItem(){}

////////////////////////////////////////////////////

void Player::catchItem(Item item)
{
    if(item.getName() == "母艦模型"){
        itemList[0] = 1;
    }
    else if(item.getName() == "火車模型"){
        itemList[1] = 1;
    }
    else if(item.getName() == "迷你政治家模型"){
        itemList[2] = 1;
    }
    else if(item.getName() == "雕像模型"){
        itemList[3] = 1;
    }
}


const bool* Player :: getItem()
{
    return itemList;

}

Player::Player(): Character(){
    name = "玩家";
    restart = false;
    end = false;
    for(int i = 0; i < 4; i++){
        itemList[i] = 0;
    }
}

void Player :: updateValues(Card* card){
    int change1 = 0;
    int change2 = 0;
    int change3 = 0;
    int change4 = 0;
    if(card->nowChoice == 1){
        change1 = card->totalOpt[card->nowQuestion].val1[0];
        change2 = card->totalOpt[card->nowQuestion].val1[1];
        change3 = card->totalOpt[card->nowQuestion].val1[2];
        change4 = card->totalOpt[card->nowQuestion].val1[3];
    }
    else if(card->nowChoice == 2){
        change1 = card->totalOpt[card->nowQuestion].val2[0];
        change2 = card->totalOpt[card->nowQuestion].val2[1];
        change3 = card->totalOpt[card->nowQuestion].val2[2];
        change4 = card->totalOpt[card->nowQuestion].val2[3];
    }
    value1 += change1;
    value2 += change2;
    value3 += change3;
    value4 += change4;

    cout << "<" <<  name << "> " << endl;
    cout << "經濟: " << value1 << printChange(change1) << "  ";
    cout << "聲望: " << value2 << printChange(change2) << "  ";
    cout << "外交: " << value3 << printChange(change3) << "  ";
    cout << "社會發展: " << value4 << printChange(change4) << "  ";
    cout << endl;
    Ending :: checkForEnding(PLAYER);
}