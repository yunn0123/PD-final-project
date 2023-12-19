#include <iostream>
using namespace std;

#include "./headFile/ending.h"

// ??????????��??????????????��?
void Ending :: checkForEnding(Player& player)
{
     // ??????????????????????????????
    const int minVal = 0;
    const int maxVal = 50;

    // ????????��????????�X??????????????????
    if (isValuesBalanced(player, minVal, maxVal)) {
        restartEnding(player);
        return;
    }

    // const string mothershipModel = "?��??????????";
    // const string trainModel = "????????????";
    // if (hasSpecificItem(player, mothershipModel) && hasSpecificItem(player, trainModel)) {
    //     hiddenEnding();
    //     return;
    // }

    bool hasAllItem = true;
    const bool* itemList = player.getItem();
    for(int i = 0; i < 4; i++){
        if(itemList[i] == 0){
            hasAllItem = false;
            break;
        }
    }
    if(hasAllItem){
        hiddenEnding();
        return;
    }


    //
}
// ????????????????????��??????????????????
bool Ending :: isValuesBalanced(Player& player, int minVal, int maxVal)
{

    bool restartGame = false;

    if(player.value1 >= maxVal){
        cout << "===========================================================" << endl;
        cout << "????????�P?��???????????�X?????????????????????????????????�P?????????????�X?????�X?????????????" << endl;
        cout << "===========================================================" << endl;
        restartGame = true;
    } else if(player.value1 <= minVal){
        cout << "===========================================" << endl;
        cout << "?�X?????????????????????????????�X??????????????????????????????????" << endl;
        cout << "===========================================" << endl;
        restartGame = true;
    } else if(player.value2 >= maxVal){
        cout << "===============================================================================================" << endl;
        cout << "????????��??????????????????????????�P????????��????????�P??��??????????????????????�X???��????????????????????????????????????????????????????�X??��????" << endl;
        cout << "===============================================================================================" << endl;
        restartGame = true;
    } else if (player.value2 <= minVal){
        cout << "===============================================================================" << endl;
        cout << "?��?????????????????????��????�P��?????????????????????????????????????????????????????????????�X???????????????????????�P????" << endl;
        cout << "===============================================================================" << endl;
        restartGame = true;
    } else if(player.value3 >= maxVal){
        cout << "==============================================================================" << endl;
        cout << "????????????????????????????????????????????????????????????????????????????????????????????????????�X?????��??��???????" << endl;
        cout << "==============================================================================" << endl;
        restartGame = true;
    } else if (player.value3 <= minVal){
        cout << "================================================================================" << endl;
        cout << "????????????????????????????????????????????????????????????????�X��?????????????????????????????�X?????????????????��??????" << endl;
        cout << "================================================================================" << endl;
        restartGame = true;
    } else if(player.value4 >= maxVal){
        cout << "======================================================================" << endl;
        cout << "?��???????????????????????????????????????????????????�X???????????????????????????????????�X???????????????" << endl;
        cout << "======================================================================" << endl;
        restartGame = true;
    } else if (player.value4 <= minVal){
        cout << "======================================================================" << endl;
        cout << "???????��?????????????????????????????�X??????????????????????????????????????��????????????????????????????" << endl;
        cout << "======================================================================" << endl;
        restartGame = true;
    }
    return restartGame;
}

//????????��?????????????????????
// bool Ending::hasSpecificItem(Player& player, const string itemName) {
//     for (const Item item : player.getItem()) {
//         if (item.getName() == itemName) {
//             return true;
//         }
//     }
//     return false;
// }

// ??????????��?
void Ending :: restartEnding(Player& player)
{
    cout << "?????????????????�X????��?......." << endl;
    // ?????�X????��???????????????????????��????????????????????????????
    player.restart = true;
    player.value1 = INI_VAL;
    player.value2 = INI_VAL;
    player.value3 = INI_VAL;
    player.value4 = INI_VAL;

}



// ??????????��?
void Ending :: normalEnding()
{
    cout << "?????????????�P???????????��????????????�X????????�X?????????????��????????��??????????????????�X?��??�P��??????" << endl
        << "???????????????????????????????�P��????��???????????????????????????????????��????????��??????????????????????????????????????????????????????????" << endl
        << "?????????????????�X???????��???????????�P��?????????????????????????????��????????????????????��????????????????????????" << endl
        << "????????????????????�X?????????????????????????????????????????????????????????????????????????????????????????????" << endl
        << "????????????????????????????????��????????�P????��??????????????��????" << endl;

    // ????????��???
    cout << "????????????????????????????????????????????????????????????????��????????��????" << endl
        << "?????????" << PLAYER.value1 << endl
        << "?????????" << PLAYER.value2 << endl
        << "?????????" << PLAYER.value3 << endl
        << "???????????????" << PLAYER.value4 << endl;
}

void Ending :: hiddenEnding()
{
    cout << "???????????????????????????????��?????????????????��???????????�X??????????????�P????????????��????????????????????????" << endl;
    cout << "????????��????�P��???????�X???????????????��??????????????�P?????????????????????????????��?????????????????????" << endl;
    cout << "??????????????�X????��?????????????????????????????��????????????????????????????????????????????�X??????????????????????????????????????????????????��????" << endl;
    cout << "????????????????????????????????????????????????????????????????????�X???" << endl;
    cout << "????????????????????????????????????????????????????????????????�P???��???????�X��???????�X????????????��???????????????????�X??????????????????????" << endl;
    cout << "????????????????????????????????��????????????????????��?????????????�P��??????????????????????????????????????�X??????????��???????" << endl;
    cout << "???????????????????????��?????????????????????????????��?????????????�X?????????????????????????" << endl;

}


