#include <iostream>
#include <cstdlib>
#include "./headFile/item.h"
using namespace std;

Item :: Item(){};

Item::Item(const string& n): name(n){}

string Item::getName() const{
    return name;
}

