/* Netanel Hugi 203553490 */

#include "Player.h"
#include <iterator>

Player::Player()
{
    name = "israel israeli";
    num_of_cards = 2;
    myCards = new vector<Card>();

    for (int i = 0; i < num_of_cards; i++)
    {
        Card t = generate_card();
        myCards->emplace_back(t);
    }
}

Player::Player(string myName, int num)
{
    name = myName;
    if (num > 0)
    {
        myCards = new vector<Card>();
    }
    num_of_cards = num;

    for (int i = 0; i < num_of_cards; i++)
    {
        Card t = generate_card();
        myCards->emplace_back(t);
    }
}

Player::~Player()
{
    delete myCards;
}

Player::Player(const Player &other)
{
    this->name = other.name;
    this->num_of_cards = other.num_of_cards;

    myCards = new vector<Card>();

    for (int i = 0; i < num_of_cards; i++)
    {
        this->myCards->emplace_back(other.myCards->at(i));
    }
}

Player &Player::operator=(const Player &other)
{
    this->name = other.name;
    this->num_of_cards = other.num_of_cards;

    myCards = new vector<Card>();

    for (int i = 0; i < num_of_cards; i++)
    {
        this->myCards->emplace_back(other.myCards->at(i));
    }

    return *this;
}

string Player::getName() const
{
    return this->name;
}

void Player::printMyCards() const
{
    cout << "Your cards: ";

    for (int i = 0; i < num_of_cards; i++)
    {
        cout << "(" << i + 1 << ")" << myCards->at(i) << " ";
    }

    cout << endl;
}

bool Player::play(Card &c)
{
    cout << "current: " << c << endl;
    cout << this->getName() << ", your turn - " << endl;
    this->printMyCards();

    int choose;
    cin >> choose;

    /*The player choose number not in the range: take another card,return false*/
    if (choose <= 0 || choose > num_of_cards)
    {
        Card n = generate_card();

        num_of_cards++;
        myCards->emplace_back(n);

        return false;
    }

    /*The player choose card from his hand, the function check if the choose is valid*/
    else
    {
        Card temp = myCards->at(choose - 1);

        /*If the the choose invalid, the user stay in the loop until he choose valid number*/
        while (!c.is_leggal(temp))
        {
            cout << "You can't put " << temp << " on " << c << endl;

            cin >> choose;

            if (choose <= 0 || choose > num_of_cards)
            {
                Card n = generate_card();

                num_of_cards++;
                myCards->emplace_back(n);
                return false;
            }

            temp = myCards->at(choose - 1);
        }

        lastCard = temp;
        myCards->erase(myCards->begin() + (choose - 1));
        this->num_of_cards--;

        //This player win.
        if (num_of_cards == 0)
        {
            cout << this->getName() << " wins!" << endl;
        }
    }

    return true;
}

int Player::getNumOfCards() const
{
    return num_of_cards;
}

const Card &Player::getLastCard()
{
    return lastCard;
}
