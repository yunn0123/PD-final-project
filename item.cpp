#include <iostream>
#include <cstdlib>
#include "./headFile/item.h"
using namespace std;

Item::Item(const string& n): name(n){}

Item::getName() const{
    return name;
}
