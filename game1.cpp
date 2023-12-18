#include "./headFile/game1.h"
using namespace std;

Game :: Game(vector<NormalCard> nCard, vector<RandomCard> rCard, vector<EventCard> eCard, Player& PLAYER)
{
    normalCard = nCard;
    //normalCard.assign(nCard.begin(), nCard.end());//try: normalCard = nCard;
	randomCard.assign(rCard.begin(), rCard.end());
	eventCard.assign(eCard.begin(), eCard.end());
	nCardIdx = 0;
	rCardIdx = 0;
	eCardIdx = 0;
    cout << "Timeless Redemption" << endl;
    cout << endl;
    cout << "---按 SPACE 開始遊戲、按ESC結束遊戲 ---" << endl;
    Sleep(30);
    while(true){
        if (GetAsyncKeyState(VK_SPACE) && 0x8001){
            keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
            while (GetAsyncKeyState(VK_SPACE) && 0x8001) {
                // Wait for the SPACE key to be released
                Sleep(50);
            }
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
                PLAYER.end = true;
                break;
            }
            if (user.compare("n") == 0){ // n
                cout << "---按 SPACE 開始遊戲---" << endl;
            }
        }
    }
}

void Game :: displayQuestion()
{
	normalCard[this->nCardIdx].GameCallingPrint();
}

void Game :: getChoice()
{
    Card& normalTmp = normalCard[this->nCardIdx];
    while(true){
        if(GetAsyncKeyState(VK_LEFT) && 0x8001){ // choose left
            keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
            normalTmp.nowChoice = 1;
            //PLAYER.updateValues(normalCard[this->nCardIdx].totalOpt[normalCard[this->nCardIdx].nowQuestion].val1[0], normalCard[this->nCardIdx].totalOpt[normalCard[this->nCardIdx].nowQuestion].val1[1], normalCard[this->nCardIdx].totalOpt[normalCard[this->nCardIdx].nowQuestion].val1[2], normalCard[this->nCardIdx].totalOpt[normalCard[this->nCardIdx].nowQuestion].val1[3]);
            break;
        }
        if(GetAsyncKeyState(VK_RIGHT) && 0x8001){ // choose right
            keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
            normalTmp.nowChoice = 2;
            //PLAYER.updateValues(normalCard[this->nCardIdx].totalOpt[normalCard[this->nCardIdx].nowQuestion].val2[0], normalCard[this->nCardIdx].totalOpt[normalCard[this->nCardIdx].nowQuestion].val2[1], normalCard[this->nCardIdx].totalOpt[normalCard[this->nCardIdx].nowQuestion].val2[2], normalCard[this->nCardIdx].totalOpt[normalCard[this->nCardIdx].nowQuestion].val2[3]);
            break;
        }
    }
    PLAYER.updateValues(&normalTmp);
    cout << "-------------------" << endl;
    // for next print
    normalTmp.nowQuestion += (normalTmp.nowQuestion + normalTmp.nowChoice);
    // if last question has asked, return to first question
    if(normalTmp.nowQuestion >= normalTmp.questionCnt){
        normalTmp.nowQuestion = 0;
        normalTmp.nowChoice = 0;
    }
    // if in the array but no question
    else if(normalTmp.totalOpt[normalTmp.nowQuestion].question.compare(" ") == 0){
        normalTmp.nowQuestion = 0;
        normalTmp.nowChoice = 0;
    }
}
