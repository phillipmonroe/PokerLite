#define A 1

class Card 
{
public:
	enum Suit : char {
		Hearts = 'H',
		Spades = 'S',
		Diamonds = 'D',
		Clubs = 'C'
	};

	Card(int value, Suit suit)
	{
		this->value = value;
		this->suit = suit;
	}
	
	Card()
	{
		value = A;
		suit = Spades;
	}

private:
	int value;
	Suit suit;

public:
	int GetValue()
	{
		return value;
	}

	Suit GetSuit()
	{
		return suit;
	}
	
};
