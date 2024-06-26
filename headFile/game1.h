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
	vector<Card* > nrCard;
	vector<EventCard> eventCard;
	int nrIdx;//which card are we now
	int eCardIdx;
	//
	int totalCardNumNeedToProcess = 21;
	vector<int> cardAppearSeq;
public:
	Game(vector<Card* > card, vector<EventCard> eCard, Player& PLAYER);
	~Game(){}
	void displayQuestion(); // when achieve the cardAppearSeq's last card, tragger the normal ending
	void displayEQuestion();
	void event();
	void getChoice();

};






#endif
