#include "ALLimport.h"
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
void Card :: setNowChoice(const int choice) {nowChoice = choice;}
bool Card :: GameCallingPrint(){}
////////////////////////////////////////////////
// 一般
NormalCard :: NormalCard(){}
NormalCard :: ~NormalCard(){}
void NormalCard :: setTotalOpt(const Description opt) {totalOpt.push_back(opt);}
NormalCard :: NormalCard(const string name, const int quesCnt) : Card(name, quesCnt)
{
    nowQuestion = 0;
    descript = "";
    nowChoice = 0;
};
bool NormalCard :: GameCallingPrint()
{
    // choice: game傳入玩家選擇
    // 左 = 1 ，右 = 2
    // 0 -> 1, 2  (+1 , +2) 0
    // 1 -> 3, 4  (+2 , +3) 1
    // 2 -> 5, 6  (+3 , +4) 1
    // 3 -> 7, 8  (+4 , +5) 2
    nowQuestion += (nowQuestion + nowChoice);
    // if last question has asked, return first question
    if(nowQuestion >= questionCnt){
        nowQuestion = 0;
    }
    if(totalOpt[nowQuestion].question.compare(" ") == 0){
        nowQuestion = 0;
        return 0;
    }
    cout << name << ": " << totalOpt[nowQuestion].question << endl; 
    cout << totalOpt[nowQuestion].option1 << " (左)" << " -> 影響 ";
    // effect what value, print out
    if(totalOpt[nowQuestion].eff1[0]){
        cout << "經濟 ";
    }
    if(totalOpt[nowQuestion].eff1[1]){
        cout << "聲望 ";
    }
    if(totalOpt[nowQuestion].eff1[2]){
        cout << "外交 ";
    }
    if(totalOpt[nowQuestion].eff1[3]){
        cout << "社會發展 ";
    }

    cout << "             " ;

    cout <<  totalOpt[nowQuestion].option2 << " (右)" << " -> 影響 ";
    // effect what value, print out
    if(totalOpt[nowQuestion].eff2[0]){
        cout << "經濟 ";
    }
    if(totalOpt[nowQuestion].eff2[1]){
        cout << "聲望 ";
    }
    if(totalOpt[nowQuestion].eff2[2]){
        cout << "外交 ";
    }
    if(totalOpt[nowQuestion].eff2[3]){
        cout << "社會發展 ";
    }
    cout << endl;
    while(true){
        if(GetAsyncKeyState(VK_LEFT) && 0x8001){ // choose left
            setNowChoice(1);
            PLAYER.updateValues(totalOpt[nowQuestion].val1[0], totalOpt[nowQuestion].val1[1], totalOpt[nowQuestion].val1[2], totalOpt[nowQuestion].val1[3]);
            break;
        }
        if(GetAsyncKeyState(VK_RIGHT) && 0x8001){ // choose left
            setNowChoice(2);
            PLAYER.updateValues(totalOpt[nowQuestion].val2[0], totalOpt[nowQuestion].val2[1], totalOpt[nowQuestion].val2[2], totalOpt[nowQuestion].val2[3]);

            break;
        }
    }
    return 1;
}
////////////////////////////////////////////////
// 隨機(數值自行random)
RandomCard :: RandomCard() {}
RandomCard :: RandomCard(const string name, const int quesCnt) : Card(name, quesCnt)
{
    nowQuestion = 0;
    descript = "";
    des = new string[quesCnt];
}       
RandomCard :: ~RandomCard() 
{
    delete [] des;
    des = nullptr;
}
void RandomCard :: setTotalOpt(const Description opt) {totalOpt.push_back(opt);}
bool RandomCard :: GameCallingPrint()
{
    nowQuestion += (nowQuestion + nowChoice);
    // if last question has asked, return first question
    if(nowQuestion >= questionCnt){
        nowQuestion = 0;
    }
    if(totalOpt[nowQuestion].question.compare(" ") == 0){
        nowQuestion = 0;
        return 0;
    }
    cout << name << ": " << totalOpt[nowQuestion].question << endl; 
    cout << totalOpt[nowQuestion].option1 << " (左)" << " -> 影響 ";
    // effect what value, print out
    if(totalOpt[nowQuestion].eff1[0]){
        cout << "經濟 ";
    }
    if(totalOpt[nowQuestion].eff1[1]){
        cout << "聲望 ";
    }
    if(totalOpt[nowQuestion].eff1[2]){
        cout << "外交 ";
    }
    if(totalOpt[nowQuestion].eff1[3]){
        cout << "社會發展 ";
    }

    cout << "             " ;

    cout <<  totalOpt[nowQuestion].option2 << " (右)" << " -> 影響 ";
    // effect what value, print out
    if(totalOpt[nowQuestion].eff2[0]){
        cout << "經濟 ";
    }
    if(totalOpt[nowQuestion].eff2[1]){
        cout << "聲望 ";
    }
    if(totalOpt[nowQuestion].eff2[2]){
        cout << "外交 ";
    }
    if(totalOpt[nowQuestion].eff2[3]){
        cout << "社會發展 ";
    }
    cout << endl;
    while(true){
        if(GetAsyncKeyState(VK_LEFT) && 0x8001){ // choose left
            setNowChoice(1);
            PLAYER.updateValues(totalOpt[nowQuestion].val1[0], totalOpt[nowQuestion].val1[1], totalOpt[nowQuestion].val1[2], totalOpt[nowQuestion].val1[3]);

            break;
        }
        if(GetAsyncKeyState(VK_RIGHT) && 0x8001){ // choose left
            setNowChoice(2);
            PLAYER.updateValues(totalOpt[nowQuestion].val2[0], totalOpt[nowQuestion].val2[1], totalOpt[nowQuestion].val2[2], totalOpt[nowQuestion].val2[3]);
            break;
        }
    }
    return 1;
}
////////////////////////////////////////////////
// 事件(進入不可出來，除非選到特定的選項)
EventCard :: EventCard() {}
EventCard :: EventCard(const string name, const int quesCnt) : Card(name, quesCnt)
{
    nowQuestion = 0;
    descript = "";
};
EventCard :: EventCard(const string name, const int quesCnt, const string EventNorration, const string EnterEvent, const bool left, const int right)
{
    this->name = name;
    questionCnt = quesCnt;
    this->EventNorration = EventNorration;
    this->EnterEvent = EnterEvent;
    isEnter[0] = left;
    isEnter[1] = right;
};
//// setting
void EventCard :: setTotalEventOpt(const eventDes opt) {totalEventOpt.push_back(opt);}
void EventCard :: setIsEnter(const bool arr[2], const string EventDes, const string EventNorration)
{ // 設定進入事件的必要問題
    isEnter[0] = arr[0];
    isEnter[1] = arr[1];
    EnterEvent = EventDes;
    this->EventNorration = EventNorration;
};
//// 判斷
bool EventCard :: isEnterEvent()
{
    cout << name << ": " << EnterEvent << endl;
    while(true){
        if (GetAsyncKeyState(VK_LEFT) && 0x8001){ // left
            if(isEnter[0]){
                cout << EventNorration << endl;
                isEvent = 1;
                isHappened = 1;
                return 1;
            }
            else {return 0;}
            break;
        }
        else if (GetAsyncKeyState(VK_RIGHT) && 0x8001){ ///right
            if(isEnter[1]){
                cout << EventNorration << endl;
                isEvent = 1;
                isHappened = 1;
                return 1;
            }
            else {return 0;}
            break;
        }
    }
    return 0;
};
//// destructor
EventCard :: ~EventCard() {}; 
int EventCard :: isEvent = 0;
void EventCard :: setEnding(const string end, bool isDead)
{
    EventEnd = end;
    this->isDead = isDead;
}
bool EventCard :: GameCallingPrint(){
    // 迴圈印出，直到user決定離開
    // 紀錄離開條件
    // 紀錄迴圈起始點
    isEnterEvent();
    while(nowQuestion < questionCnt && isEvent){
        cout << name << ": " << totalEventOpt[nowQuestion].question << endl; 
        cout << totalEventOpt[nowQuestion].option1 << " (左)" << " -> 影響 ";
        // effect what value, print out
        if(totalEventOpt[nowQuestion].eff1[0]){
            cout << "經濟 ";
        }
        if(totalEventOpt[nowQuestion].eff1[1]){
            cout << "聲望 ";
        }
        if(totalEventOpt[nowQuestion].eff1[2]){
            cout << "外交 ";
        }
        if(totalEventOpt[nowQuestion].eff1[3]){
            cout << "社會發展 ";
        }

        cout << "          " ;

        cout <<  totalEventOpt[nowQuestion].option2 << " (右)" << " -> 影響 ";
        // effect what value, print out
        if(totalEventOpt[nowQuestion].eff2[0]){
            cout << "經濟 ";
        }
        if(totalEventOpt[nowQuestion].eff2[1]){
            cout << "聲望 ";
        }
        if(totalEventOpt[nowQuestion].eff2[2]){
            cout << "外交 ";
        }
        if(totalEventOpt[nowQuestion].eff2[3]){
            cout << "社會發展 ";
        }
        // call Player value change
        while(true){
            if(GetAsyncKeyState(VK_LEFT) && 0x8001){ // choose left
                setNowChoice(1);
                PLAYER.updateValues(totalEventOpt[nowQuestion].val1[0], totalEventOpt[nowQuestion].val1[1], totalEventOpt[nowQuestion].val1[2], totalEventOpt[nowQuestion].val1[3]);
                nowQuestion = totalEventOpt[nowQuestion].nextIndex[0];
                break;
            }
            if(GetAsyncKeyState(VK_RIGHT) && 0x8001){ // choose right
                setNowChoice(2);
                PLAYER.updateValues(totalEventOpt[nowQuestion].val2[0], totalEventOpt[nowQuestion].val2[1], totalEventOpt[nowQuestion].val2[2], totalEventOpt[nowQuestion].val2[3]);
                nowQuestion = totalEventOpt[nowQuestion].nextIndex[1];
                break;
            }
        }
        // if ending: ?
        if (nowQuestion == -1){ // 若事件失敗
            isEvent = 0;
            cout << EventEnd << endl;
            if (isDead){
                // tragger ending
            }
        }

    }
    return 1;

}
///////////////////////////////////////////