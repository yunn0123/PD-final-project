#include <string>
#include "ALLimport.h"
using namespace std;

Description :: Description(){}
// 給沒有敘述的
Description :: Description(const string q): question(q) {} // 傳入空格
// 給有敘述的
Description :: Description(const string q, const string opt1, const string opt2, const int val1[4], const int val2[4]): question(q), option1(opt1), option2(opt2)
{
    for(int i = 0; i < 4 ; i++){
        this->val1[i] = val1[i];
        this->val2[i] = val2[i];
        if (val1[i] != 0){
            eff1[i] = 1;
        }
        else{
            eff1[i] = 0;
        }
        if (val2[i] != 0){
            eff2[i] = 1;
        }
        else {
            eff2[i] = 0;
        }
    }
};
// 給隨機卡牌
Description :: Description(const string q, const string opt1, const string opt2): question(q), option1(opt1), option2(opt2)
{
    std::random_device rd;   // 獲取真實的隨機數種子
    std::mt19937 gen(rd());  //  Mersenne Twister 亂數引擎
    std::uniform_int_distribution<int> distribution(-10, 10);

    // 產生一個隨機整數
    for (int i = 0 ; i < 4 ; i++){
        val1[i] = distribution(gen);
        val2[i] = distribution(gen);

        if (val1[i] != 0){eff1[i] = 1;}
        else{ eff1[i] = 0;}
        // 
        if (val2[i] != 0){eff2[i] = 1;}
        else{ eff2[i] = 0;}
    }

} // for random card

eventDes :: eventDes(const string q, const string opt1, const string opt2, const int val1[4], const int val2[4]) : Description(q, opt1, opt2, val1, val2){}
void eventDes :: setNextIdex(const int left, const int right)
{
    nextIndex[0] = left;
    nextIndex[1] = right;
}