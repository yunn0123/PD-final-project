#include "./headFile/card.h"
using namespace std;
// abstract class Card
Card :: Card() {}
Card :: ~Card() {}
Card :: Card(const string name, const int quesCnt) : name(name), questionCnt(quesCnt)
{
    nowQuestion = 0;
    descript = "";
    nowChoice = 0;
}
void Card :: setTotalOpt(const Description opt) {totalOpt.push_back(opt);}
string Card :: getName() {return name;}
void Card :: setDescript(const string des) {descript = des;}
void Card :: GameCallingPrint(){}
////////////////////////////////////////////////
// 
NormalCard :: NormalCard(){}
NormalCard :: ~NormalCard(){}
void NormalCard :: setTotalOpt(const Description opt) {totalOpt.push_back(opt);}
NormalCard :: NormalCard(const string name, const int quesCnt) : Card(name, quesCnt)
{
    nowQuestion = 0;
    descript = "";
    nowChoice = 0;
};
void NormalCard :: GameCallingPrint()
{
    // 左 = 1 右 = 2
    // 0 -> 1, 2  (+1 , +2) 0
    // 1 -> 3, 4  (+2 , +3) 1
    // 2 -> 5, 6  (+3 , +4) 1
    // 3 -> 7, 8  (+4 , +5) 2
    cout << name << ": " << totalOpt[nowQuestion].question << endl; 
    cout << totalOpt[nowQuestion].option1 << " (左)" << " -> 影響 ";
    // effect what value, print out
    if(totalOpt[nowQuestion].eff1[0]){cout << "經濟 ";}
    if(totalOpt[nowQuestion].eff1[1]){cout << "聲望 ";}
    if(totalOpt[nowQuestion].eff1[2]){cout << "外交 ";}
    if(totalOpt[nowQuestion].eff1[3]){cout << "社會發展 ";}
    cout << "           " ;
    cout <<  totalOpt[nowQuestion].option2 << " (右)" << " -> 影響 ";
    // effect what value, print out
    if(totalOpt[nowQuestion].eff2[0]){cout << "經濟 ";}
    if(totalOpt[nowQuestion].eff2[1]){cout << "聲望 ";}
    if(totalOpt[nowQuestion].eff2[2]){cout << "外交 ";}
    if(totalOpt[nowQuestion].eff2[3]){cout << "社會發展 ";}
    cout << endl;

    while(true){
        if(GetAsyncKeyState(VK_LEFT) && 0x8001){ // choose left
            keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
            nowChoice = 1;
            PLAYER.updateValues(totalOpt[nowQuestion].val1[0], totalOpt[nowQuestion].val1[1], totalOpt[nowQuestion].val1[2], totalOpt[nowQuestion].val1[3]);
            break;
        }
        if(GetAsyncKeyState(VK_RIGHT) && 0x8001){ // choose right
            keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
            nowChoice = 2;
            PLAYER.updateValues(totalOpt[nowQuestion].val2[0], totalOpt[nowQuestion].val2[1], totalOpt[nowQuestion].val2[2], totalOpt[nowQuestion].val2[3]);

            break;
        }
    }
    cout << "-------------------" << endl;
    // for next print
    nowQuestion += (nowQuestion + nowChoice);
    // if last question has asked, return to first question
    if(nowQuestion >= questionCnt){
        nowQuestion = 0;
        nowChoice = 0;
    }
    // if in the array but no question
    else if(totalOpt[nowQuestion].question.compare(" ") == 0){
        nowQuestion = 0;
        nowChoice = 0;
    }
    // tragger ending 
    

}
////////////////////////////////////////////////
// ?H??
RandomCard :: RandomCard() {}
RandomCard :: RandomCard(const string name, const int quesCnt) : Card(name, quesCnt)
{
    nowQuestion = 0;
    descript = "";
}       
RandomCard :: ~RandomCard() {}
void RandomCard :: setTotalOpt(const Description opt) {totalOpt.push_back(opt);}
void RandomCard :: GameCallingPrint()
{
    // ?? = 1 ?k = 2
    // 0 -> 1, 2  (+1 , +2) 0
    // 1 -> 3, 4  (+2 , +3) 1
    // 2 -> 5, 6  (+3 , +4) 1
    // 3 -> 7, 8  (+4 , +5) 2

    cout << name << ": " << totalOpt[nowQuestion].question << endl; 
    cout << totalOpt[nowQuestion].option1 << " (左)" << " -> 影響 ";
    // effect what value, print out
    if(totalOpt[nowQuestion].eff1[0]){cout << "經濟 ";}
    if(totalOpt[nowQuestion].eff1[1]){cout << "聲望 ";}
    if(totalOpt[nowQuestion].eff1[2]){cout << "外交 ";}
    if(totalOpt[nowQuestion].eff1[3]){cout << "社會發展 ";}
    cout << "           " ;
    cout <<  totalOpt[nowQuestion].option2 << " (右)" << " -> 影響 ";
    // effect what value, print out
    if(totalOpt[nowQuestion].eff2[0]){cout << "經濟 ";}
    if(totalOpt[nowQuestion].eff2[1]){cout << "聲望 ";}
    if(totalOpt[nowQuestion].eff2[2]){cout << "外交 ";}
    if(totalOpt[nowQuestion].eff2[3]){cout << "社會發展 ";}
    cout << endl;
    //
    while(true){
        if(GetAsyncKeyState(VK_LEFT) && 0x8001){ // choose left
            keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
            nowChoice = 1;
            PLAYER.updateValues(totalOpt[nowQuestion].val1[0], totalOpt[nowQuestion].val1[1], totalOpt[nowQuestion].val1[2], totalOpt[nowQuestion].val1[3]);
            break;
        }
        if(GetAsyncKeyState(VK_RIGHT) && 0x8001){ // choose right
            keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
            nowChoice = 2;
            PLAYER.updateValues(totalOpt[nowQuestion].val2[0], totalOpt[nowQuestion].val2[1], totalOpt[nowQuestion].val2[2], totalOpt[nowQuestion].val2[3]);
            break;
        }
    }
    cout << "-------------------" << endl;
    // for next print
    nowQuestion += (nowQuestion + nowChoice);
    // if last question has asked, return to first question
    if(nowQuestion >= questionCnt){
        nowQuestion = 0;
        nowChoice = 0;
    }
    // if in the array but no question
    else if(totalOpt[nowQuestion].question.compare(" ") == 0){
        nowQuestion = 0;
        nowChoice = 0;
    }
    
}
////////////////////////////////////////////////
// ???(?s??)
EventCard :: EventCard() {}
EventCard :: EventCard(const string name, const int quesCnt) : Card(name, quesCnt)
{
    nowQuestion = 0;
    descript = "";
};
EventCard :: EventCard(const string name, const int quesCnt, const string EventNorration, const string EventDes, const string opt1, const string opt2, const bool left, const int right)
{
    nowQuestion = 0;
    nowChoice = 0;
    this->name = name;
    questionCnt = quesCnt;
    isEnter[0] = left;
    isEnter[1] = right;
    optLEFT = opt1;
    optRIGHT = opt2;
    EnterEventQues = EventDes;
    this->EventNorration = EventNorration;
};
//// setting
void EventCard :: setTotalEventOpt(const eventDes opt) {totalEventOpt.push_back(opt);}
void EventCard:: setItem(const int itemQues, const int itemChoice, const string ItemNorration, const string name)
{
    this -> itemQues = itemQues;
    this -> itemChoice = itemChoice;
    this -> ItemNorration = ItemNorration;
    Item item(name);
}

//// destructor
EventCard :: ~EventCard() {}; 
int EventCard :: isEvent = 0;
int EventCard :: isHappened = 0;
//// 
bool EventCard :: isEnterEvent()
{
    cout << EventNorration << endl;
    cout << name << " : " << EnterEventQues << endl;
    cout << optLEFT << " (左)          " << optRIGHT << " (右)" << endl;
    while(true){
        if (GetAsyncKeyState(VK_LEFT) && 0x8001){ // left
            keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
            if(isEnter[0]){
                isEvent = 1;
                isHappened = 1;
                cout << "-------------------" << endl;
                return 1;
            }
            else {
                cout << "-------------------" << endl;
                return 0;
            }
            break;
        }
        else if (GetAsyncKeyState(VK_RIGHT) && 0x8001){ ///right
            keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
            if(isEnter[1]){
                isEvent = 1;
                isHappened = 1;
                cout << "-------------------" << endl;
                return 1;
            }
            else {
                cout << "-------------------" << endl;
                return 0;
            }
            break;
        }
        if(nowQuestion == itemQues && nowChoice == itemChoice){
            cout << ItemNorration << endl;
        }
    }
    cout << "-------------------" << endl;
    return 0;
};

void EventCard :: setEnding(const string end, bool isDead)
{
    EventEnd = end;
    this->isDead = isDead;
}
void EventCard :: GameCallingPrint(){
    this -> isEnterEvent();
    while(nowQuestion < questionCnt && isEvent){
        cout << totalEventOpt[nowQuestion].name << ": " << totalEventOpt[nowQuestion].question << endl; 
        cout << totalEventOpt[nowQuestion].option1 << " (左)" << " -> 影響 ";
        // effect what value, print out
        if(totalEventOpt[nowQuestion].eff1[0]){cout << "經濟 ";}
        if(totalEventOpt[nowQuestion].eff1[1]){cout << "聲望 ";}
        if(totalEventOpt[nowQuestion].eff1[2]){cout << "外交 ";}
        if(totalEventOpt[nowQuestion].eff1[3]){cout << "社會發展 ";}
        cout << "          " ;
        cout <<  totalEventOpt[nowQuestion].option2 << " (右)" << " -> 影響 ";
        // effect what value, print out
        if(totalEventOpt[nowQuestion].eff2[0]){cout << "經濟 ";}
        if(totalEventOpt[nowQuestion].eff2[1]){cout << "聲望 ";}
        if(totalEventOpt[nowQuestion].eff2[2]){cout << "外交 ";}
        if(totalEventOpt[nowQuestion].eff2[3]){cout << "社會發展 ";}
        cout << endl;
        // call Player value change
        while(true){
            if(GetAsyncKeyState(VK_LEFT) && 0x8001){ // choose left
                keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
                nowChoice = 1;
                // item check
                if (nowQuestion == itemQues && nowChoice == itemChoice ){
                    cout << ItemNorration << endl;
                    PLAYER.catchItem(item);
                }
                //
                PLAYER.updateValues(totalEventOpt[nowQuestion].val1[0], totalEventOpt[nowQuestion].val1[1], totalEventOpt[nowQuestion].val1[2], totalEventOpt[nowQuestion].val1[3]);
                nowQuestion = totalEventOpt[nowQuestion].nextIndex[0];
                break;
            }
            if(GetAsyncKeyState(VK_RIGHT) && 0x8001){ // choose right
                keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
                nowChoice = 2;
                // item check 
                if (nowQuestion == itemQues && nowChoice == itemChoice ){
                    cout << ItemNorration << endl;
                    PLAYER.catchItem(item);
                }
                //
                PLAYER.updateValues(totalEventOpt[nowQuestion].val2[0], totalEventOpt[nowQuestion].val2[1], totalEventOpt[nowQuestion].val2[2], totalEventOpt[nowQuestion].val2[3]);
                nowQuestion = totalEventOpt[nowQuestion].nextIndex[1];
                break;
            }
        }
        cout << "-------------------" << endl;
        // if ending: ?
        if (nowQuestion == -1){ // 事件失敗
            isEvent = 0;
            cout << "事件失敗。" << endl;
            if (isDead){
                // tragger ending
                // call ending ?
                break;
            }
            break;
        }

    }
    if (nowQuestion >= questionCnt){
        cout << EventEnd << endl;
        nowQuestion = 0;
    }

}
///////////////////////////////////////////