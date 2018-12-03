/* Netanel Hugi 203553490 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <vector>

class Player
{
  private:
	string name;		   //player name.
	int num_of_cards;	  //player current number of cards.
	vector<Card> *myCards; //vector of cards, "player hand".
	Card lastCard;		   //the last card the player that the player threw.

  public:
	Player();						//default constructor.
	Player(string myName, int num); //constructor, get name, and number of cards.
	~Player();						//destructor.

	Player(const Player &other);			//Copy constructor.
	Player &operator=(const Player &other); //Copy operator.

	//get the current card, and wait to user choose.
	//return: true- if the user therw a card, false- if the user take a card.
	bool play(Card &);

	string getName() const;	//return player name.
	void printMyCards() const; //print "player hand".
	int getNumOfCards() const; //print the player current number of cards.
	const Card &getLastCard(); //return reference to the last card the player play with.
};
#endif
