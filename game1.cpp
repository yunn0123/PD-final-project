#include "./headFile/game.h"
using namespace std;

Game :: Game(vector<NormalCard> nCard, vector<RandomCard> rCard, vector<EventCard> eCard, Player PLAYER)
{
	normalCard = nCard;
	randomCard = rCard;
	eventCard = eCard;
	nCardIdx = -1;
	rCardIdx = -1;
	eCardIdx = -1;
	nQuestionIdx = -1;
	rQuestionIdx = -1;
	eQuestionIdx = -1;
}
 
void Game :: displayQuestion()
{
	if(normalCard[this->nCardIdx].nowQuestion < normalCard[this->nCardIdx].questionCnt)
	{
		normalCard[this->nCardIdx].gameCallPrint();
		normalCard[this->nCardIdx].nowQuestion += 1;
	}
	this->nCardIdx  += 1;
}

void Game :: getChoice()
{
    if(GetAsyncKeyState(VK_LEFT) && 0x8001){ // choose left
        keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
        nowChoice = 1;
        PLAYER.updateValues(totalOpt[nowQuestion].val1[0], totalOpt[nowQuestion].val1[1], totalOpt[nowQuestion].val1[2], totalOpt[nowQuestion].val1[3]);
        break;
    }
    if(GetAsyncKeyState(VK_RIGHT) && 0x8001){ // choose right
        keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
        nowChoice = 2;
        PLAYER.updateValues(totalOpt[nowQuestion].val2[0], totalOpt[nowQuestion].val2[1], totalOpt[nowQuestion].val2[2], totalOpt[nowQuestion].val2[3]);

        break;
    }
}
