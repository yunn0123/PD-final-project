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
#include "card.h"
//#include "ending.h"
class Ending;
/// player
const int INI_VAL = 25;
string printChange(int change);//印出數值變化

class Character {
    friend class Ending;
    protected:
        string name;
        int value1, value2, value3, value4; // 四個主要數值
    public:
        Character();
        //virtual void updateValues(int change1, int change2, int change3, int change4) = 0; //更新玩家的數值並印出
        virtual void updateValues(Card* card) = 0;
        int getEnemyChoice();
        void catchItem(Item item);
        const bool* getItem(); //return pointer pointed to itemList
        
};

class Player: public Character{
    private:
        bool itemList[4]; //存拿到的隱藏道具(1: 拿到 0: 未拿到)
    public:
        bool restart;
        bool end;
        Player();
        void catchItem(Item item); //拿到道具，設定itemList中對應道具為0或1
        const bool* getItem(); //return pointer pointed to itemList
        //void updateValues(int change1, int change2, int change3, int change4);
        void updateValues(Card* card);
};

class Enemy: public Character{
    public:
        Enemy();
        //void updateValues(int change1, int change2, int change3, int change4);
        void updateValues(Card* card);
        int getEnemyChoice();
};

extern Player PLAYER;

#endif