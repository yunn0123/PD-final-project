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
            // ��ܷ�e�d�P�����e�M�ƭ�
            showCard();
            // �������a�����O
            char userInput;
            std::cout << "�п�� (����: l, �k��: r�A���}: q): ";
            std::cin >> userInput;

            // �ھڪ��a�����O���X�������B�z
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
                    std::cout << "�L�Ī����O�A�Э��s��J�C" << std::endl;
                    break;
            }
        }
    }

private:
    void showCard() {
        // ��ܷ�e�d�P�����e�M�ƭ�
        std::cout << "��e�d�P���e�G" << getCurrentCard().getDescription() << std::endl;
        std::cout << "�g�١G" << player.getEconomy() << " �x�ơG" << player.getMilitary()
                  << " �n��G" << player.getPrestige() << " �~��G" << player.getDiplomacy() << std::endl;
    }

    const Card& getCurrentCard() const {
        // �ھڷ�e�����ި��o�d�P
        // ���B���]�A���@�ӥΩ�s�x�Ҧ��d�P���V�q cards
        // �`�N�G�o�ݭn�A�� Card ���O���@�� getIndex �禡�A�i�H���o�d�P������
        return cards[currentIndex];
    }

    void handleLeftChoice() {
        // ���ﶵ���B�z�޿�
        const Card& currentCard = getCurrentCard();
        const Description& leftChoice = currentCard.getLeftChoice();

        // ��s���a�ƭ�
        player.updateValues(leftChoice);

        // ���ʨ�U�@�ӥd�P������
        currentIndex = leftChoice.getNextIndex();
    }

    void handleRightChoice() {
        // �k�ﶵ���B�z�޿�
        const Card& currentCard = getCurrentCard();
        const Description& rightChoice = currentCard.getRightChoice();

        // ��s���a�ƭ�
        player.updateValues(rightChoice);

        // ���ʨ�U�@�ӥd�P������
        currentIndex = rightChoice.getNextIndex();
    }

    void endGame() {
        std::cout << "�C�������C�̲׼ƭȡG" << std::endl;
        std::cout << "�g�١G" << player.getEconomy() << " �x�ơG" << player.getMilitary()
                  << " �n��G" << player.getPrestige() << " �~��G" << player.getDiplomacy() << std::endl;
    }
};

