#include <windows.h>
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
        eventCardCnt = atoi(line.c_str()); // �`�@���ƥ�d�P��
        //
        for(int j = 0 ; j < eventCardCnt ; j++){
            // �Өƥ��`�@���D�ƶq
            getline(eventFile, line, ' ');
            totalQuesInEvent = atoi(line.c_str());
            // �ƥ�}�l���ǥ�
            getline(eventFile, EventNorration, '\n');
            // �Ĥ@�ӭn�O�_�n�i�J�ƥ���D���W�r
            getline(eventFile, name, ' ');
            // �O�_�n�i�J�ƥ󪺰��D
            getline(eventFile, question, '\"');
            getline(eventFile, question, '\"');
            getline(eventFile, line, ' ');
            // ���k���
            getline(eventFile, opt1, ' ');
            getline(eventFile, opt2, ' ');
            // ���k��ܬO�_�|�i�J�ƥ�
            getline(eventFile, line, ' ');
            leftChoice = atoi(line.c_str());
            getline(eventFile, line);
            rightChoice = atoi(line.c_str());
            eventCard.push_back(EventCard(name, totalQuesInEvent, EventNorration, question, opt1, opt2, leftChoice, rightChoice));
            // �ƥ󪺰��D��
            for (int i = 0; i < totalQuesInEvent ; i++){
                // �W�r(���ݤH)
                getline(eventFile, name, ' ');
                // ���D
                getline(eventFile, question, '\"');
                getline(eventFile, question, '\"');
                getline(eventFile, line, ' ');
                // �ﶵ��
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
                // ���k�ﶵ�|���쪺�U�@�Ӱ��D
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
    // cout << "Timeless Redemption" << endl;
    // cout << endl;
    // cout << "---�� SPACE �}�l�C��---" << endl;

    // while(true){
    //     if (GetAsyncKeyState(VK_SPACE) && 0x8001){
    //         keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
    //         // call game
    //         break;
    //     }
    //     if(GetAsyncKeyState(VK_ESCAPE) && 0x8001){ // esc
    //         keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);
    //         cout << "�T�w�n���}�ܡH" << endl;
    //         cout << "�O(y) �_(n)" << endl;
    //         string user;
    //         cin >> user;
    //         if (user.compare("y") == 0){ // y
    //             return 0;
    //         }
    //         if (user.compare("n") == 0){ // n
    //             cout << "---�� SPACE �}�l�C��---" << endl;
    //         }
    //     }
    // }
    //////////////////////////////////////////
    while(true){
        // initialize
        PLAYER.restart = false;
        Game game(normalCard, randomCard, eventCard, PLAYER);//game setup
        
        ///  keyboard 
        keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);

        // main process
        if(PLAYER.end){
            return 0;
        }
        //processing normal cards
        for(int i = 0; i < normalCard.size(); i++)
        {
            for(int j = 0; j < normalCard[i].getCnt(); j++)
            {
                game.displayQuestion();
                game.getChoice();
                if(PLAYER.restart){
                    break;
                }
            }
            if(PLAYER.restart){
                break;
            }

        }
        if(PLAYER.restart){
            continue;
        }

        //processing event cards
        for(int i = 0; i < eventCard.size(); i++)
        {
            for(int j = 0; j < eventCard[i].getCnt(); j++)
            {
                game.displayQuestion();
                game.getChoice();
            }
        }
    }


    return 0;
}

