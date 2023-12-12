#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <random>
#include "./headFile/item.h"
using namespace std;
//
#ifndef PLAYER_H
#define PLAYER_H

// #include "ending.h"

/// player
const int INI_VAL = 25;
string printChange(int change);//印出數值變化

class Player {
    private:
        vector<Item>itemList; //存拿到的隱藏道具
        //int choiceList[100] = {0};   //針對有兩個選項的Card，用陣列存player從遊戲一開始到現在的選擇(1為左，2為右) ->處理連續卡牌
        vector<int> chV1, chV2, chV3, chV4;
    public:
        int value1, value2, value3, value4; // 四個主要數值
        Player();

        void updateValues(int change1, int change2, int change3, int change4, Game& game); //更新玩家的數值並印出
        char getChoice(); //return玩家的選擇 ("l" or "r" or 其他)
        void useItem(); //TODO: 從itemList使用道具
        void catchItem(Item); //拿到道具，存進itemList

};

extern Player PLAYER;

#endif
