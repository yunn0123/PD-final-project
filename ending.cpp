#include <iostream>
using namespace std;

#include "./headFile/ending.h"

// 檢查並觸發遊戲結局
void Ending :: checkForEnding(Player& player)
{
     // 設計最高與最低的數值
    const int minVal = 0;
    const int maxVal = 50;

    // 檢查是否達到需重玩的條件
    if (isValuesBalanced(player, minVal, maxVal)) {
        restartEnding(player);
        return;
    }

    const string mothershipModel = "母艦模型";
    const string trainModel = "火車模型";
    if (hasSpecificItem(player, mothershipModel) && hasSpecificItem(player, trainModel)) {
        hiddenEnding();
        return;
    }


    //
}
// 檢查玩家數值是否過高或過低
bool Ending :: isValuesBalanced(Player& player, int minVal, int maxVal)
{

    bool restartGame = false;

    if(player.value1 >= maxVal){
        cout << "===========================================================" << endl;
        cout << "物價斷層上漲，民眾苦不堪言，你被投票罷免，往後將受民眾唾棄…" << endl;
        cout << "===========================================================" << endl;
        restartGame = true;
    } else if(player.value1 <= minVal){
        cout << "===========================================" << endl;
        cout << "民生凋落，你被闖入的民眾集體瓜分，不知去向…" << endl;
        cout << "===========================================" << endl;
        restartGame = true;
    } else if(player.value2 >= maxVal){
        cout << "===============================================================================================" << endl;
        cout << "你被拱為民眾的偶像，不斷的吹捧中你迷失自我。在一次的小錯誤中，你被推下神壇，成為萬人唾棄的對象…" << endl;
        cout << "===============================================================================================" << endl;
        restartGame = true;
    } else if (player.value2 <= minVal){
        cout << "===============================================================================" << endl;
        cout << "每次你出門，總是被路過的人民丟食物或廚餘，你再也受不了這樣的對待，從此消聲匿跡…" << endl;
        cout << "===============================================================================" << endl;
        restartGame = true;
    } else if(player.value3 >= maxVal){
        cout << "==============================================================================" << endl;
        cout << "你結交了很多朋友，但在一次的衝突中你無法為兩方朋友站場，雙方不滿的將你解決了…" << endl;
        cout << "==============================================================================" << endl;
        restartGame = true;
    } else if (player.value3 <= minVal){
        cout << "================================================================================" << endl;
        cout << "你在國際被孤立，沒有人願意在出事時幫助你，就這樣，你的國家漸漸地在世界中消失了…" << endl;
        cout << "================================================================================" << endl;
        restartGame = true;
    } else if(player.value4 >= maxVal){
        cout << "======================================================================" << endl;
        cout << "科技快速發展，你的國家成為了法外之地。在一次出門中，你被最新科技鎖定…" << endl;
        cout << "======================================================================" << endl;
        restartGame = true;
    } else if (player.value4 <= minVal){
        cout << "======================================================================" << endl;
        cout << "沒有科技的社會猶如一片死水，你的國家成為了他國的附屬品，也不再需要你…" << endl;
        cout << "======================================================================" << endl;
        restartGame = true;
    }
    return restartGame;
}

//檢查是否有特定的道具
bool Ending::hasSpecificItem(Player& player, const string itemName) {
    for (const Item item : player.getItem()) {
        if (item.getName() == itemName) {
            return true;
        }
    }
    return false;
}

// 重啟結局
void Ending :: restartEnding(Player& player)
{
    cout << "嚙褓程嚙磐嚙瞇嚙踝蕭嚙編嚙罷嚙締嚙皺" << endl;
    // 重新初始化遊戲，數值初始化，指回最初的卡牌
    player.restart = true;
    player.value1 = INI_VAL;
    player.value2 = INI_VAL;
    player.value3 = INI_VAL;
    player.value4 = INI_VAL;

}



// 普通結局
void Ending :: normalEnding()
{
    cout << "恭喜！你已成功克服了每一個遇到的挑戰！你的洞察力和決策能力令人印象深刻！" << endl
        << "你在鋪著國家前進的道路上展現出了無限的潛力，你的每一個決策都為這個國家的未來帶來了光明和希望。" << endl
        << "通過這個挑戰，你展現了自己在政治領域的非凡才華，也證明了你是一位出色的領袖。" << endl
        << "讓我們期待看到你在這場角色扮演的旅程中，繼續為這個國家帶來更多的繁榮和進步！" << endl
        << "祝賀你，這次的勝利只是你不斷追求卓越的開始…" << endl;

    // 數值顯示
    cout << "在這場旅程中，你最後以這樣的數值為這段故事寫下結局：" << endl
        << "經濟：" << PLAYER.value1 << endl
        << "聲望：" << PLAYER.value2 << endl
        << "外交：" << PLAYER.value3 << endl
        << "發展：" << PLAYER.value4 << endl;
}

void Ending :: hiddenEnding()
{
     cout << "隨著你在這趟旅程中所展現出的卓越決策和領導才能，你已不僅僅是一位國家的領袖。" << endl;
    cout << "你的內心深處，對於模型的熱愛逐漸滋長，成為了你生活中不可或缺的一部分。" << endl;
    cout << "從你收集到的母艦模型和火車模型開始，你的辦公室逐漸轉變成了一個小型博物館，吸引了無數同好者前來參觀。" << endl;
    cout << "你的收藏品成為了全國甚至全世界模型愛好者的聖地。" << endl;
    cout << "在你的引領下，國家不僅在政治和經濟上取得了巨大的成就，你對模型的熱愛也成為了國民文化的一部分。" << endl;
    cout << "你的故事證明了，即使是國家領袖，也可以擁有自己的愛好，並將這份愛好提升到藝術的層次。" << endl;
    cout << "恭喜你，你不僅是一位成功的領袖，也是一位備受尊敬的模型收藏家。" << endl;

}


