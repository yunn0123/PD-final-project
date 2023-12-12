#include <iostream>
#include <cstdlib>
using namespace std;

class Item{
private:
    string name;
public:
    Item(const string& n);
    string getName() const;
};