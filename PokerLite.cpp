#include <iostream>
#include "Card.cpp"
#include "Hand.cpp"

int main()
{
    Card A_Spades(A, Card::Spades);
    std::cout << "Hello World!\n" << A_Spades.GetValue() << A_Spades.GetSuit();
}