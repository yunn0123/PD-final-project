#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <random>
using namespace std;

#ifndef DESCRIPTION_H
#define DESCRIPTION_H

class Description{
    friend class Card;
    friend class NormalCard;
    friend class RandomCard;
    friend class EventCard;
    friend class Game;
    friend class Player;
    friend class Enemy;
    protected:
        string question;
        string option1;
        string option2;
        int val1[4];
        int val2[4];
        bool eff1[4]; // 會影響哪個數值
        bool eff2[4];
    public:
        Description();
        // 給沒有敘述的
        Description(const string q); // 傳入空格
        // 給有敘述的
        Description(const string q, const string opt1, const string opt2, const int val1[4], const int val2[4]);
        // 給隨機卡牌
        Description(const string q, const string opt1, const string opt2);
};

class eventDes : public Description{
    friend class EventCard;
    private:
        int nextIndex[2];
        string name;
    public:
        eventDes(const string name, const string q, const string opt1, const string opt2, const int val1[4], const int val2[4]);
        void setNextIdex(const int left, const int right);
        int getLeftInd();
        int getRightInd();
        string getName();
};
///

#endif