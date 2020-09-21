# PokerLite
**Author**: Phillip Monroe

## Download
A compile .exe can be found on my [GitHub](https://github.com/phillipmonroe/PokerLite/releases)

## Summary/Rules
The game of Pokerlite is just like Poker, but with some parts removed. It uses a
standard card deck, but only the ranks of Aces, and 2 through 9s, of all four
suits: hearts, diamonds, spades and clubs. Each player's hand consists of 3 cards.
Aces are high, but in the case of straights can also be low.

**Hand rankings:**
A hand of a higher ranking type on the list beats one that is lower on the list.

If two hands have the same ranking, the winning hand will have the highest ranked
card. In the case of pairs, the rank of the pair determines the winner.

*Ties are possible.*

Hand rankings in order of highest to lowest.
- **Flush**: three cards of the same suit. Highest rank card wins ties.
- **Straight**: three cards in sequential order but of different suits. E.g. 3H,
  4C,5H.
- **Pair**: two cards of the same rank; the remaining card doesn't matter.
- **High Card**: rank of highest card.

## Approach
I began this programming test by creating a class that represents a card. This
involved storing the suit and value of the card and adding functions surrounding
them. Next I added a class to represent a group of cards called a hand. After I
added all of the functions to store the cards and create a hand, I began to add
functions to find the rank of the hand inside of the Hand Class. These functions
included HighCard which finds the highest card in the hand. I then added functions
to check if the hand is a straight or a flush. After that I added a function to
check if the hand has a pair. Then I added functions to print the cards and the
hands. The next step was comparing two hands to find the winner. I approached this
by checking for hands in order of ranking shown above. I created a method to find
which hand has the higher card in the case of two matching rank hands (excluding
pairs). Finally I began testing. I added a deck class that contains all possible
cards in PokerLite to increase the readability of my main file. I then added tests
that cover every scenario without being overwhelming.

*My approach can also be seen through the commit history on my **[GitHub](https://github.com/phillipmonroe/PokerLite)**.*

## Sources
- Rules for PokerLite courtesy of Visual Purple
