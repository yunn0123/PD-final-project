#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <random>
using namespace std;
//

#ifndef CARD_H

#define CARD_H

#include "description.h"
#include "character.h"
#include "item.h"
//#include "game1.h"

//class Game; // Forward declaration

class Card {
    friend class Game;
    protected:
        string name;
        int questionCnt;
        vector<Description> totalOpt; // array of option
        int nowQuestion;
        string descript;
        int nowChoice; // 紀錄this card上次的選擇
    public:
        Card();
        Card(const string name, const int quesCnt);
        ~Card();
        void setTotalOpt(const Description opt);
        string getName();
        int getCnt();
        void setDescript(const string des);
        virtual void GameCallingPrint() = 0;
};
////////////////////////////////////////////////
// 一般
class NormalCard : public Card{
    private:
    public:
        NormalCard();
        NormalCard(const string name, const int quesCnt);
        ~NormalCard();
        void setTotalOpt(const Description opt);
        void GameCallingPrint(); // 當game呼叫card，要印出的問題與選項 (可能有連續性問題)，game呼叫時傳入已經call該card幾次或是要call odd or even function
        int* getVal1(); // 回傳左邊選項的數值增減陣列
        int* getVal2();

};
////////////////////////////////////////////////
// 隨機(數值自行random)
class RandomCard : public Card{
    private:
    public:
        RandomCard();
        RandomCard(const string name, const int quesCnt);
        ~RandomCard();
        void setTotalOpt(const Description opt);
        void GameCallingPrint();

};
////////////////////////////////////////////////
// 事件(進入不可出來，除非選到特定的選項)
class EventCard : public Card{
    static int isEvent;    // 是否在event中
    static int isHappened; // 該event有出現過
    private:
        //
        string EventNorration; // 事件開始前的旁白
        //
        string EnterEventQues; // 第一個問題，是否要進入該事件
        string optLEFT, optRIGHT; // 是否要進入該事件的選項們
        bool isEnter[2]; // isEnter[0]: 左邊選項是否進入事件, isEnter[1]: 右邊選項是否進入事件
        //
        string EventEnd; // 事件失敗的旁白
        bool isDead;     // 事件失敗是否會死亡
        // 問題們
        vector<eventDes> totalEventOpt;
        ////////////// get item
        int itemQues, itemChoice;
        string ItemNorration;
        Item item;
        //// 判斷
        bool isEnterEvent();
    public:
        EventCard();
        EventCard(const string name, const int quesCnt);
        EventCard(const string name, const int quesCnt, const string EventNorration, const string EventDes, const string opt1, const string opt2, const bool left, const int right);
        //// setting
        void setTotalEventOpt(const eventDes opt);
        void setItem(const int itemQues, const int itemChoice, const string GetItemNorration, const string name);
        void setEnding(const string end, bool isDead);
        //// print
        void GameCallingPrint();
        //// destructor
        ~EventCard();

};

#endif
