#include <string>

/**
* This Class represents a hand of 3 cards to be used
* in PokerLite.
* 
* @author Phillip Monroe
*/
class Hand 
{
private:
	Card hand[3];
	int counter;
	std::string title;
public:
	/**
	* Constructor for an empty hand of cards
	*/
	Hand() 
	{
		counter = 0;
	}

	/**
	* Constructor for a hand of cards with one card
	* 
	* @param one
	*	card to store in the hand
	*/
	Hand(Card one)
	{
		counter = 1;
		hand[0] = one;
	}

	/**
	* Constructor for a hand of cards with two card
	* 
	* @param one, two
	*	card to store in the hand
	*/
	Hand(Card one, Card two)
	{
		counter = 2;
		hand[0] = one;
		hand[1] = two;
	}

	/**
	* Constructor for a hand of cards with three card
	* 
	* @param one, two, three
	*	card to store in the hand
	*/
	Hand(Card one, Card two, Card three)
	{
		counter = 3;
		hand[0] = one;
		hand[1] = two;
		hand[2] = three;
	}

	/**
	* Adds a card to the hand if it is not full
	* 
	* @param card
	*	card to add to the hand
	*/
	void AddCard(Card card)
	{
		if (counter <= 2)
		{
			hand[counter] = card;
			counter++;
		}
		else
		{
			std::cout << "[ERROR]: This hand is already full!";
		}
	}

	/**
	* Finds the card with the highest value in the hand
	* 
	* @return value of the highest card
	*/
	int HighCard() 
	{
		if (counter > 2)
		{
			if (hand[0].GetValue() == A || hand[1].GetValue() == A || hand[2].GetValue() == A)
			{
				return A;
			}

			if (hand[0].GetValue() >= hand[1].GetValue() && hand[0].GetValue() >= hand[2].GetValue()) {
				return hand[0].GetValue();
			}
			else
			{
				if (hand[1].GetValue() >= hand[2].GetValue())
				{
					return hand[1].GetValue();
				}
				else
				{
					return hand[2].GetValue();
				}
			}
		}
		else
		{
			std::cout << "[ERROR]: This hand is not full!";
			return -1;
		}
	}

	/**
	* Finds if the hand contains a flush
	* 
	* @return bool indicating if the hand has a flush
	*/
	bool IsFlush()
	{
		if(counter > 2)
		{
			if (hand[0].GetSuit() == hand[1].GetSuit() && hand[0].GetSuit() == hand[2].GetSuit())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			std::cout << "[ERROR]: This hand is not full!";
			return false;
		}
	}

	/**
	* Finds if the hand contains a straight
	*
	* @return bool indicating if the hand has a straight
	*/
	bool IsStraight()
	{
		if (counter > 2)
		{
			// Check if in range [n-2 ... n+2] (assuming n is value of hand[0]..referred to as 'first card' after this) 
			if (hand[1].GetValue() > (hand[0].GetValue() + 2) || hand[2].GetValue() > (hand[0].GetValue() + 2))
			{
				return false;
			}
			if (hand[1].GetValue() < (hand[0].GetValue() - 2) || hand[2].GetValue() < (hand[0].GetValue() - 2))
			{
				return false;
			}

			// Check that the values are not equal
			if (hand[0].GetValue() == hand[1].GetValue() || hand[0].GetValue() == hand[2].GetValue() || hand[1].GetValue() == hand[2].GetValue())
			{
				return false;
			}

			// Check if both are higher than first card
			if (hand[0].GetValue() > hand[1].GetValue() && hand[0].GetValue() > hand[2].GetValue())
			{
				// n, n+1, n+2
				return true;
			}

			// Check if both are lower than first card
			if (hand[0].GetValue() < hand[1].GetValue() && hand[0].GetValue() < hand[2].GetValue())
			{
				// n-2, n-1, n
				return true;
			}

			// Check if cards are 'sandwiching' first card without gaps
			if ((hand[1].GetValue() < (hand[0].GetValue() + 2) && hand[2].GetValue() > (hand[0].GetValue() - 2)) || (hand[1].GetValue() > (hand[0].GetValue() - 2) && hand[2].GetValue() < (hand[0].GetValue() + 2)))
			{
				// n-1, n, n+1
				return true;
			}
			else
			{
				// n-2, n, n+2
				return false;
			}
		}
		else
		{
			std::cout << "[ERROR]: This hand is not full!";
			return false;
		}
	}

	/**
	* Finds if the hand contains a pair
	*
	* @return value of the pair or 0 if there is no pair
	*/
	int HasPair()
	{
		if (hand[0].GetValue() == hand[1].GetValue())
		{
			return hand[0].GetValue();
		}

		if (hand[0].GetValue() == hand[2].GetValue())
		{
			return hand[0].GetValue();
		}

		if (hand[1].GetValue() == hand[2].GetValue())
		{
			return hand[1].GetValue();
		}

		return 0;
	}

	/**
	* Sets the title of the hand
	* 
	* @param title
	*	the title to give the hand
	*/
	void SetTitle(std::string title)
	{
		this->title = title;
	}
	
	/**
	* Gets the title of the hand
	* 
	* @return the title of the hand
	*/
	std::string GetTitle()
	{
		return title;
	}

	/**
	* Prints the contents of the hand
	* 
	* @param title
	*	title to give the hand
	*/
	void Print(std::string title)
	{
		SetTitle(title);
		if (counter > 2)
		{
			std::cout << title << ":\n";
			hand[0].Print();
			hand[1].Print();
			hand[2].Print();
		}
		else
		{
			std::cout << "[ERROR]: This hand is not full!";
		}
	}
};