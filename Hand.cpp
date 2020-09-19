class Hand 
{
private:
	Card hand[3];
	int counter;
public:
	Hand() 
	{
		counter = 0;
	}

	Hand(Card one)
	{
		counter = 1;
		hand[0] = one;
	}

	Hand(Card one, Card two)
	{
		counter = 2;
		hand[0] = one;
		hand[1] = two;
	}

	Hand(Card one, Card two, Card three)
	{
		counter = 3;
		hand[0] = one;
		hand[1] = two;
		hand[2] = three;
	}

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

	int HighCard() 
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

	bool IsFlush()
	{
		if (hand[0].GetSuit() == hand[1].GetSuit() == hand[2].GetSuit())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};