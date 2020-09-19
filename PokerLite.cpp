#include <iostream>
#include "Card.cpp"
#include "Hand.cpp"

int main()
{
    Card aceSpades(A, Card::Spades);
    Card twoSpades(2, Card::Spades);
    Card threeSpades(3, Card::Spades);
    Hand one(aceSpades, twoSpades, threeSpades);
    one.Print("Hand One");
}
