#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <random>
using namespace std;

#ifndef ENDING_H
#define ENDING_H

#include "character.h"

class Ending {
    public:
        // 檢查並觸發遊戲結局
        static void checkForEnding(Player& player, Game& game);
    private:
        // 檢查玩家數值是否平衡
        bool isValuesBalanced(Player& player, int minVal, int maxVal);
        // 檢查是否達到普通結局條件
        static bool isNormalEndingAchieved(Game& game);

        // 檢查是否解鎖隱藏結局（要看有沒有特殊道具）
        static bool isHiddenEndingUnlocked(Player& player);

        // 重啟結局
        static void restartEnding();

        // 普通結局
        static void normalEnding();

        // 隱藏結局
        static void hiddenEnding();
};

#endif
