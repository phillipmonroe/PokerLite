#include <iostream>
#include "Card.cpp"
#include "Hand.cpp"
#include "Deck.cpp"

void FindHigher(Hand first, Hand second)
{
    if (first.HighCard() == second.HighCard())
    {
        std::cout << "Tie!\n";
    }
    else
    {
        if (first.HighCard() > second.HighCard())
        {
            if (second.HighCard() == A)
            {
                std::cout << second.GetTitle() << " wins!\n";
            }
            else
            {
                std::cout << first.GetTitle() << " wins!\n";
            }
        }
        else
        {
            if (first.HighCard() == A)
            {
                std::cout << first.GetTitle() << " wins!\n";
            }
            else
            {
                std::cout << second.GetTitle() << " wins!\n";
            }
        }
    }
}

void FindWinner(Hand first, Hand second)
{
    if (first.IsFlush() || second.IsFlush()) // There is a flush
    {
        if (first.IsFlush() && second.IsFlush()) // both our flushes
        {
            FindHigher(first, second);
        }
        else if (first.IsFlush())
        {
            std::cout << first.GetTitle() << " wins!\n"; // first is flush
        }
        else
        {
            std::cout << second.GetTitle() << " wins!\n"; // second is flush
        }
    }
    else if (first.IsStraight() || second.IsStraight()) // There is a straight
    {
        if (first.IsStraight() && second.IsStraight()) // both our straights
        {
            FindHigher(first, second);
        }
        else if (first.IsStraight())
        {
            std::cout << first.GetTitle() << " wins!\n"; // first is straight
        }
        else
        {
            std::cout << second.GetTitle() << " wins!\n"; // second is straight
        }
    }
    else if (first.HasPair() || second.HasPair())
    {
        if (first.HasPair() > second.HasPair())
        {
            std::cout << first.GetTitle() << " wins!\n";
        }
        else if (first.HasPair() < second.HasPair())
        {
            std::cout << second.GetTitle() << " wins!\n";
        }
        else
        {
            FindHigher(first, second);
        }
    }
    else
    {
        FindHigher(first, second);
    }
}

int main()
{
    Hand one(aceSpades, twoSpades, threeSpades);
    one.SetTitle("One");

    Hand two(twoHearts, threeClubs, fiveDiamonds);
    two.SetTitle("Two");

    FindWinner(one, two);
}
