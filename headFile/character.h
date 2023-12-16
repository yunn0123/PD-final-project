#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <random>
using namespace std;
//
#ifndef CHARACTER_H
#define CHARACTER_H

#include "item.h"
#include "game.h"
#include "ending.h"

/// player
const int INI_VAL = 25;
string printChange(int change);//印出數值變化

class Character {
    friend class Ending;
    protected:
        string name;
        int value1, value2, value3, value4; // 四個主要數值
        vector<int> chV1, chV2, chV3, chV4;
    public:
        Character();
        virtual void updateValues(int change1, int change2, int change3, int change4) = 0; //更新玩家的數值並印出
        int getEnemyChoice();
        void catchItem(Item item);
        vector<Item> getItem();
        //void useItem(); //TODO: 從itemList使用道具
};

class Player: public Character{
    private:
        vector<Item>itemList; //存拿到的隱藏道具
    public:
        Player();
        void catchItem(Item item); //拿到道具，存進itemList
        vector<Item> getItem();
        void updateValues(int change1, int change2, int change3, int change4);
};

class Enemy: public Character{
    public:
        Enemy();
        void updateValues(int change1, int change2, int change3, int change4);
        int getEnemyChoice();
};

extern Player PLAYER;

#endif