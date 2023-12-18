#include <Windows.h>
#include <iostream>
#include <vector>
#include <time.h>

#ifndef GAME1_H
#define GAME1_H

#include "ending.h"
#include "card.h"
#include "character.h"
#include "item.h"

using namespace std;


class Game
{
private:
	vector<NormalCard> normalCard;
	vector<RandomCard> randomCard;
	vector<EventCard> eventCard;
	int nCardIdx;//which card are we now
	int rCardIdx;
	int eCardIdx;
	//
	int totalCardNumNeedToProcess = 10;
	vector<int> cardAppearSeq;
	// Player PLAYER;
public:
	//void setup();//initialization and read card text
	Game(vector<NormalCard> nCard, vector<RandomCard> rCard, vector<EventCard> eCard, Player& PLAYER);
	~Game(){}
	void displayQuestion(); // when achieve the normal ending, return 1
	void getChoice();
	void theEnd();//ending
	int getTotalseq();
};






#endif
