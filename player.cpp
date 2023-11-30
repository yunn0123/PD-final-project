#include <iostream>
#include <cstdlib>
using namespace std;

const int INI_VAL = 10;
string printChange(int change);//印出數值變化

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
class Player {
private:
    //TODO: itemList 存拿到的隱藏道具
public:
    int value1, value2, value3, value4; // 四個主要數值
    Player() : value1(INI_VAL), value2(INI_VAL), value3(INI_VAL), value4(INI_VAL) {}

    void updateValues(int change1, int change2, int change3, int change4); //更新玩家的數值並印出
    char getChoice(); //return玩家的選擇 ("l" or "r" or 其他)
    void useItem(); //TODO: 從itemList使用道具
    void catchItem(); //TODO: 拿到道具，存進itemList

};
void Player::updateValues(int change1, int change2, int change3, int change4) {
    value1 += change1;
    value2 += change2;
    value3 += change3;
    value4 += change4;
    cout << "A: " << value1 << printChange(change1) << ' ';
    cout << "B: " << value2 << printChange(change2) << ' ';
    cout << "C: " << value3 << printChange(change3) << ' ';
    cout << "D: " << value4 << printChange(change4) << ' ';
    //checkForEndGame() by Ending?
}
char Player::getChoice(){
    char choice;
    cin >> choice;
    return choice;
}
