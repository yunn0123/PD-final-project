#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <random>
using namespace std;

#ifndef GAME_H
#define GAME_H

#include "ending.h"
#include "card.h"
#include "character.h"
#include "item.h"
#include "description.h"

class Game {
private:
    int currentIndex;
    Player player;
    //
    void showCard();
    void handleLeftChoice();
    void handleRightChoice();
    void endGame();

public:
    Game(int startingIndex, const Player& initialPlayer);
    void start();
};

#endif