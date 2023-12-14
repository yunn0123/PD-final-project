using namespace std;
#include "headFile/card.h"
#include "headFile/description.h"
#include "headFile/character.h"
#include "headFile/ending.h"
#include "headFile/game.h"
///
////////////////////////////
Player PLAYER;
int main() {
    /// initilalize the keyboard ///
    keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);

    ////////////////////////////////
    cout << "initialize the information.../" << endl;
    int quesCnt, val1[4], val2[4], index = 0, cardCnt;
    string operation, name, question, opt1, opt2;
    string line; //temp string to change str in int
    /////////// store card info //////////////
    //// cardText.txt
    string cardPath = "textFile/cardText.txt";
    ifstream cardFile(cardPath);
    vector<NormalCard> normalCard; 
    if (cardFile.is_open()){
        getline(cardFile, line, '\n');
        cardCnt = atoi(line.c_str());
        ///////////////////////////////////
        for(int j = 0 ; j < cardCnt ; j++){
            // quesCnt
            getline(cardFile, line, ' ');
            quesCnt = atoi(line.c_str());
            // name
            getline(cardFile, name);
            /// create card
            normalCard.push_back(NormalCard(name, quesCnt));
            /// create description
            for (int i = 0 ; i < quesCnt ; i++){
                // question
                getline(cardFile, question, '\"');
                getline(cardFile, question, '\"');
                if (question.compare(" ") == 0){ 
                    Description opt = Description(" ");    
                    /// set card's description
                    normalCard[j].setTotalOpt(opt);
                }
                else{    
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
                    normalCard[j].setTotalOpt(opt);
                }
            }
        }
    }
    else{
        cout << "CardFile cannot open." << endl;
        return 0;
    }


    cardFile.close();
    //// cardText.txt
    string randomCardPath = "textFile/randomCard.txt";
    ifstream randomCardFile(randomCardPath);
    vector<RandomCard> randomCard; 
    if (randomCardFile.is_open()){
        getline(randomCardFile, line, '\n');
        cardCnt = atoi(line.c_str());
        ///////////////////////////////////
        for(int j = 0 ; j < cardCnt ; j++){
            // quesCnt
            getline(randomCardFile, line, ' ');
            quesCnt = atoi(line.c_str());
            // name
            getline(randomCardFile, name);
            /// create card
            randomCard.push_back(RandomCard(name, quesCnt));
            /// create description
            for (int i = 0 ; i < quesCnt ; i++){
                // question
                getline(randomCardFile, question, '\"');
                getline(randomCardFile, question, '\"');
                if (question.compare(" ") == 0){ 
                    Description opt = Description(" ");
                    /// set card's description
                    normalCard[j].setTotalOpt(opt);
                }
                else{
                    // option
                    getline(randomCardFile, line, ' ');

                    getline(randomCardFile, opt1, ' ');
                    getline(randomCardFile, opt2);
                    /// store into description
                    Description opt = Description(question, opt1, opt2);
                    /// set card's description
                    randomCard[j].setTotalOpt(opt);
                }
            }
        }
    }
    else{
        cout << "RandomCardFile cannot open." << endl;
        return 0;
    }


    randomCardFile.close();
    //////////////////////////////////////////////
    //// event.txt
    string eventPath = "textFile/event.txt";
    ifstream eventFile(eventPath);
    vector<EventCard> eventCard;
    int eventCardCnt = 0, totalQuesInEvent = 0; 
    int leftChoice = 0, rightChoice = 0;
    int itemChoice, itemQues;
    bool isDead;
    string EventNorration, ItemNorration;
    //
    if(eventFile.is_open()){
        getline(eventFile, line, '\n');
        eventCardCnt = atoi(line.c_str()); // 總共的事件卡牌數
        // 
        for(int j = 0 ; j < eventCardCnt ; j++){
            // 該事件的總共問題數量 
            getline(eventFile, line, ' ');
            totalQuesInEvent = atoi(line.c_str()); 
            // 事件開始的旁白
            getline(eventFile, EventNorration, '\n');
            // 第一個要是否要進入事件問題的名字
            getline(eventFile, name, ' ');
            // 是否要進入事件的問題
            getline(eventFile, question, '\"');
            getline(eventFile, question, '\"');
            getline(eventFile, line, ' ');
            // 左右選擇
            getline(eventFile, opt1, ' ');
            getline(eventFile, opt2, ' ');
            // 左右選擇是否會進入事件
            getline(eventFile, line, ' ');
            leftChoice = atoi(line.c_str());
            getline(eventFile, line);
            rightChoice = atoi(line.c_str());
            eventCard.push_back(EventCard(name, totalQuesInEvent, EventNorration, question, opt1, opt2, leftChoice, rightChoice));
            // 事件的問題們
            for (int i = 0; i < totalQuesInEvent ; i++){
                // 名字(提問人)
                getline(eventFile, name, ' ');
                // 問題
                getline(eventFile, question, '\"');
                getline(eventFile, question, '\"');
                getline(eventFile, line, ' ');
                // 選項們
                getline(eventFile, opt1, ' ');
                getline(eventFile, opt2, ' ');
                // val1
                getline(eventFile, line, ',');
                val1[0] = atoi(line.c_str());
                getline(eventFile, line, ',');
                val1[1] = atoi(line.c_str());
                getline(eventFile, line, ',');
                val1[2] = atoi(line.c_str());
                getline(eventFile, line, ' ');
                val1[3] = atoi(line.c_str());
                // val2
                getline(eventFile, line, ',');
                val2[0] = atoi(line.c_str());
                getline(eventFile, line, ',');
                val2[1] = atoi(line.c_str());
                getline(eventFile, line, ',');
                val2[2] = atoi(line.c_str());
                getline(eventFile, line, ' ');
                val2[3] = atoi(line.c_str());
                // 左右選項會指到的下一個問題
                getline(eventFile, line, ' ');
                leftChoice = atoi(line.c_str());
                getline(eventFile, line);
                rightChoice = atoi(line.c_str());
                eventDes opt = eventDes(name, question, opt1, opt2, val1, val2);
                opt.setNextIdex(leftChoice, rightChoice);
                eventCard[j].setTotalEventOpt(opt);
            } // total question 
            // event ending
            getline(eventFile, EventNorration, ' ');
            getline(eventFile, line);
            isDead = atoi(line.c_str());
            eventCard[j].setEnding(EventNorration, isDead);
            // event item
            getline(eventFile, name, ' ');
            getline(eventFile, ItemNorration, ' ');
            getline(eventFile, line, ' ');
            itemQues = atoi(line.c_str());
            getline(eventFile, line);
            itemChoice = atoi(line.c_str());
            eventCard[j].setItem(itemQues, itemChoice, ItemNorration, name);
        }// this event card
    }
    else{
        cout << "eventFile cannot open." << endl;
        return 0;
    }
    eventFile.close();
    //////////////////////////////////////////////////////
    cout << "Timeless Redemption" << endl;
    cout << endl;
    cout << "---按 SPACE 開始遊戲---" << endl;
    while(true){
        if (GetAsyncKeyState(VK_SPACE) && 0x8001){
            keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
            // call game
            break;
        }
        if(GetAsyncKeyState(VK_ESCAPE) && 0x8001){ // esc
            keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);
            cout << "確定要離開嗎？" << endl;
            cout << "是(y) 否(n)" << endl;
            string user;
            cin >> user;
            if (user.compare("y") == 0){ // y
                return 0;
            }
            if (user.compare("n") == 0){ // n
                cout << "---按 SPACE 開始遊戲---" << endl;
            }
        }
    }
    //////////////////////////////////////////
    eventCard[0].GameCallingPrint();
    // Game game(numCards); // n(卡牌數)
    // game.start();

    return 0;
}

// main function 讀入資料、cout 一些遊戲開啟等字眼
// 主流程(game)會是不斷cin的過程(while(cin))
// 直到過關跑完動畫或是結束遊戲，用一個判斷式判斷是否跳出迴圈
