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
			std::cout << "[ERROR]: This hand is already full!"
		}
	}

};