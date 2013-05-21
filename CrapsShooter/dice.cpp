#include <iostream>
#include <cstdlib>
using namespace std;

class Dice
{
private:
    int die1;
    int die2;
    int diceSum;
public:
    void roll()
    {
        die1 = (rand() % 6) + 1;
        die2 = (rand() % 6) + 1;
        diceSum = die1 + die2;
    }
    int getDie1()
    {
        return die1;
    }
    int getDie2()
    {
        return die2;
    }
    int getDiceSum()
    {
        return diceSum;
    }
};
