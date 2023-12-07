#include <iostream>
using namespace std;
#include "ALLimport.h"

using namespace std;

// 檢查並觸發遊戲結局
void Ending :: checkForEnding(Player& player, Game& game)
{
    // 設計平衡的數值（可改）
    const int MIN_BALANCE_VALUE = 5;
    const int MAX_BALANCE_VALUE = 20;

    // 檢查是否達到需重玩的條件
    if (!isValuesBalanced(player, MIN_BALANCE_VALUE, MAX_BALANCE_VALUE)) {
        restartEnding();
        return;
    }

    // 檢查是否達到普通結局的條件
    if (isNormalEndingAchieved(game)) {
        normalEnding();
        return;
    }

    // 檢查是否解鎖隱藏結局
    if (isHiddenEndingUnlocked(player)) {
        hiddenEnding();
        return;
    }

    // 
}
// 檢查玩家數值是否平衡
bool Ending :: isValuesBalanced(Player& player, int minVal, int maxVal)
{
    return (player.value1 >= minVal && player.value1 <= maxVal &&
            player.value2 >= minVal && player.value2 <= maxVal &&
            player.value3 >= minVal && player.value3 <= maxVal &&
            player.value4 >= minVal && player.value4 <= maxVal);
}

// 檢查是否達到普通結局條件
bool Ending :: isNormalEndingAchieved(Game& game)
{
    // 檢查要跑的地方是否都完成 or 特定事件是否被觸發
    // return game.isAllProcessCompleted();
}

// 檢查是否解鎖隱藏結局（要看有沒有特殊道具）
bool Ending :: isHiddenEndingUnlocked(Player& player)
{
    // 檢查玩家的道具中是否包含特定道具
    // return player.hasSecretItem(); 
}

// 重啟結局
void Ending :: restartEnding()
{
    cout << "..." << endl;
    // 重新初始化遊戲
}

// 普通結局
void Ending :: normalEnding()
{
    cout << "..." << endl;
    // 結局故事敘述文字 or 結局評分
}

// 隱藏結局
void Ending :: hiddenEnding()
{
    cout << "..." << endl;
    // 隱藏結局故事敘述文字 or 解鎖特殊獎勵可以開啟新的遊戲內容
}