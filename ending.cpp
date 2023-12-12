#include <iostream>
using namespace std;

#include "./headFile/ending.h"

// 檢查並觸發遊戲結局
void Ending :: checkForEnding(Player& player, Game& game)
{
    // 設計最高與最低的數值
    const int MIN_BALANCE_VALUE = -50;
    const int MAX_BALANCE_VALUE = 50;

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

    // 
}
// 檢查玩家數值是否過高或過低
bool Ending :: isValuesBalanced(Player& player, int minVal, int maxVal)
{

    bool restartGame = false;
    
    if(player.value1 >= MAX_BALANCE_VALUE){
        cout << "物價斷層上漲，民眾苦不堪言，你被投票罷免，往後將受民眾唾棄…" << endl;
        restartGame = true;
    } else if(player.value1 <= MIN_BALANCE_VALUE){
        cout << "民生凋落，你被闖入的民眾集體瓜分，不知去向…" << endl;
        restartGame = true;
    } else if(player.value2 >= MAX_BALANCE_VALUE){
        cout << "你被拱為民眾的偶像，不斷的吹捧中你迷失自我。在一次的小錯誤中，你被推下神壇，成為萬人唾棄的對象…" << endl;
        restartGame = true;
    } else if (player.value2 <= MIN_BALANCE_VALUE){
        cout << "每次你出門，總是被路過的人民丟食物或廚餘，你再也受不了這樣的對待，從此消聲匿跡…" << endl;
        restartGame = true;
    } else if(player.value3 >= MAX_BALANCE_VALUE){
        cout << "你結交了很多朋友，但在一次的衝突中你無法為兩方朋友站場，雙方不滿的將你解決了…" << endl;
        restartGame = true;
    } else if (player.value3 <= MIN_BALANCE_VALUE){
        cout << "你在國際被孤立，沒有人願意在出事時幫助你，就這樣，你的國家漸漸地在世界中消失了…" << endl;
        restartGame = true;
    } else if(player.value4 >= MAX_BALANCE_VALUE){
        cout << "科技快速發展，你的國家成為了法外之地。在一次出門中，你被最新科技鎖定…" << endl;
        restartGame = true;
    } else if (player.value4 <= MIN_BALANCE_VALUE){
        cout << "沒有科技的社會猶如一片死水，你的國家成為了他國的附屬品…" << endl;
        restartGame = true;
    }
   /* return (player.value1 >= minVal && player.value1 <= maxVal &&
            player.value2 >= minVal && player.value2 <= maxVal &&
            player.value3 >= minVal && player.value3 <= maxVal &&
            player.value4 >= minVal && player.value4 <= maxVal);*/
}

// 檢查是否達到普通結局條件
bool Ending :: isNormalEndingAchieved(Game& game)
{
// 是否已經讀取特定數字的卡牌
}

// 重啟結局
void Ending :: restartEnding()
{
    cout << "旅程即將重新開始…" << endl;
    // 重新初始化遊戲
}



// 普通結局
void Ending :: normalEnding()
{
    cout << "恭喜！你已成功克服了每一個遇到的挑戰！你的洞察力和決策能力令人印象深刻。" << endl 
        << "你在鋪著國家前進的道路上展現出了無限的潛力，你的每一個決策都為這個國家的未來帶來了光明和希望。" << endl
        << "通過這個挑戰，你展現了自己在政治領域的非凡才華，也證明了你是一位出色的領袖。 << endl
        << 讓我們期待看到你在這場角色扮演的旅程中，繼續為這個國家帶來更多的繁榮和進步！" << endl
        << "祝賀你，這次的勝利只是你不斷追求卓越的開始！" << endl;

    // 數值顯示
    cout << "在這場旅程中，你最後以這樣的數值為這段故事寫下結局：" << endl
        << "經濟：" << player.value1 << endl
        << "聲望：" << player.value2 << endl
        << "外交：" << player.value3 << endl
        << "發展:" << player.value4 << endl;
}

