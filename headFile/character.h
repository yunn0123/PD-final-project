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


#include "card.h"
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
        virtual void updateValues(Card* card) = 0;
        void catchItem(Item item);
        const bool* getItem(); //return pointer pointed to itemList

};

class Player: public Character{
    friend class Ending;
    private:
        bool itemList[4]; //存拿到的隱藏道具(1: 拿到 0: 未拿到)
    public:
        bool restart;
        bool end;
        Player();
        void catchItem(Item item); //拿到道具，設定itemList中對應道具為0或1
        const bool* getItem(); //return pointer pointed to itemList
        void updateValues(Card* card);
};


extern Player PLAYER;

#endif