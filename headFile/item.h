#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item{
private:
    string name;
public:
    Item();
    Item(const string& n);
    string getName() const;
};

#endif