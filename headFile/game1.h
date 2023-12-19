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
	vector<Card* > card;
	vector<EventCard> eventCard;
	int cardIdx;//which card are we now
	int eventIdx;
	//
	int totalCardNumNeedToProcess = 10;
	vector<int> cardAppearSeq;
public:
	//void setup();//initialization and read card text
	Game(vector<Card* > card, vector<EventCard> eCard, Player& PLAYER);
	~Game(){}
	void displayQuestion(); // when achieve the normal ending, return 1
	void event();
	void getChoice();
	void theEnd();//ending
	int getTotalseq();
};






#endif
