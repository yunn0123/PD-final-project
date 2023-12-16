#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <random>
using namespace std;

#ifndef ENDING_H
#define ENDING_H

#include "player.h"
#include "game.h"

class Ending {
    public:
        // 檢查並觸發遊戲結局
        static void checkForEnding(Player& player, Game& game);
        // 重啟結局
        static void restartEnding();
        // 普通結局
        static void normalEnding();
        // 隱藏結局
        static void hiddenEnding();

    private:
        // 檢查玩家數值是否平衡
        static bool isValuesBalanced(Player& player, int minVal, int maxVal);
        // 檢查是否達到普通結局條件
        static bool isNormalEndingAchieved(Game& game);
        // 檢查是否解鎖隱藏結局
        static bool isHiddenEndingUnlocked(Player& player);
        // 檢查是否有特定道具
        static bool hasSpecificItem(const Character& character, const string& itemName);


};

#endif
