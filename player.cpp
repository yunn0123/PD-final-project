#include <iostream>
#include <cstdlib>
#include <vector>
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
public:
    //TODO: itemList 存拿到的隱藏道具
    int choiceList[100] = {0};   //針對有兩個選項的Card，用陣列存player從遊戲一開始到現在的選擇(1為左，2為右) ->處理連續卡牌
    int value1, value2, value3, value4; // 四個主要數值
    vector<int> chV1, chV2, chV3, chV4; //存四個數值遊戲期間變化

    Player() : value1(INI_VAL), value2(INI_VAL), value3(INI_VAL), value4(INI_VAL) {
        chV1.push_back(INI_VAL);
        chV2.push_back(INI_VAL);
        chV3.push_back(INI_VAL);
        chV4.push_back(INI_VAL);
    }

    void updateValues(int change1, int change2, int change3, int change4); //更新玩家的數值並印出
    // char getChoice(); //return玩家的選擇 ("l" or "r" or 其他)
    // void useItem(); //TODO: 從itemList使用道具
    // void catchItem(); //TODO: 拿到道具，存進itemList

};
void Player::updateValues(int change1, int change2, int change3, int change4) {
    value1 += change1;
    value2 += change2;
    value3 += change3;
    value4 += change4;
    chV1.push_back(value1);
    chV2.push_back(value2);
    chV3.push_back(value3);
    chV4.push_back(value4);
    cout << "A: " << value1 << printChange(change1) << ' ';
    cout << "B: " << value2 << printChange(change2) << ' ';
    cout << "C: " << value3 << printChange(change3) << ' ';
    cout << "D: " << value4 << printChange(change4) << ' ' << endl;

    //checkForEndGame() by Ending?
}
// char Player::getChoice(){
//     char choice;
//     cin >> choice;
//     return choice;
// }


