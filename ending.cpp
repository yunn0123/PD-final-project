#include <iostream>
using namespace std;

#include "./headFile/ending.h"

// �ˬd��Ĳ�o�C������
void Ending :: checkForEnding(Player& player, Game& game)
{
    // �]�p�̰��P�̧C���ƭ�
    const int MIN_BALANCE_VALUE = 0;
    const int MAX_BALANCE_VALUE = 50;

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

    // 
}
// �ˬd���a�ƭȬO�_�L���ιL�C
bool Ending :: isValuesBalanced(Player& player, int minVal, int maxVal)
{

    bool restartGame = false;
    
    if(player.value1 >= maxVal){
        cout << "�����_�h�W���A�����W�������A�A�Q�벼�}�K�A����N���������K" << endl;
        restartGame = true;
    } else if(player.value1 <= minVal){
        cout << "���ͭ丨�A�A�Q���J����������ʤ��A�����h�V�K" << endl;
        restartGame = true;
    } else if(player.value2 >= maxVal){
        cout << "�A�Q���������������A���_���j�����A�g���ۧڡC�b�@�����p���~���A�A�Q���U���¡A�����U�H��󪺹�H�K" << endl;
        restartGame = true;
    } else if (player.value2 <= minVal){
        cout << "�C���A�X���A�`�O�Q���L���H���᭹���μp�l�A�A�A�]�����F�o�˪���ݡA�q�����n�θ�K" << endl;
        restartGame = true;
    } else if(player.value3 >= maxVal){
        cout << "�A����F�ܦh�B�͡A���b�@�����Ĭ𤤧A�L�k�����B�ͯ����A���褣�����N�A�ѨM�F�K" << endl;
        restartGame = true;
    } else if (player.value3 <= minVal){
        cout << "�A�b��ڳQ�t�ߡA�S���H�@�N�b�X�Ʈ����U�A�A�N�o�ˡA�A����a�����a�b�@�ɤ������F�K" << endl;
        restartGame = true;
    } else if(player.value4 >= maxVal){
        cout << "��ާֳt�o�i�A�A����a�����F�k�~���a�C�b�@���X�����A�A�Q�̷s�����w�K" << endl;
        restartGame = true;
    } else if (player.value4 <= minVal){
        cout << "�S����ު����|�S�p�@�������A�A����a�����F�L�ꪺ���ݫ~�K" << endl;
        restartGame = true;
    }
}

// �ˬd�O�_�F�촶�q��������
bool Ending :: isNormalEndingAchieved(Game& game)
{
// �O�_�w�gŪ���S�w�Ʀr���d�P
}

// ���ҵ���
void Ending :: restartEnding()
{
    cout << "�ȵ{�Y�N���s�}�l�K" << endl;
    // ���s��l�ƹC���A�ƭȪ�l�ơA���^�̪쪺�d�P
}



// ���q����
void Ending :: normalEnding()
{
    cout << "���ߡI�A�w���\�J�A�F�C�@�ӹJ�쪺�D�ԡI�A���}��O�M�M����O�O�H�L�H�`��I" << endl 
        << "�A�b�Q�۰�a�e�i���D���W�i�{�X�F�L������O�A�A���C�@�ӨM�������o�Ӱ�a�����ӱa�ӤF�����M�Ʊ�C" << endl
        << "�q�L�o�ӬD�ԡA�A�i�{�F�ۤv�b�F�v��쪺�D�Z�~�ءA�]�ҩ��F�A�O�@��X�⪺��S�C" << endl
        << "���ڭ̴��ݬݨ�A�b�o�������t���ȵ{���A�~�򬰳o�Ӱ�a�a�ӧ�h���c�a�M�i�B�I" << endl
        << "���P�A�A�o�����ӧQ�u�O�A���_�l�D���V���}�l�K" << endl;

    // �ƭ����
    cout << "�b�o���ȵ{���A�A�̫�H�o�˪��ƭȬ��o�q�G�Ƽg�U�����G" << endl
        << "�g�١G" << PLAYER.value1 << endl
        << "�n��G" << PLAYER.value2 << endl
        << "�~��G" << PLAYER.value3 << endl
        << "�o�i:" << PLAYER.value4 << endl; // �|�PGame.cpp����i��n��@�U
}
