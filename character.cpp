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
    if(item.getName() == "��ĥ�ҫ�"){
        itemList[0] = 1;
    }
    else if(item.getName() == "�����ҫ�"){
        itemList[1] = 1;
    }
    else if(item.getName() == "�g�A�F�v�a�ҫ�"){
        itemList[2] = 1;
    }
    else if(item.getName() == "�J���ҫ�"){
        itemList[3] = 1;
    }
}


const bool* Player :: getItem()
{
    return itemList;

}

Player::Player(): Character(){
    name = "���a";
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
    cout << "�g��: " << value1 << printChange(change1) << "  ";
    cout << "�n��: " << value2 << printChange(change2) << "  ";
    cout << "�~��: " << value3 << printChange(change3) << "  ";
    cout << "���|�o�i: " << value4 << printChange(change4) << "  ";
    cout << endl;
    Ending :: checkForEnding(PLAYER);
}