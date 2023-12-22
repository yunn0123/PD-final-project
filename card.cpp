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
    already_A_Round = 0;

}
void Card :: setTotalOpt(const Description opt) {totalOpt.push_back(opt);}
string Card :: getName() {return name;}
int Card:: getCnt() {return questionCnt;}
bool Card:: getIfRounded() {return already_A_Round;}
void Card :: setDescript(const string des) {descript = des;}
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
    // left = 1 right = 2
    // 0 -> 1, 2  (+1 , +2) 0
    // 1 -> 3, 4  (+2 , +3) 1
    // 2 -> 5, 6  (+3 , +4) 1
    // 3 -> 7, 8  (+4 , +5) 2
    cout << name << ": " << totalOpt[nowQuestion].question << endl;
    cout << endl;
    cout << totalOpt[nowQuestion].option1 << " (左)" << " -> 影響 ";
    // effect what value, print out
    if(totalOpt[nowQuestion].eff1[0]){cout << "經濟 ";}
    if(totalOpt[nowQuestion].eff1[1]){cout << "聲望 ";}
    if(totalOpt[nowQuestion].eff1[2]){cout << "外交 ";}
    if(totalOpt[nowQuestion].eff1[3]){cout << "社會發展 ";}
    cout << endl ;
    cout <<  totalOpt[nowQuestion].option2 << " (右)" << " -> 影響 ";
    // effect what value, print out
    if(totalOpt[nowQuestion].eff2[0]){cout << "經濟 ";}
    if(totalOpt[nowQuestion].eff2[1]){cout << "聲望 ";}
    if(totalOpt[nowQuestion].eff2[2]){cout << "外交 ";}
    if(totalOpt[nowQuestion].eff2[3]){cout << "社會發展 ";}
    cout << endl;


}
////////////////////////////////////////////////
// random value
RandomCard :: RandomCard() {}
RandomCard :: RandomCard(const string name, const int quesCnt) : Card(name, quesCnt)
{
    nowQuestion = 0;
    descript = "";
    nowChoice = 0;
}
RandomCard :: ~RandomCard() {}
void RandomCard :: setTotalOpt(const Description opt) {totalOpt.push_back(opt);}
void RandomCard :: GameCallingPrint()
{
    // left = 1 , right = 2
    // 0 -> 1, 2  (+1 , +2) 0
    // 1 -> 3, 4  (+2 , +3) 1
    // 2 -> 5, 6  (+3 , +4) 1
    // 3 -> 7, 8  (+4 , +5) 2

    cout << name << ": " << totalOpt[nowQuestion].question << endl;
    cout << endl;
    cout << totalOpt[nowQuestion].option1 << " (左)" << " -> 影響 ";
    // effect what value, print out
    if(totalOpt[nowQuestion].eff1[0]){cout << "經濟 ";}
    if(totalOpt[nowQuestion].eff1[1]){cout << "聲望 ";}
    if(totalOpt[nowQuestion].eff1[2]){cout << "外交 ";}
    if(totalOpt[nowQuestion].eff1[3]){cout << "社會發展 ";}
    cout << endl ;
    cout <<  totalOpt[nowQuestion].option2 << " (右)" << " -> 影響 ";
    // effect what value, print out
    if(totalOpt[nowQuestion].eff2[0]){cout << "經濟 ";}
    if(totalOpt[nowQuestion].eff2[1]){cout << "聲望 ";}
    if(totalOpt[nowQuestion].eff2[2]){cout << "外交 ";}
    if(totalOpt[nowQuestion].eff2[3]){cout << "社會發展 ";}
    cout << endl;


}
////////////////////////////////////////////////
// event
EventCard :: EventCard() {}
EventCard :: EventCard(const string name, const int quesCnt) : Card(name, quesCnt)
{
    nowQuestion = 0;
    descript = "";
    isEvent = 0;
    isHappened = 0;
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
    //Item item(name);
    item = Item(name);
}
////
bool EventCard :: isEnterEvent()
{
    string choice;
    cout << EventNorration << endl;
    cout << name << " : " << EnterEventQues << endl;
    cout << optLEFT << " (左)" << endl ;
    cout << optRIGHT << " (右)" << endl;
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


}
///////////////////////////////////////////
