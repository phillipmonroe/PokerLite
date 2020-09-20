#include <iostream>
#include "Card.cpp"
#include "Hand.cpp"
#include "Deck.cpp"

/**
* This is the main file for the PokerLite Program.
* 
* The rules for PokerLite are as follows:
* A Standard deck is used, but only the ranks Ace and
* 2 through 9. The four suits (hearts, diamonds,
* spades, and clubs) are all used.
* 
* A hand of a higher ranking type on the list beats 
* one that is lower on the list.
* If two hands have the same ranking, the winning hand 
* will have the highest ranked card. In the case of
* pairs, the rank of the pair determines the winner.
* Ties are possible.
* Hand rankings in order of highest to lowest.
*   - Flush: three cards of the same suit. Highest rank
*     card wins ties.
*   - Straight: three cards in sequential order but of
*     different suits. E.g. 3H, 4C,5H.
*   - Pair: two cards of the same rank; the remaining
*     card doesn't matter.
*   - High Card: rank of highest card.
*
* Rules courtesy of Visual Purple.
* 
* @author Phillip Monroe
*/

/**
* Finds which hand has the higher high card.
* 
* @param first, second 
*   hand to compare
*/
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
            if (second.HighCard() == A) // check for Ace because it is stored as 1 internally
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
            if (first.HighCard() == A) // check for Ace because it is stored as 1 internally
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

/**
* Finds which hand wins.
*
* @param first, second
*   hand to compare
*/
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
        if (first.HasPair() && second.HasPair()) 
        {
            if (first.HasPair() > second.HasPair())
            {
                if (second.HasPair() == A)
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
                if (first.HasPair() == A)
                {
                    std::cout << first.GetTitle() << " wins!\n";
                }
                else
                {
                    std::cout << second.GetTitle() << " wins!\n";
                }
            }
        }
        else if (first.HasPair())
        {
            std::cout << first.GetTitle() << " wins!\n";
        }
        else
        {
            std::cout << second.GetTitle() << " wins!\n";
        }
    }
    else
    {
        FindHigher(first, second);
    }
}

int main()
{
    Hand highFlush(aceSpades, nineSpades, eightSpades);
    Hand lowFlush(twoDiamonds, fiveDiamonds, sevenDiamonds);
    Hand highStraight(eightDiamonds, nineClubs, sevenHearts);
    Hand lowStraight(fourSpades, fiveSpades, threeDiamonds);
    Hand highPair(aceHearts, aceClubs, fourHearts);
    Hand lowPair(twoSpades, aceDiamonds, twoClubs);
    Hand highCard(threeSpades, nineHearts, eightHearts);
    Hand lowCard1(twoHearts, threeClubs, fiveHearts);
    Hand lowCard2(fiveClubs, threeHearts, twoClubs);

    std::cout << "All hands that will be used:\n";
    highFlush.Print("High Flush");
    lowFlush.Print("Low Flush");
    highStraight.Print("High Straight");
    lowStraight.Print("Low Straight");
    highPair.Print("High Pair");
    lowPair.Print("Low Pair");
    highCard.Print("High Card");
    lowCard1.Print("Low Card 1");
    lowCard2.Print("Low Card 2");
    std::cout << "\n\n";

    std::cout << highFlush.GetTitle() << " vs. " << lowFlush.GetTitle() << "\n";
    FindWinner(highFlush, lowFlush);                // Expected Winner: High Flush
    std::cout << "\n";

    std::cout << highFlush.GetTitle() << " vs. " << highStraight.GetTitle() << "\n";
    FindWinner(highFlush, highStraight);            // Expected Winner: High Flush
    std::cout << "\n";

    std::cout << highFlush.GetTitle() << " vs. " << highPair.GetTitle() << "\n";
    FindWinner(highFlush, highPair);                // Expected Winner: High Flush
    std::cout << "\n";

    std::cout << highFlush.GetTitle() << " vs. " << highCard.GetTitle() << "\n";
    FindWinner(highFlush, highCard);                // Expected Winner: High Flush
    std::cout << "\n";

    std::cout << highStraight.GetTitle() << " vs. " << lowFlush.GetTitle() << "\n";
    FindWinner(highStraight, lowFlush);             // Expected Winner: Low Flush
    std::cout << "\n";

    std::cout << highStraight.GetTitle() << " vs. " << lowStraight.GetTitle() << "\n";
    FindWinner(highStraight, lowStraight);          // Expected Winner: High Straight
    std::cout << "\n";

    std::cout << highStraight.GetTitle() << " vs. " << highPair.GetTitle() << "\n";
    FindWinner(highStraight, highPair);             // Expected Winner: High Straight
    std::cout << "\n";

    std::cout << highStraight.GetTitle() << " vs. " << highCard.GetTitle() << "\n";
    FindWinner(highStraight, highCard);             // Expected Winner: High Straight
    std::cout << "\n";

    std::cout << highPair.GetTitle() << " vs. " << lowStraight.GetTitle() << "\n";
    FindWinner(highPair, lowStraight);              // Expected Winner: Low Straight
    std::cout << "\n";

    std::cout << highPair.GetTitle() << " vs. " << lowPair.GetTitle() << "\n";
    FindWinner(highPair, lowPair);                  // Expected Winner: High Pair
    std::cout << "\n";

    std::cout << highPair.GetTitle() << " vs. " << highCard.GetTitle() << "\n";
    FindWinner(highPair, highCard);                 // Expected Winner: High Pair
    std::cout << "\n";

    std::cout << highCard.GetTitle() << " vs. " << lowPair.GetTitle() << "\n";
    FindWinner(highCard, lowPair);                  // Expected Winner: Low Pair
    std::cout << "\n";

    std::cout << highCard.GetTitle() << " vs. " << lowCard1.GetTitle() << "\n";
    FindWinner(highCard, lowCard1);                  // Expected Winner: High Card
    std::cout << "\n";

    std::cout << lowCard1.GetTitle() << " vs. " << lowCard2.GetTitle() << "\n";
    FindWinner(lowCard1, lowCard2);                  // Expected Winner: Tie
    std::cout << "\n";
}
