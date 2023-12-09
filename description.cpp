#include <string>
#include <random>
#include <time.h>
#include "./headFile/description.h"
using namespace std;

Description :: Description(){}
// for no question
Description :: Description(const string q): question(q), option1(""), option2("") {}
// for normal
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
// for random
Description :: Description(const string q, const string opt1, const string opt2): question(q), option1(opt1), option2(opt2)
{
    srand( time(NULL) );
    int v1,v2;
    // random the value
    for (int i = 0 ; i < 4 ; i++){
        v1 = rand();
        v2 = rand();

        val1[i] = v1 % 15 - 7;
        val2[i] = v2 % 15 - 7;

        if (val1[i] != 0){eff1[i] = 1;}
        else{ eff1[i] = 0;}
        // 
        if (val2[i] != 0){eff2[i] = 1;}
        else{ eff2[i] = 0;}
    }

}

eventDes :: eventDes(const string name, const string q, const string opt1, const string opt2, const int val1[4], const int val2[4]) : Description(q, opt1, opt2, val1, val2), name(name){}
void eventDes :: setNextIdex(const int left, const int right)
{
    nextIndex[0] = left;
    nextIndex[1] = right;
}