#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
using namespace std;

class Description{
    friend class Card;
    friend class NormalCard; 
    friend class NorrationCard; 
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
       Description(const string q, const string opt1, const string opt2, const int val1[4], const int val2[4]): question(q), option1(opt1), option2(opt2){
            for(int i = 0; i < 4 ; i++){
                this->val1[i] = val1[i];
                this->val2[i] = val2[i];
                if (val1[i] != 0){
                    eff1[i] = 1;
                }
                else{
                    eff1[i] = 0;
                }
                if (val2[i] != 0){
                    eff2[i] = 1;
                }
                else {
                    eff2[i] = 0;
                }
            }
        };

};
class eventDes : public Description{
    friend class eventCard;
    private:
        int nextIndex[2];
        string name;
    public:
        eventDes(const string q, const string opt1, const string opt2, const int val1[4], const int val2[4]) : Description(q, opt1, opt2, val1, val2){};
        void setNextIdex(const int left, const int right){
            nextIndex[0] = left;
            nextIndex[1] = right;
        }
};
/////////////////////////////////

// player need to friend card
class Card {
    protected:
        string name;
        int questionCnt;
        vector<Description> totalOpt; // array of option
        int nowQuestion;
        string descript;
        int nowChoice; // 紀錄this card上次的選擇
    public:
        Card() {};
        Card(const string name, const int quesCnt) : name(name), questionCnt(quesCnt){
            nowQuestion = 0;
            descript = "";
            nowChoice = 0;
        };
        ~Card() {};
        void setTotalOpt(const Description opt){
            totalOpt.push_back(opt);
        };
        string getName() { return name;};
        void setDescript(const string des){descript = des;};
        virtual void GameCallingPrint() = 0;
        void setNowChoice(const int choice) {nowChoice = choice;}
        int* getVal1(); // 回傳左邊選項的數值增減陣列
        int* getVal2(); // 回傳右邊選項的數值增減陣列
};

void Card :: GameCallingPrint(){ // 取用前/後應設定nowChoice
    // // choice: game傳入玩家選擇
    // // 左 = 1 ，右 = 2
    // nowQuestion += (nowChoice + nowQuestion); 
    // if(nowQuestion >= questionCnt){
    //     nowQuestion = 0;
    // }
    // cout << name << ": " << totalOpt[nowQuestion].question << endl; 
    // cout << totalOpt[nowQuestion].option1 << " (L)" << " -> effect ";
    // // effect what value, print out
    // if(totalOpt[nowQuestion].eff1[0]){
    //     cout << "A ";
    // }
    // if(totalOpt[nowQuestion].eff1[1]){
    //     cout << "B ";
    // }
    // if(totalOpt[nowQuestion].eff1[2]){
    //     cout << "C ";
    // }
    // if(totalOpt[nowQuestion].eff1[3]){
    //     cout << "D ";
    // }

    // cout << "             " ;

    // cout <<  totalOpt[nowQuestion].option2 << " (R)" << " -> effect ";
    // // effect what value, print out
    // if(totalOpt[nowQuestion].eff2[0]){
    //     cout << "A ";
    // }
    // if(totalOpt[nowQuestion].eff2[1]){
    //     cout << "B ";
    // }
    // if(totalOpt[nowQuestion].eff2[2]){
    //     cout << "C ";
    // }
    // if(totalOpt[nowQuestion].eff2[3]){
    //     cout << "D ";
    // }
    // cout << endl;
}
////////////////////////////////////////////////
// 一般
class NormalCard : public Card{
    private:
    public:
        NormalCard() {};
        NormalCard(const string name, const int quesCnt) : Card(name, quesCnt){
            nowQuestion = 0;
            descript = "";
            nowChoice = 0;
        };

        ~NormalCard() {};
        void setTotalOpt(const Description opt){
            totalOpt.push_back(opt);
        };
        void GameCallingPrint(); // 當game呼叫card，要印出的問題與選項 (可能有連續性問題)，game呼叫時傳入已經call該card幾次或是要call odd or even function
        int* getVal1(); // 回傳左邊選項的數值增減陣列
        int* getVal2(); 

};
void NormalCard :: GameCallingPrint()
{
    // choice: game傳入玩家選擇
    // 左 = 1 ，右 = 2
    // 0 -> 1,2  (+1 , +2) 0
    // 1 -> 3,4  (+2 , +3) 1
    // 2 -> 5,6  (+3 , +4) 1
    // 3 -> 7,8  (+4 , +5) 2
    nowQuestion += (nowQuestion + nowChoice);
    // if last question has asked, return first question
    if(nowQuestion >= questionCnt){
        nowQuestion = 0;
    }
    cout << name << ": " << totalOpt[nowQuestion].question << endl; 
    cout << totalOpt[nowQuestion].option1 << " (L)" << " -> effect ";
    // effect what value, print out
    if(totalOpt[nowQuestion].eff1[0]){
        cout << "A ";
    }
    if(totalOpt[nowQuestion].eff1[1]){
        cout << "B ";
    }
    if(totalOpt[nowQuestion].eff1[2]){
        cout << "C ";
    }
    if(totalOpt[nowQuestion].eff1[3]){
        cout << "D ";
    }

    cout << "             " ;

    cout <<  totalOpt[nowQuestion].option2 << " (R)" << " -> effect ";
    // effect what value, print out
    if(totalOpt[nowQuestion].eff2[0]){
        cout << "A ";
    }
    if(totalOpt[nowQuestion].eff2[1]){
        cout << "B ";
    }
    if(totalOpt[nowQuestion].eff2[2]){
        cout << "C ";
    }
    if(totalOpt[nowQuestion].eff2[3]){
        cout << "D ";
    }
    cout << endl;
}
////////////////////////////////////////////////
// 旁白(連續旁白、無數值增減)
class NorrationCard : public Card{
    private:
        string* des;
    public:
        NorrationCard() {};
        NorrationCard(const string name, const int quesCnt) : Card(name, quesCnt){
            nowQuestion = 0;
            descript = "";
            des = new string[quesCnt];
        };
        
        ~NorrationCard() {
            delete [] des;
            des = nullptr;
        };
        void setTotalOpt(const Description opt){
            totalOpt.push_back(opt);
        };
        void GameCallingPrint();

};
void NorrationCard :: GameCallingPrint(){
    for(int i = 0 ; i < questionCnt ; i++){
        cout << des[i] << endl;
        while(!(GetAsyncKeyState(VK_SPACE) && 0x8000)){ // 等待玩家按下空白鍵
            Sleep(100);  // 100秒後，自動跳出迴圈
        }
    }
}
////////////////////////////////////////////////
// 事件(進入不可出來，除非選到特定的選項)
class EventCard : public Card{
    static int isEvent;
    private:
        int contiVal[4]; // 持續變化的數值(可不用，就全是0)
        string EnterEvent; // 第一張敘述，是否要進入該事件
        string EventNorration; // 進入事件的旁白
        bool isEnter[2]; // isEnter[0]: 左邊選項是否進入事件, isEnter[1]: 右邊選項是否進入事件
        vector<eventDes> totalEventOpt;
    public:
        EventCard() {};
        EventCard(const string name, const int quesCnt) : Card(name, quesCnt){
            nowQuestion = 0;
            descript = "";
        };
        EventCard(const string name, const int quesCnt, const string EventNorration, const string EnterEvent, const bool left, const int right){
            this->name = name;
            questionCnt = quesCnt;
            this->EventNorration = EventNorration;
            this->EnterEvent = EnterEvent;
            isEnter[0] = left;
            isEnter[1] = right;
        };
        //// setting
        void setTotalEventOpt(const eventDes opt){
            totalEventOpt.push_back(opt);
        };
        void setIsEnter(const bool arr[2], const string EventDes, const string EventNorration){ // 設定進入事件的必要問題
            isEnter[0] = arr[0];
            isEnter[1] = arr[1];
            EnterEvent = EventDes;
            this->EventNorration = EventNorration;
        };
        void setContiVal(const int val[4]){
            for(int i = 0 ; i < 3 ; i++){
                contiVal[i] = val[i];
            }
        };
        //// 判斷
        bool isEnterEvent(){ // choice: 選擇左邊: 傳入0，選擇右邊: 傳入1
            cout << name << ": " << EnterEvent << endl;
            if (GetAsyncKeyState(VK_LEFT) && 0x8001){ // left
                if(isEnter[0]){
                    cout << EventNorration << endl;
                    isEvent = 1;
                    return 1;
                }
            }
            else if (GetAsyncKeyState(VK_RIGHT) && 0x8001){
                if(isEnter[1]){
                    cout << EventNorration << endl;
                    isEvent = 1;
                    return 1;
                }
            }
            return 0;
        };
        //// print
        void GameCallingPrint(); 
        //// get value
        int* getVal1(){}; // 回傳左邊選項的數值增減陣列
        int* getVal2(){};
        //// destructor
        ~EventCard() {}; 

};
int EventCard :: isEvent = 0;
void EventCard :: GameCallingPrint(){
    // 迴圈印出，直到user決定離開
    // 紀錄離開條件
    // 紀錄迴圈起始點
    while(nowQuestion < questionCnt && isEvent){
        
        cout << name << ": " << totalOpt[nowQuestion].question << endl; 
        cout << totalOpt[nowQuestion].option1 << " (L)" << " -> effect ";
        // effect what value, print out
        if(totalOpt[nowQuestion].eff1[0]){
            cout << "A ";
        }
        if(totalOpt[nowQuestion].eff1[1]){
            cout << "B ";
        }
        if(totalOpt[nowQuestion].eff1[2]){
            cout << "C ";
        }
        if(totalOpt[nowQuestion].eff1[3]){
            cout << "D ";
        }

        cout << "             " ;

        cout <<  totalOpt[nowQuestion].option2 << " (R)" << " -> effect ";
        // effect what value, print out
        if(totalOpt[nowQuestion].eff2[0]){
            cout << "A ";
        }
        if(totalOpt[nowQuestion].eff2[1]){
            cout << "B ";
        }
        if(totalOpt[nowQuestion].eff2[2]){
            cout << "C ";
        }
        if(totalOpt[nowQuestion].eff2[3]){
            cout << "D ";
        }
        // call Player value change
        // updateValues(val[0], val[1], val[2], val[3]);
        

    }
    

}
///////////////////////////////////////////
int main() {
    cout << "initialize the information.../" << endl;
    int quesCnt, val1[4], val2[4], index = 0, cardCnt;
    string operation, name, question, opt1, opt2;
    string line; //temp string to change str in int

    /////////// store card info //////////////
    //// cardText.txt
    string cardPath = "./cardText.txt";
    ifstream cardFile(cardPath);
    vector<NormalCard> normalCard; 
    if (cardFile.is_open()){
        // file 總共行數
        getline(cardFile, line, '\n');
        cardCnt = atoi(line.c_str());
        ///////////////////////////////////
        for(int j = 0 ; j < cardCnt ; j++){
            // quesCnt
            getline(cardFile, line, ' ');
            quesCnt = atoi(line.c_str());
            // name
            getline(cardFile, name, ' ');
            /// create card
            normalCard.push_back(NormalCard(name, quesCnt));
            /// create description
            for (int i = 0 ; i < quesCnt ; i++){
                // question
                getline(cardFile, question, '\"');
                getline(cardFile, question, '\"');
                // option
                getline(cardFile, line, ' ');

                getline(cardFile, opt1, ' ');
                getline(cardFile, opt2, ' ');
                // val1
                getline(cardFile, line, ',');
                val1[0] = atoi(line.c_str());
                getline(cardFile, line, ',');
                val1[1] = atoi(line.c_str());
                getline(cardFile, line, ',');
                val1[2] = atoi(line.c_str());
                getline(cardFile, line, ' ');
                val1[3] = atoi(line.c_str());
                // val2
                getline(cardFile, line, ',');
                val2[0] = atoi(line.c_str());
                getline(cardFile, line, ',');
                val2[1] = atoi(line.c_str());
                getline(cardFile, line, ',');
                val2[2] = atoi(line.c_str());
                getline(cardFile, line, '\n');
                val2[3] = atoi(line.c_str());
                /// store into description
                Description opt = Description(question, opt1, opt2, val1, val2);
                /// set card's description
                normalCard[index].setTotalOpt(opt);
            }
            // 下一個normalCard
            index++;
        }
    }
    else{
        cout << "CardFile cannot open." << endl;
        return 0;
    }


    cardFile.close();
    ///////// description of card //////////////
    string descriptPath = "./descript.txt";
    ifstream desFile(descriptPath);
    int desCnt = 0;
    index = 0 ;
    if(desFile.is_open()){
        getline(desFile, line, ' ');
        desCnt = atoi(line.c_str());
        getline(desFile, name, '\n');
        for(int i = 0 ; i < normalCard.size() ; i++){
            if(normalCard[i].getName().compare(name) == 0){
                index = i; // record the index, to add descript
            }
        }
        for(int i = 0; i < desCnt ; i++){
            getline(desFile, line);
            normalCard[index].setDescript(line);
        }

    }
    else{
        cout << "descript file cannot open." << endl;
        return 0;
    }
    //// event.txt
    string eventPath = "./event.txt";
    ifstream eventFile(eventPath);
    vector<EventCard> eventCard;
    int eventCardCnt = 0, totalQuesInEvent = 0; 
    int leftChoice = 0, rightChoice = 0;
    index = 0;
    string EventNorration;
    if(eventFile.is_open()){
        getline(eventFile, line, '\n');
        eventCardCnt = atoi(line.c_str());
        for(int i = 0 ; i < eventCardCnt ; i++){
            // total number of cards 
            getline(eventFile, line, ' ');
            eventCardCnt = atoi(line.c_str());
            // 事件開始的旁白
            getline(eventFile, EventNorration, '\n');
            // 第一個要是否要進入事件的問題
            getline(eventFile, name, ' ');
            // question
            getline(eventFile, question, '\"');
            getline(eventFile, question, '\"');
            getline(eventFile, line, ' ');
            // option
            getline(eventFile, opt1, ' ');
            getline(eventFile, opt2, ' ');
            // isEnter
            getline(eventFile, line, ' ');
            leftChoice = atoi(line.c_str());
            getline(eventFile, line, ' ');
            rightChoice = atoi(line.c_str());
            eventCard.push_back(EventCard(name, eventCardCnt, EventNorration, question, leftChoice, rightChoice));
            for (int i = 0; i < eventCardCnt ; i++){
                // name
                getline(eventFile, name, ' ');
                // question
                getline(eventFile, question, '\"');
                getline(eventFile, question, '\"');
                getline(eventFile, line, ' ');
                // option
                getline(eventFile, opt1, ' ');
                getline(eventFile, opt2, ' ');
                // val1
                getline(cardFile, line, ',');
                val1[0] = atoi(line.c_str());
                getline(cardFile, line, ',');
                val1[1] = atoi(line.c_str());
                getline(cardFile, line, ',');
                val1[2] = atoi(line.c_str());
                getline(cardFile, line, ' ');
                val1[3] = atoi(line.c_str());
                // val2
                getline(cardFile, line, ',');
                val2[0] = atoi(line.c_str());
                getline(cardFile, line, ',');
                val2[1] = atoi(line.c_str());
                getline(cardFile, line, ',');
                val2[2] = atoi(line.c_str());
                getline(cardFile, line, ' ');
                val2[3] = atoi(line.c_str());
                // nextIndex
                getline(eventFile, line, ' ');
                leftChoice = atoi(line.c_str());
                getline(eventFile, line, ' ');
                rightChoice = atoi(line.c_str());
                eventDes opt = eventDes(question, opt1, opt2, val1, val2);
                opt.setNextIdex(leftChoice, rightChoice);
                eventCard[index].setTotalEventOpt(opt);
            }
            index++;
        }
    }
    else{
        cout << "eventFile cannot open." << endl;
    }
    // eventCard[0].isEnterEvent();
    // eventCard[0].GameCallingPrint();
    eventFile.close();
    cout << "pause ENTER to start Game." << endl;
    //////////////////////////////////////////
    // store some card information, etc.
    // cout << "開始遊戲中.../" << endl;
    // Game game(numCards); // n(卡牌數)
    // game.start();
    return 0;
}

// main function 讀入資料、cout 一些遊戲開啟等字眼
// 主流程(game)會是不斷cin的過程(while(cin))
// 直到過關跑完動畫或是結束遊戲，用一個判斷式判斷是否跳出迴圈
