// #include <iostream>
// #include <string>
// using namespace std;

// // 可以把player, card, game另外弄成header files
// // 玩家類別 --> (character)
// class Player {
// public:
//     int value1, value2, value3, value4; // 四個主要數值

//     Player() : value1(10), value2(10), value3(10), value4(10) {}

//     void updateValues(int change1, int change2, int change3, int change4) {
//         value1 += change1;
//         value2 += change2;
//         value3 += change3;
//         value4 += change4;
//         checkForEndGame();
//     }

//     void checkForEndGame() {
//         if (value1 <= 0 || value2 <= 0 || value3 <= 0 || value4 <= 0) {
            
//             exit(0); // exit或處理死亡結局
//         }

//         // 最終結局的條件判斷
//         // if (value1 > 20 && value2 > 20 && ...)
//     }
// };

// // 卡牌 --> (player)
// class Card : public Player{
// public:
//     string description; // 卡牌描述

//     Card(const string &desc) : description(desc) {}

//     void applyChoice(Player &player, bool choice) {
//         if (choice) {
//             player.updateValues(1, -1, 0, 0); // ...
//         } else {
//             player.updateValues(-1, 1, 0, 0); 
//     } // ...
//     // child class:
//         // 1. 一般卡牌(會影響數值的)
//         // 2. 旁白卡牌(沒有選項，不會影響數值的)

// };

// // 主幹: 遊戲主控類別 --> (game)
// class Game {
//     Player player;
//     Card cards[10]; // 固定大小的卡牌陣列

// public:
//     Game(int num) : numCards(num) {
//         cards = new Card[numCards];
//         // 初始化卡牌
//         int yes1[] = {1, -1, 0, 0};
//         int no1[] = {-1, 1, 0, 0}; // 可以寫很多組數值增減（但感覺有更好的方法？）
//         cards[0] = Card("卡牌描述1", yes1, no1); 
//         //cards[1] ...
//         // ...
//     }

//     ~Game() {
//         delete[] cards; // 釋放卡牌陣列
//     }

//     void start() {
//         for (int i = 0; i < numCards; ++i) {
//             cout << cards[i].description << endl;
            
//             // 選擇左(1)右 (0)...
//             bool choice;
//             cin >> choice;
//             cards[i].applyChoice(player, choice);

//             // 
//         }

//         cout << "THE END" << endl;
//     }
// };
// // ending --> (enemy)
// class ending : public {
//     friend class Player; // 取player裡面的數值
//     private:
//     public:
//         // check if  tragger the end
//         bool end1();
//         bool end2();
//         bool end3();
//         bool end4();
// };
// int main() {
//     Game game(numCards); // n(卡牌數)
//     game.start();
//     return 0;
// }



