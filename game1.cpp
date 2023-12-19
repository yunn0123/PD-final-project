#include "./headFile/game1.h"
using namespace std;
int Game :: getTotalseq(){return totalCardNumNeedToProcess;}
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
    cout << "Timeless Redemption" << endl;
    cout << endl;
    cout << "--- �� SPACE �}�l�C���B��ESC�����C�� ---" << endl;
    Sleep(30);
    while(true){
        if (GetAsyncKeyState(VK_SPACE) && 0x8001){
            // avoid previous click is taken
            keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
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
            cout << "�O�_���}�C���H" << endl;
            cout << "�O(y) �_(n)" << endl;
            string user;
            cin >> user;
            if (user.compare("y") == 0){ // y
                PLAYER.end = true;
                break;
            }
            if (user.compare("n") == 0){ // n
                cout << "--- �� SPACE �}�l�C���B��ESC�����C�� ---" << endl;
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
        Ending :: normalEnding();
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
        keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
        if(GetAsyncKeyState(VK_LEFT) && 0x8001){ // choose left
            keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
                Sleep(50);
            tempCard->nowChoice = 1;
            //PLAYER.updateValues(normalCard[this->nrIdx].totalOpt[normalCard[this->nrIdx].nowQuestion].val1[0], normalCard[this->nrIdx].totalOpt[normalCard[this->nrIdx].nowQuestion].val1[1], normalCard[this->nrIdx].totalOpt[normalCard[this->nrIdx].nowQuestion].val1[2], normalCard[this->nrIdx].totalOpt[normalCard[this->nrIdx].nowQuestion].val1[3]);
            break;
        }
        if(GetAsyncKeyState(VK_RIGHT) && 0x8001){ // choose right
            keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
                Sleep(50);
            tempCard->nowChoice = 2;
            //PLAYER.updateValues(normalCard[this->nrIdx].totalOpt[normalCard[this->nrIdx].nowQuestion].val2[0], normalCard[this->nrIdx].totalOpt[normalCard[this->nrIdx].nowQuestion].val2[1], normalCard[this->nrIdx].totalOpt[normalCard[this->nrIdx].nowQuestion].val2[2], normalCard[this->nrIdx].totalOpt[normalCard[this->nrIdx].nowQuestion].val2[3]);
            break;
        }
    }
    PLAYER.updateValues(tempCard);
    nrIdx ++;
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
}
void Game :: event()
{
    EventCard event = eventCard[this->eCardIdx];
    event.isEnterEvent();
    while(event.nowQuestion < event.questionCnt && event.isEvent){
        cout << event.totalEventOpt[event.nowQuestion].getName() << ": " << event.totalEventOpt[event.nowQuestion].question << endl;
        cout << event.totalEventOpt[event.nowQuestion].option1 << " (��)" << " -> �v�T ";
        // effect what value, print out
        if(event.totalEventOpt[event.nowQuestion].eff1[0]){cout << "�g�� ";}
        if(event.totalEventOpt[event.nowQuestion].eff1[1]){cout << "�n�� ";}
        if(event.totalEventOpt[event.nowQuestion].eff1[2]){cout << "�~�� ";}
        if(event.totalEventOpt[event.nowQuestion].eff1[3]){cout << "���|�o�i ";}
        cout << "          " ;
        cout <<  event.totalEventOpt[event.nowQuestion].option2 << " (�k)" << " -> �v�T ";
        // effect what value, print out
        if(event.totalEventOpt[event.nowQuestion].eff2[0]){cout << "�g�� ";}
        if(event.totalEventOpt[event.nowQuestion].eff2[1]){cout << "�n�� ";}
        if(event.totalEventOpt[event.nowQuestion].eff2[2]){cout << "�~�� ";}
        if(event.totalEventOpt[event.nowQuestion].eff2[3]){cout << "���|�o�i ";}
        cout << endl;
        // update value and item
        while(true){
            if(GetAsyncKeyState(VK_LEFT) && 0x8001){ // choose left
                keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
                event.nowChoice = 1;
                // item check
                if (event.nowQuestion == event.itemQues && event.nowChoice == event.itemChoice ){
                    cout << event.ItemNorration << endl;
                    PLAYER.catchItem(event.item);
                }
                //
                PLAYER.eventUpdateVal(&event);
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
                PLAYER.updateValues(&event);
                event.nowQuestion = event.totalEventOpt[event.nowQuestion].getRightInd();
                break;
            }
        }
        eCardIdx ++;
        // if ending: ?
        if (event.nowQuestion == -1){ // event failed
            event.isEvent = 0;
            cout << "�ƥ󥢱ѡC" << endl;
            if (event.isDead){
                // tragger ending
                // call ending ?
                break;
            }
            break;
        }

        if (event.nowQuestion >= event.questionCnt){
            cout << event.EventEnd << endl;
            event.nowQuestion = 0;
        }
    }
    

}