#include <iostream>
using namespace std;

#include "./headFile/ending.h"

// �ˬd��Ĳ�o�C������
void Ending :: checkForEnding(Player& player)
{
     // �]�p�̰��P�̧C���ƭ�
    const int minVal = 0;
    const int maxVal = 50;

    // �ˬd�O�_�F��ݭ���������
    if (isValuesBalanced(player, minVal, maxVal)) {
        restartEnding(player);
        return;
    }

    const string mothershipModel = "��ĥ�ҫ�";
    const string trainModel = "�����ҫ�";
    if (hasSpecificItem(player, mothershipModel) && hasSpecificItem(player, trainModel)) {
        hiddenEnding();
        return;
    }


    //
}
// �ˬd���a�ƭȬO�_�L���ιL�C
bool Ending :: isValuesBalanced(Player& player, int minVal, int maxVal)
{

    bool restartGame = false;

    if(player.value1 >= maxVal){
        cout << "===========================================================" << endl;
        cout << "�����_�h�W���A�����W�������A�A�Q�벼�}�K�A����N���������K" << endl;
        cout << "===========================================================" << endl;
        restartGame = true;
    } else if(player.value1 <= minVal){
        cout << "===========================================" << endl;
        cout << "���ͭ丨�A�A�Q���J����������ʤ��A�����h�V�K" << endl;
        cout << "===========================================" << endl;
        restartGame = true;
    } else if(player.value2 >= maxVal){
        cout << "===============================================================================================" << endl;
        cout << "�A�Q���������������A���_���j�����A�g���ۧڡC�b�@�����p���~���A�A�Q���U���¡A�����U�H��󪺹�H�K" << endl;
        cout << "===============================================================================================" << endl;
        restartGame = true;
    } else if (player.value2 <= minVal){
        cout << "===============================================================================" << endl;
        cout << "�C���A�X���A�`�O�Q���L���H���᭹���μp�l�A�A�A�]�����F�o�˪���ݡA�q�����n�θ�K" << endl;
        cout << "===============================================================================" << endl;
        restartGame = true;
    } else if(player.value3 >= maxVal){
        cout << "==============================================================================" << endl;
        cout << "�A����F�ܦh�B�͡A���b�@�����Ĭ𤤧A�L�k�����B�ͯ����A���褣�����N�A�ѨM�F�K" << endl;
        cout << "==============================================================================" << endl;
        restartGame = true;
    } else if (player.value3 <= minVal){
        cout << "================================================================================" << endl;
        cout << "�A�b��ڳQ�t�ߡA�S���H�@�N�b�X�Ʈ����U�A�A�N�o�ˡA�A����a�����a�b�@�ɤ������F�K" << endl;
        cout << "================================================================================" << endl;
        restartGame = true;
    } else if(player.value4 >= maxVal){
        cout << "======================================================================" << endl;
        cout << "��ާֳt�o�i�A�A����a�����F�k�~���a�C�b�@���X�����A�A�Q�̷s�����w�K" << endl;
        cout << "======================================================================" << endl;
        restartGame = true;
    } else if (player.value4 <= minVal){
        cout << "======================================================================" << endl;
        cout << "�S����ު����|�S�p�@�������A�A����a�����F�L�ꪺ���ݫ~�A�]���A�ݭn�A�K" << endl;
        cout << "======================================================================" << endl;
        restartGame = true;
    }
    return restartGame;
}

//�ˬd�O�_���S�w���D��
bool Ending::hasSpecificItem(Player& player, const string itemName) {
    for (const Item item : player.getItem()) {
        if (item.getName() == itemName) {
            return true;
        }
    }
    return false;
}

// ���ҵ���
void Ending :: restartEnding(Player& player)
{
    cout << "�ȵ{�Y�N���s�}�l�K" << endl;
    // ���s��l�ƹC���A�ƭȪ�l�ơA���^�̪쪺�d�P
    player.restart = true;
    player.value1 = INI_VAL;
    player.value2 = INI_VAL;
    player.value3 = INI_VAL;
    player.value4 = INI_VAL;

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
        << "�o�i�G" << PLAYER.value4 << endl;
}

void Ending :: hiddenEnding()
{
     cout << "�H�ۧA�b�o��ȵ{���Үi�{�X�����V�M���M��ɤ~��A�A�w���ȶȬO�@���a����S�C" << endl;
    cout << "�A�����߲`�B�A���ҫ������R�v�������A�����F�A�ͬ������i�ίʪ��@�����C" << endl;
    cout << "�q�A�����쪺��ĥ�ҫ��M�����ҫ��}�l�A�A���줽�ǳv�����ܦ��F�@�Ӥp���ժ��]�A�l�ޤF�L�ƦP�n�̫e�Ӱ��[�C" << endl;
    cout << "�A�����ë~�����F����Ʀܥ��@�ɼҫ��R�n�̪��t�a�C" << endl;
    cout << "�b�A���޻�U�A��a���Ȧb�F�v�M�g�٤W���o�F���j�����N�A�A��ҫ������R�]�����F�����ƪ��@�����C" << endl;
    cout << "�A���G���ҩ��F�A�Y�ϬO��a��S�A�]�i�H�֦��ۤv���R�n�A�ñN�o���R�n���ɨ����N���h���C" << endl;
    cout << "���ߧA�A�A���ȬO�@�즨�\����S�A�]�O�@��ƨ��L�q���ҫ����îa�C" << endl;

}


