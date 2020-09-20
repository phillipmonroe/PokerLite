#define A 1

/**
* This class represents a standard playing card
* 
* @author Phillip Monroe
*/
class Card 
{
public:
	enum Suit : char {
		Hearts = 'H',
		Spades = 'S',
		Diamonds = 'D',
		Clubs = 'C'
	};

	/**
	* Constructor for a Card object
	*
	* @param value value of the card
	* @param suit suit of the card
	*/
	Card(int value, enum Suit suit)
	{
		this->value = value;
		this->suit = suit;
	}
	
	/**
	* Default constructor for a Card object.
	* The default card is Ace of Spades.
	*/
	Card()
	{
		value = A;
		suit = Spades;
	}

private:
	int value;
	enum Suit suit;

public:
	/**
	* Returns the value of the card
	* 
	* @return value of the card
	*/
	int GetValue()
	{
		return value;
	}

	/**
	* Returns the suit of the card
	*
	* @return suit of the card
	*/
	Suit GetSuit()
	{
		return suit;
	}

	/**
	* Prints the card to the console.
	*/
	void Print()
	{
		if (value == A)
		{
			std::cout << "A of " << suit << "\n";
		}
		else
		{
			std::cout << value << " of " << suit << "\n";
		}
	}
	
};
