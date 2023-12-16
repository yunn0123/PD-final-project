 #include <Windows.h>
 #include <iostream>
 #include <vector>
 using namespace std;

#ifndef GAME_H
#define GAME_H

#include "ending.h"
#include "card.h"
#include "character.h"
#include "item.h"

class Game
{
private:
	vector<NormalCard> normalCard; 
	vector<RandomCard> randomCard; 
	vector<EventCard> eventCard; 
	int nCardIdx;//which card are we now
	int rCardIdx;
	int eCardIdx;
	int nQuestionIdx;//which Question are we now
	int rQuestionIdx;
	int eQuestionIdx;    
	Player PLAYER;
public:
	//void setup();//initialization and read card text
	Game(vector<NormalCard> nCard, vector<RandomCard> rCard, vector<EventCard> eCard, Player Player);
	~Game();
	void displayQuestion();
	void getChoice();
	void theEnd();//ending
};

 
#endif
