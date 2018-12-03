/* Netanel Hugi 203553490 */

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"

class Game
{
  private:
	int cardsNumber;   //Number of cards for each player at the beginning of the game.
	Card nowCard;	  //current card.
	int playersNumber; //The number of player in the game.
	bool direction;	//game direction, true: 1->9, false: 9->1

	//private copy constructor and operator(without implementation) for disable the default implementation.
	Game(const Game &other);
	Game &operator=(const Game &other);

  public:
	Game();  //constructor, ask for players&cards numbers.
	~Game(); //destructor

	void start();			   //init game, create players, and draws the first card.
	vector<Player *> *players; //Contains the game players.
	Player *nowTurn;		   //current player
	int idTurn;				   //the index of current player in Players.
	bool GAMEOVER;			   //false: still playing, true: someone wins.

	void printPlayersList() const;			 //print number, and player name.
	void nextTurn();						 //run until GAMEOVER
	int nextStep(bool dir, int steps) const; //retrun the next player index.
	bool getDirection() const;				 //Return the current direction.
};
#endif
