#include <iostream>
#include <cstdlib>
#include "./headerFile/item.h"
using namespace std;

Item::Item(const string& n): name(n){}

Item::getName() const{
    return name;
}