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
private:
	Suit suit;
	int value;
public:
	Card(int value, Suit suit)
	{
		this->suit = suit;
		this->value = value;
	}

	int GetValue()
	{
		return value;
	}

	Suit GetSuit()
	{
		return suit;
	}
	
};
