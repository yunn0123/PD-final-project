#include "./headFile/game1.h"
using namespace std;
Game :: Game(vector<Card *> nrCard, vector<EventCard> eCard, Player& PLAYER)
{
    // random the nrCard's seq once if player dead
    srand( time(NULL) );
    for (int i = 0; i < totalCardNumNeedToProcess ; i++){
        int seq = rand();
        cardAppearSeq.push_back( seq % (nrCard.size()) );
    }
    ///////////////////////////////////////////////////////

    this->nrCard = nrCard;
    this->eventCard = eCard;
	nrIdx = 0;
	eCardIdx = 0;
    cout << "           Regal Dominion" << endl;
    cout << endl;
    cout << "--- 按SPACE開始遊戲 | 按ESC結束遊戲 ---" << endl;
    Sleep(30);
    while(true){
        if (GetAsyncKeyState(VK_SPACE) && 0x8001){
            // avoid previous click is taken
            keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
            break;
        }
        if(GetAsyncKeyState(VK_ESCAPE) && 0x8001){ // esc
            keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);
            cout << "是否離開遊戲？" << endl;
            cout << "是(y) 否(n)" << endl;
            string user;
            cin >> user;
            if (user.compare("y") == 0){ // y
                PLAYER.end = true;
                break;
            }
            if (user.compare("n") == 0){ // n
                cout << "--- 按SPACE開始遊戲 | 按ESC結束遊戲 ---" << endl;
            }
        }
    }
}
//
void Game :: displayQuestion()
{
    if (nrIdx < totalCardNumNeedToProcess){
        nrCard[this->cardAppearSeq[nrIdx]]->GameCallingPrint();
    }
    else{
        bool hasAllItem = true;
        const bool* itemList = PLAYER.getItem();
        for(int i = 0; i < 4; i++){
            if(itemList[i] == 0){
                hasAllItem = false;
                break;
            }
        }
        if(hasAllItem){
            Ending::hiddenEnding();
            Ending :: normalEnding();
        }
        else{
            Ending :: normalEnding();
        }
        PLAYER.end = 1;
        exit(0);
    }
}
void Game :: displayEQuestion()
{
    if (eCardIdx < 4){
        event();
    }
    else{
        Ending :: normalEnding();
        PLAYER.end = 1;
        exit(0);
    }
}
//
void Game :: getChoice()
{
    Card* tempCard = nrCard[this->cardAppearSeq[nrIdx]];
    while(true){

        if(GetAsyncKeyState(VK_LEFT) && 0x8001){ // choose left
            keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
            tempCard->nowChoice = 1;
            break;
        }
        if(GetAsyncKeyState(VK_RIGHT) && 0x8001){ // choose right
            keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
            tempCard->nowChoice = 2;
            break;
        }
    }
    PLAYER.updateValues(tempCard);
    //
    cout << "-------------------" << endl;
    // for next print
    tempCard->nowQuestion += (tempCard->nowQuestion + tempCard->nowChoice);
    // if last question has asked, return to first question
    if(tempCard->nowQuestion >= tempCard->questionCnt){
        tempCard->nowQuestion = 0;
        tempCard->nowChoice = 0;
        tempCard->already_A_Round = 1;
    }
    // if in the array but no question
    else if(tempCard->totalOpt[tempCard->nowQuestion].question.compare(" ") == 0){
        tempCard->nowQuestion = 0;
        tempCard->nowChoice = 0;
        tempCard->already_A_Round = 1;
    }
    //
    nrIdx ++;

}
void Game :: event()
{
    EventCard event = eventCard[this->eCardIdx];
    event.isEnterEvent();
    while(event.nowQuestion < event.questionCnt && event.isEvent){
        cout << event.totalEventOpt[event.nowQuestion].getName() << ": " << event.totalEventOpt[event.nowQuestion].question << endl;
        //
        cout << event.totalEventOpt[event.nowQuestion].option1 << " (左)";
        cout << endl ;
        cout <<  event.totalEventOpt[event.nowQuestion].option2 << " (右)";
        cout << endl;
        // update value and item
        while(true){
            //
            if(GetAsyncKeyState(VK_LEFT) && 0x8001){ // choose left
                keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
                event.nowChoice = 1;
                // item check
                if (event.nowQuestion == event.itemQues && event.nowChoice == event.itemChoice ){
                    cout << event.ItemNorration << endl;
                    PLAYER.catchItem(event.item);
                }
                //
                event.nowQuestion = event.totalEventOpt[event.nowQuestion].getLeftInd();
                break;
            }
            if(GetAsyncKeyState(VK_RIGHT) && 0x8001){ // choose right
                keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
                event.nowChoice = 2;
                // item check
                if (event.nowQuestion == event.itemQues && event.nowChoice == event.itemChoice ){
                    cout << event.ItemNorration << endl;
                    PLAYER.catchItem(event.item);
                }
                //
                event.nowQuestion = event.totalEventOpt[event.nowQuestion].getRightInd();
                break;
            }
        }
        cout << "-------------------" << endl;

        // if ending: ?
        if (event.nowQuestion == -1){ // event failed
            event.isEvent = 0;
            cout << "事件失敗" << endl;
            break;
        }

        if (event.nowQuestion >= event.questionCnt){
            cout << event.EventEnd << endl;
            cout << "=================================================================" << endl;
            event.nowQuestion = 0;
            break;
        }
    }
    if (event.isHappened){ eCardIdx ++; }

}
