#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <random>
using namespace std;

class Description{
    friend class Card;
    friend class NormalCard; 
    friend class RandomCard; 
    friend class EventCard;
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
        eventDes(const string q, const string opt1, const string opt2, const int val1[4], const int val2[4]);
        void setNextIdex(const int left, const int right);
};
///

class Card {
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
        void setDescript(const string des);
        virtual bool GameCallingPrint() = 0;
        void setNowChoice(const int choice);
        int* getVal1(); // 回傳左邊選項的數值增減陣列
        int* getVal2(); // 回傳右邊選項的數值增減陣列
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
        bool GameCallingPrint(); // 當game呼叫card，要印出的問題與選項 (可能有連續性問題)，game呼叫時傳入已經call該card幾次或是要call odd or even function
        int* getVal1(); // 回傳左邊選項的數值增減陣列
        int* getVal2(); 

};
////////////////////////////////////////////////
// 隨機(數值自行random)
class RandomCard : public Card{
    private:
        string* des;
    public:
        RandomCard();
        RandomCard(const string name, const int quesCnt);
        
        ~RandomCard();
        void setTotalOpt(const Description opt);
        bool GameCallingPrint();

};
////////////////////////////////////////////////
// 事件(進入不可出來，除非選到特定的選項)
class EventCard : public Card{
    static int isEvent;    // 是否在event中
    static int isHappened; // 該event有出現過
    private:
        // int contiVal[4]; // 持續變化的數值(可不用，就全是0)
        string EnterEvent; // 第一張敘述，是否要進入該事件
        string EventNorration; // 進入事件的旁白
        string EventEnd; // 事件失敗的旁白
        bool isDead; // 事件失敗是否會死亡
        bool isEnter[2]; // isEnter[0]: 左邊選項是否進入事件, isEnter[1]: 右邊選項是否進入事件
        vector<eventDes> totalEventOpt;
    public:
        EventCard();
        EventCard(const string name, const int quesCnt);
        EventCard(const string name, const int quesCnt, const string EventNorration, const string EnterEvent, const bool left, const int right);
        //// setting
        void setTotalEventOpt(const eventDes opt);
        void setIsEnter(const bool arr[2], const string EventDes, const string EventNorration);
        void setEnding(const string end, bool isDead);
        void setContiVal(const int val[4]);
        //// 判斷
        bool isEnterEvent();
        //// print
        bool GameCallingPrint(); 
        //// get value
        int* getVal1(); // 回傳左邊選項的數值增減陣列
        int* getVal2();
        //// destructor
        ~EventCard(); 

};

/// player
const int INI_VAL = 10;
string printChange(int change);//印出數值變化

class Player {
    private:
        //TODO: itemList 存拿到的隱藏道具
        int choiceList[100] = {0};   //針對有兩個選項的Card，用陣列存player從遊戲一開始到現在的選擇(1為左，2為右) ->處理連續卡牌
    public:
        int value1, value2, value3, value4; // 四個主要數值
        vector<int> chV1, chV2, chV3, chV4; //存四個數值遊戲期間變化
        Player() : value1(INI_VAL), value2(INI_VAL), value3(INI_VAL), value4(INI_VAL) {}

        void updateValues(int change1, int change2, int change3, int change4); //更新玩家的數值並印出
        char getChoice(); //return玩家的選擇 ("l" or "r" or 其他)
        void useItem(); //TODO: 從itemList使用道具
        void catchItem(); //TODO: 拿到道具，存進itemList

};
///////////////////////////////////////////
class Ending {
    public:
        // 檢查並觸發遊戲結局
        static void checkForEnding(Player& player, Game& game);
    private:
        // 檢查玩家數值是否平衡
        static bool isValuesBalanced(Player& player, int minVal, int maxVal);

        // 檢查是否達到普通結局條件
        static bool isNormalEndingAchieved(Game& game);

        // 檢查是否解鎖隱藏結局（要看有沒有特殊道具）
        static bool isHiddenEndingUnlocked(Player& player);

        // 重啟結局
        static void restartEnding();

        // 普通結局
        static void normalEnding();

        // 隱藏結局
        static void hiddenEnding();
};
///////////////////////////////////////////////////
class Game {};
Player PLAYER = Player();
