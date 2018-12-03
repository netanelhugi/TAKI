/* Netanel Hugi 203553490 */

#include "Game.h"

Game::Game()
{
    playersNumber = 0;
    cardsNumber = 0;
    GAMEOVER = false;
    players = new vector<Player *>();

    cout << "How many players?" << endl;

    cin >> playersNumber;

    if (playersNumber < 2)
    {
        return;
    }

    cout << "How many cards?" << endl;
    cin >> cardsNumber;

    if (cardsNumber < 1)
    {
        return;
    }

}

Game::~Game()
{

    if (playersNumber > 1 && cardsNumber > 0)
    {
        int n = players->size();
        for (int i = 0; i < n; i++)
        {
            delete players->at(i);
        }
    }

    delete players;
}

void Game::start()
{
    if (playersNumber < 2 || cardsNumber < 1)
    {
        cout << "Error! You entered an incorrect value. Restart the game." << endl;
        return;
    }

    /*Create players*/
    for (int i = 0; i < playersNumber; i++)
    {
        cout << "player number " << i + 1 << " name?" << endl;
        string name;
        cin >> name;

        Player *p1 = new Player{name, cardsNumber};
        players->emplace_back(p1);
    }

    nowCard = generate_card(); //The open card.
    Player *pt = players->at(0);

    nowTurn = pt;

    nextTurn();
}

void Game::printPlayersList() const
{
    if (playersNumber > 1)
    {
        for (int i = 0; i < playersNumber; i++)
        {
            cout << "Player #" << i + 1 << ": " << players->at(i)->getName() << endl;
        }
    }
}

void Game::nextTurn()
{
    /*Run until the game over*/
    while (!GAMEOVER)
    {
        //Current player is play
        bool playInTurn = nowTurn->play(nowCard);

        //Check if the current player threw all his cards.
        if (nowTurn->getNumOfCards() == 0)
        {
            GAMEOVER = true;
            break;
        }

        //if the player take a card,
        //the game is continue by the current direction.
        if (!playInTurn)
        {
            idTurn = nextStep(direction, 1);
            nowTurn = players->at(idTurn);
        }

        else
        { //The player threw a card
            nowCard = nowTurn->getLastCard();

            if (nowCard.get_sign() == PLUS)
            {
                //do noting
            }
            else if (nowCard.get_sign() == CD)
            { //change direction
                if (getDirection() == true)
                {
                    direction = false;

                    idTurn = nextStep(direction, 1);
                    nowTurn = players->at(idTurn);
                }

                else
                {
                    direction = true;

                    idTurn = nextStep(direction, 1);
                    nowTurn = players->at(idTurn);
                }
            }

            else if (nowCard.get_sign() == STOP)
            { //Skip the next player turn.
                idTurn = nextStep(direction, 2);
                nowTurn = players->at(idTurn);
            }

            else
            { //Regular Card(numbers&TAKI)
                idTurn = nextStep(direction, 1);
                nowTurn = players->at(idTurn);
            }
        }
    }
}

int Game::nextStep(bool dir, int steps) const
{

    if (getDirection() == true)
    {
        return (idTurn + steps) % playersNumber;
    }

    else
    {
        if ((idTurn - steps) == -1)
        {
            return playersNumber - 1;
        }
        else if ((idTurn - steps) == -2)
        {
            return playersNumber - 2;
        }
        else
        {
            return idTurn - steps;
        }
    }
}

bool Game::getDirection() const
{
    return direction;
}
