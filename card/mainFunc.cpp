#include "ALLimport.h"
///

////////////////////////////

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
                if (question.compare(" ") == 0){ 
                    Description opt = Description(" ");    
                    /// set card's description
                    normalCard[index].setTotalOpt(opt);
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
                    normalCard[index].setTotalOpt(opt);
                }
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
    //// cardText.txt
    // string randomCardPath = "./randomCard.txt";
    // ifstream randomCardFile(randomCardPath);
    // vector<RandomCard> randomCard; 
    // if (randomCardFile.is_open()){
    //     getline(randomCardFile, line, '\n');
    //     cardCnt = atoi(line.c_str());
    //     ///////////////////////////////////
    //     for(int j = 0 ; j < cardCnt ; j++){
    //         // quesCnt
    //         getline(randomCardFile, line, ' ');
    //         quesCnt = atoi(line.c_str());
    //         // name
    //         getline(randomCardFile, name, ' ');
    //         /// create card
    //         randomCard.push_back(RandomCard(name, quesCnt));
    //         /// create description
    //         for (int i = 0 ; i < quesCnt ; i++){
    //             // question
    //             getline(randomCardFile, question, '\"');
    //             getline(randomCardFile, question, '\"');
    //             if (question.compare(" ") == 0){ 
    //                 Description opt = Description(" ");
    //                 /// set card's description
    //                 normalCard[index].setTotalOpt(opt);
    //             }
    //             else{
    //                 // option
    //                 getline(randomCardFile, line, ' ');

    //                 getline(randomCardFile, opt1, ' ');
    //                 getline(randomCardFile, opt2, ' ');
    //                 /// store into description
    //                 Description opt = Description(question, opt1, opt2);
    //                 /// set card's description
    //                 normalCard[index].setTotalOpt(opt);
    //             }
    //         }
    //         // 下一個randomCard
    //         index++;
    //     }
    // }
    // else{
    //     cout << "RandomCardFile cannot open." << endl;
    //     return 0;
    // }


    // randomCardFile.close();
    ///////// description of card //////////////
    // string descriptPath = "./descript.txt";
    // ifstream desFile(descriptPath);
    // int desCnt = 0;
    // index = 0 ;
    // if(desFile.is_open()){
    //     getline(desFile, line, ' ');
    //     desCnt = atoi(line.c_str());
    //     getline(desFile, name, '\n');
    //     for(int i = 0 ; i < normalCard.size() ; i++){
    //         if(normalCard[i].getName().compare(name) == 0){
    //             index = i; // record the index, to add descript
    //         }
    //     }
    //     for(int i = 0; i < desCnt ; i++){
    //         getline(desFile, line);
    //         normalCard[index].setDescript(line);
    //     }

    // }
    // else{
    //     cout << "descript file cannot open." << endl;
    //     return 0;
    // }

    //// event.txt
    string eventPath = "./event.txt";
    ifstream eventFile(eventPath);
    vector<EventCard> eventCard;
    int eventCardCnt = 0, totalQuesInEvent = 0; 
    int leftChoice = 0, rightChoice = 0;
    bool isDead;
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
                // nextIndex
                getline(eventFile, line, ' ');
                leftChoice = atoi(line.c_str());
                getline(eventFile, line, ' ');
                rightChoice = atoi(line.c_str());
                eventDes opt = eventDes(question, opt1, opt2, val1, val2);
                opt.setNextIdex(leftChoice, rightChoice);
                eventCard[index].setTotalEventOpt(opt);
            }
            getline(eventFile, EventNorration, ' ');
            getline(eventFile, line);
            isDead = atoi(line.c_str());
            eventCard[index].setEnding(EventNorration, isDead);
            index++;
        }
    }
    else{
        cout << "eventFile cannot open." << endl;
        return 0;
    }
    eventFile.close();
    cout << "pause ENTER to start Game." << endl;
    //////////////////////////////////////////
    // store some card information, etc.
    // cout << "開始遊戲中.../" << endl;
    // Game game(numCards); // n(卡牌數)
    // game.start();

    ///// GameCallingPrint test /////
    bool a = normalCard[1].GameCallingPrint();
    cout << a << endl;
    // normalCard[0].GameCallingPrint();
    //
    // randomCard[0].GameCallingPrint();
    // randomCard[0].GameCallingPrint();
    //
    // eventCard[0].isEnterEvent();
    // eventCard[0].GameCallingPrint();
    ////////////
    return 0;
}

// main function 讀入資料、cout 一些遊戲開啟等字眼
// 主流程(game)會是不斷cin的過程(while(cin))
// 直到過關跑完動畫或是結束遊戲，用一個判斷式判斷是否跳出迴圈