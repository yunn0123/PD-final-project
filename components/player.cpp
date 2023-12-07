#include <iostream>
#include <cstdlib>
#include "ALLimport.h"
using namespace std;

const int INI_VAL = 10;
string printChange(int change){
    string out = "";
    if(change > 0){
        out = "(+" + to_string(change) + ')';
    }
    else if(change < 0){
        out = '(' + to_string(change) + ')';
    }
    return out;
}
Player :: Player() : value1(INI_VAL), value2(INI_VAL), value3(INI_VAL), value4(INI_VAL) {}

void Player :: updateValues(int change1, int change2, int change3, int change4) 
{
    value1 += change1;
    value2 += change2;
    value3 += change3;
    value4 += change4;
    cout << "A: " << value1 << printChange(change1) << ' ';
    cout << "B: " << value2 << printChange(change2) << ' ';
    cout << "C: " << value3 << printChange(change3) << ' ';
    cout << "D: " << value4 << printChange(change4) << ' ';
    cout << endl;
    //checkForEndGame() by Ending?
}
char Player :: getChoice(){
    char choice;
    cin >> choice;
    return choice;
}
