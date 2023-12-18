#include <windows.h>
#include <random>
#include <ctime>
using namespace std;
#include "headFile/card.h"
#include "headFile/description.h"
#include "headFile/character.h"
#include "headFile/ending.h"
#include "headFile/game1.h"
#include "headFile/item.h"
///
////////////////////////////
Player PLAYER;
int main() {
    ///  intialize the keyboard
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
        eventCardCnt = atoi(line.c_str()); // ?????¤ç«þ?¬¾?«þd?Öë?¤ç«þ
        //
        for(int j = 0 ; j < eventCardCnt ; j++){
            // ?±µ£u?«þ?????¤ç«þ?Öï?¬¾Ïü
            getline(eventFile, line, ' ');
            totalQuesInEvent = atoi(line.c_str());
            // ?¬¾?«þ}?Úí?¤ç«þ?¨¤?«þ
            getline(eventFile, EventNorration, '\n');
            // ????±µðE?²Ì?Úï?????Öê?¬¾?«þ?¤ç«þD?¤ç«þ?Úû?Úø
            getline(eventFile, name, ' ');
            // ?²Ì?Úï?????Öê?¬¾???«þ?Öï
            getline(eventFile, question, '\"');
            getline(eventFile, question, '\"');
            getline(eventFile, line, ' ');
            // ?¤ç«þ?µº?¤ç«þ??
            getline(eventFile, opt1, ' ');
            getline(eventFile, opt2, ' ');
            // ?¤ç«þ?µº?¤ç«þá[O?Úï?????Öê?¬¾?«þ
            getline(eventFile, line, ' ');
            leftChoice = atoi(line.c_str());
            getline(eventFile, line);
            rightChoice = atoi(line.c_str());
            eventCard.push_back(EventCard(name, totalQuesInEvent, EventNorration, question, opt1, opt2, leftChoice, rightChoice));
            // ?¬¾???«þ?Öï?¤ç«þ
            for (int i = 0; i < totalQuesInEvent ; i++){
                // ?Úû?Úø(?¤ç«þ?±¶?)
                getline(eventFile, name, ' ');
                // ?¤ç«þ?Öï
                getline(eventFile, question, '\"');
                getline(eventFile, question, '\"');
                getline(eventFile, line, ' ');
                // ?¤ç°Â?¤ç«þ
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
                // ?¤ç«þ?µº?¤ç°Â???¤ç«þ????????±µ?«þ?Öï
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

    while(true){
        // initialize
        PLAYER.restart = false;
        Game game(normalCard, randomCard, eventCard, PLAYER); // game setup
        int CardSeq = game.getTotalseq();
        int count = 0;
        // main process
        if(PLAYER.end){
            return 0;
        }
        //processing normal cards
        while(true)
        {
            game.displayQuestion();
            game.getChoice();
            count ++;
            if(PLAYER.restart){break;}
        }
        if(PLAYER.restart){
            continue;
        }

        //processing event cards
        // for(int i = 0; i < eventCard.size(); i++)
        // {
        //     for(int j = 0; j < eventCard[i].getCnt(); j++)
        //     {
        //         game.displayQuestion();
        //         game.getChoice();
        //     }
        // }
    }


    return 0;
}

