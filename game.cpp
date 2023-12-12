#include <iostream>
#include "card.h"

class Game {
private:
    int currentIndex;
    Player player;

public:
    Game(int startingIndex, const Player& initialPlayer)
        : currentIndex(startingIndex), player(initialPlayer) {}

    void start() {
        while (true) {
            // 顯示當前卡牌的內容和數值
            showCard();
            // 接收玩家的指令
            char userInput;
            std::cout << "請選擇 (左鍵: l, 右鍵: r，離開: q): ";
            std::cin >> userInput;

            // 根據玩家的指令做出相應的處理
            switch (userInput) {
                case 'l':
                    handleLeftChoice();
                    break;
                case 'r':
                    handleRightChoice();
                    break;
                case 'q':
                    endGame();
                    return;
                default:
                    std::cout << "無效的指令，請重新輸入。" << std::endl;
                    break;
            }
        }
    }

private:
    void showCard() {
        // 顯示當前卡牌的內容和數值
        std::cout << "當前卡牌內容：" << getCurrentCard().getDescription() << std::endl;
        std::cout << "經濟：" << player.getEconomy() << " 軍事：" << player.getMilitary()
                  << " 聲望：" << player.getPrestige() << " 外交：" << player.getDiplomacy() << std::endl;
    }

    const Card& getCurrentCard() const {
        // 根據當前的索引取得卡牌
        // 此處假設你有一個用於存儲所有卡牌的向量 cards
        // 注意：這需要你的 Card 類別有一個 getIndex 函式，可以取得卡牌的索引
        return cards[currentIndex];
    }

    void handleLeftChoice() {
        // 左選項的處理邏輯
        const Card& currentCard = getCurrentCard();
        const Description& leftChoice = currentCard.getLeftChoice();

        // 更新玩家數值
        player.updateValues(leftChoice);

        // 移動到下一個卡牌的索引
        currentIndex = leftChoice.getNextIndex();
    }

    void handleRightChoice() {
        // 右選項的處理邏輯
        const Card& currentCard = getCurrentCard();
        const Description& rightChoice = currentCard.getRightChoice();

        // 更新玩家數值
        player.updateValues(rightChoice);

        // 移動到下一個卡牌的索引
        currentIndex = rightChoice.getNextIndex();
    }

    void endGame() {
        std::cout << "遊戲結束。最終數值：" << std::endl;
        std::cout << "經濟：" << player.getEconomy() << " 軍事：" << player.getMilitary()
                  << " 聲望：" << player.getPrestige() << " 外交：" << player.getDiplomacy() << std::endl;
    }
};

