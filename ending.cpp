#include <iostream>
using namespace std;

#include "./headFile/ending.h"

// �ˬd��Ĳ�o�C������
void Ending :: checkForEnding(Player& player, Game& game)
{
    // �]�p���Ū��ƭȡ]�i��^
    const int MIN_BALANCE_VALUE = 5;
    const int MAX_BALANCE_VALUE = 20;

    // �ˬd�O�_�F��ݭ���������
    if (!isValuesBalanced(player, MIN_BALANCE_VALUE, MAX_BALANCE_VALUE)) {
        restartEnding();
        return;
    }

    // �ˬd�O�_�F�촶�q����������
    if (isNormalEndingAchieved(game)) {
        normalEnding();
        return;
    }

    // �ˬd�O�_�������õ���
    if (isHiddenEndingUnlocked(player)) {
        hiddenEnding();
        return;
    }

    // 
}
// �ˬd���a�ƭȬO�_����
bool Ending :: isValuesBalanced(Player& player, int minVal, int maxVal)
{
    return (player.value1 >= minVal && player.value1 <= maxVal &&
            player.value2 >= minVal && player.value2 <= maxVal &&
            player.value3 >= minVal && player.value3 <= maxVal &&
            player.value4 >= minVal && player.value4 <= maxVal);
}

// �ˬd�O�_�F�촶�q��������
bool Ending :: isNormalEndingAchieved(Game& game)
{
    // �ˬd�n�]���a��O�_������ or �S�w�ƥ�O�_�QĲ�o
    // return game.isAllProcessCompleted();
}

// �ˬd�O�_�������õ����]�n�ݦ��S���S��D��^
bool Ending :: isHiddenEndingUnlocked(Player& player)
{
    // �ˬd���a���D�㤤�O�_�]�t�S�w�D��
    // return player.hasSecretItem(); 
}

// ���ҵ���
void Ending :: restartEnding()
{
    cout << "..." << endl;
    // ���s��l�ƹC��
}

// ���q����
void Ending :: normalEnding()
{
    cout << "..." << endl;
    // �����G�Ʊԭz��r or ��������
}

// ���õ���
void Ending :: hiddenEnding()
{
    cout << "..." << endl;
    // ���õ����G�Ʊԭz��r or ����S����y�i�H�}�ҷs���C�����e
}