#include <iostream>
#include <cstdlib>
#include <ctime>
#include "interface.h"
#include "player.h"
#include "dice.cpp"

using namespace std;
class Game
{
private:
    int input;
    int amountMade;
public:
    void play()
    {
        //seed for random numbers
        srand(time(NULL));
        //create objects
        Interface interface;
        Player player1;
        Dice dice;
        //print intro screen
        interface.initialize();
        //initialize player starting money
        player1.buyIn();
        system("CLS");
        while (true)
        {
            interface.printAbove(player1);

            player1.setInput(10);
            interface.printBelow(player1);
            while ((player1.getInput() != 0))
            {
                player1.makeBets();
                system("CLS");
                interface.printAbove(player1);
                interface.printBelow(player1);
            }
            dice.roll();
            interface.rollResult(dice.getDie1(), dice.getDie2(), player1.getPoint());
            //if a point has not been established
            if (player1.getPoint() == 0)
            {
                //frontline winner
                if ((dice.getDiceSum() == 7) || dice.getDiceSum() == 11)
                {
                    player1.setMoney((player1.getPassLine() * 2) + player1.getMoney());
                    player1.setPassLine(0);
                }
                //crap
                if ((dice.getDiceSum() == 2) || (dice.getDiceSum() == 3) || (dice.getDiceSum() == 12))
                {
                    player1.setPassLine(0);
                }
                //establish point
                if ((dice.getDiceSum() == 4) || (dice.getDiceSum() == 5) || (dice.getDiceSum() == 6) ||
                    (dice.getDiceSum() == 8) || (dice.getDiceSum() == 9) || (dice.getDiceSum() == 10))
                {
                    player1.setPoint(dice.getDiceSum());
                    if (player1.getPassLine() > 0)
                    {
                        cout<<"Dealer: 'Do you want odds on your pass line bet?' "<<endl;
                        cout<<"Enter odds you want on your pass line bet, or enter 0 for none: "<<endl;
                        cin>>input;
                        while (player1.getMoney() - input < 0)
                        {
                            cout<<"You don't have enough money! Try again! "<<endl;
                            cin>>input;
                            while ((input < 0) || (input > (player1.getPassLine() * 5)))
                            {
                                cout<<"Invalid Odds, try again!"<<endl;
                                cin>>input;
                            }
                        }
                        while ((input < 0) || (input > (player1.getPassLine() * 5)))
                        {
                            cout<<"Invalid Odds, try again!"<<endl;
                            cin>>input;
                            while (player1.getMoney() - input <= 0)
                            {
                                cout<<"You don't have enough money! Try again! "<<endl;
                                cin>>input;
                            }
                        }
                        player1.setPassLineOdds(input);
                        player1.setMoney(player1.getMoney() - player1.getPassLineOdds());
                        input = 0;
                        //if the point is the same as the player's place bet and they have a pass line bet,
                        //remove the place bet and give the player their money back.
                        if (((player1.getPlace4() > 0) && (player1.getPoint() == 4)) || ((player1.getPlace5() > 0) && (player1.getPoint() == 5)) ||
                        ((player1.getPlace6() > 0) && (player1.getPoint() == 6)) || ((player1.getPlace8() > 0) && (player1.getPoint() == 8)) ||
                        ((player1.getPlace9() > 0) && (player1.getPoint() == 9)) || ((player1.getPlace10() > 0) && (player1.getPoint() == 10)))
                        {
                            if ((player1.getPlace4() > 0) && (player1.getPoint() == 4))
                            {
                                player1.setMoney(player1.getMoney() + player1.getPlace4());
                                player1.setPlace4(0);
                            }
                            if ((player1.getPlace5() > 0) && (player1.getPoint() == 5))
                            {
                                player1.setMoney(player1.getMoney() + player1.getPlace5());
                                player1.setPlace5(0);
                            }
                            if ((player1.getPlace6() > 0) && (player1.getPoint() == 6))
                            {
                                player1.setMoney(player1.getMoney() + player1.getPlace6());
                                player1.setPlace6(0);
                            }
                            if ((player1.getPlace8() > 0) && (player1.getPoint() == 8))
                            {
                                player1.setMoney(player1.getMoney() + player1.getPlace8());
                                player1.setPlace8(0);
                            }
                            if ((player1.getPlace9() > 0) && (player1.getPoint() == 9))
                            {
                                player1.setMoney(player1.getMoney() + player1.getPlace9());
                                player1.setPlace9(0);
                            }
                            if ((player1.getPlace10() > 0) && (player1.getPoint() == 10))
                            {
                                player1.setMoney(player1.getMoney() + player1.getPlace10());
                                player1.setPlace10(0);
                            }
                        }
                    }
                }
            }
            //if a point has been established
            else if (player1.getPoint() != 0)
            {
                //lose
                if (dice.getDiceSum() == 7)
                {
                    player1.setPoint(0);
                    player1.setPassLine(0);
                    player1.setPassLineOdds(0);
                    player1.setPlace4(0);
                    player1.setPlace5(0);
                    player1.setPlace6(0);
                    player1.setPlace8(0);
                    player1.setPlace9(0);
                    player1.setPlace10(0);

                }
                //win
                if (dice.getDiceSum() == player1.getPoint())
                {
                    player1.setPoint (0);
                    if ((dice.getDiceSum() == 4) || (dice.getDiceSum() == 10))
                    {
                        player1.setMoney((player1.getPassLine() * 2) + ((player1.getPassLineOdds() * 2) + player1.getPassLineOdds()) + (player1.getMoney()));

                    }
                    if ((dice.getDiceSum() == 5) || (dice.getDiceSum() == 9))
                    {
                        player1.setMoney((player1.getPassLine() * 2) + (((player1.getPassLineOdds() * 3) / 2) + player1.getPassLineOdds()) + (player1.getMoney()));
                    }
                    if ((dice.getDiceSum() == 6) || (dice.getDiceSum() == 8))
                    {
                        player1.setMoney((player1.getPassLine() * 2) + (((player1.getPassLineOdds() * 6) / 5) + player1.getPassLineOdds()) + (player1.getMoney()));
                    }
                    player1.setPassLine(0);
                    player1.setPassLineOdds(0);
                    cout<<"Stickman: 'Winner!'" <<endl;
                }
                if ((dice.getDiceSum() == 4) && (player1.getPlace4() > 0))
                {
                    amountMade = ((player1.getPlace4() / 5) * 9);
                    player1.setMoney(player1.getMoney() + ((player1.getPlace4() / 5) * 9));
                    cout<<"Dealer: 'Your place bet made you $"<<amountMade<<"!"<<endl;
                    amountMade = 0;
                }
                if ((dice.getDiceSum() == 5) && (player1.getPlace5() > 0))
                {
                    amountMade = ((player1.getPlace5() / 5) * 7);
                    player1.setMoney(player1.getMoney() + ((player1.getPlace5() / 5) * 7));
                    cout<<"Dealer: 'Your place bet made you $"<<amountMade<<"!"<<endl;
                    amountMade = 0;
                }
                if ((dice.getDiceSum() == 6) && (player1.getPlace6() > 0))
                {
                    amountMade = ((player1.getPlace6() / 6) * 7);
                    player1.setMoney(player1.getMoney() + ((player1.getPlace6() / 5) * 7));
                    cout<<"Dealer: 'Your place bet made you $"<<amountMade<<"!"<<endl;
                    amountMade = 0;
                }
                if ((dice.getDiceSum() == 8) && (player1.getPlace8() > 0))
                {
                    amountMade = ((player1.getPlace8() / 6) * 7);
                    player1.setMoney(player1.getMoney() + ((player1.getPlace8() / 6) * 7));
                    cout<<"Dealer: 'Your place bet made you $"<<amountMade<<"!"<<endl;
                    amountMade = 0;
                }
                if ((dice.getDiceSum() == 9) && (player1.getPlace9() > 0))
                {
                    amountMade = ((player1.getPlace9() / 5) * 7);
                    player1.setMoney(player1.getMoney() + ((player1.getPlace9() / 5) * 7));
                    cout<<"Dealer: 'Your place bet made you $"<<amountMade<<"!"<<endl;
                    amountMade = 0;
                }
                if ((dice.getDiceSum() == 10) && (player1.getPlace10() > 0))
                {
                    amountMade = ((player1.getPlace4() / 5) * 9);
                    player1.setMoney(player1.getMoney() + ((player1.getPlace10() / 5) * 9));
                    cout<<"Dealer: 'Your place bet made you $"<<amountMade<<"!"<<endl;
                    amountMade = 0;
                }
            }
            if (player1.getField() > 0)
            {
                if ((dice.getDiceSum() == 2) || (dice.getDiceSum() == 3) || (dice.getDiceSum() == 4) || (dice.getDiceSum() == 9) ||
                    (dice.getDiceSum() == 10) || (dice.getDiceSum() == 11) || (dice.getDiceSum() == 12))
                {
                    if ((dice.getDiceSum() == 2) || (dice.getDiceSum() == 12))
                    {
                        player1.setMoney(player1.getMoney() + (player1.getField() * 3));
                        player1.setField(0);
                    }
                    else
                    {
                        player1.setMoney(player1.getMoney() + (player1.getField() * 2));
                        player1.setField(0);
                    }
                }
                if ((dice.getDiceSum() == 5) || (dice.getDiceSum() == 6) || (dice.getDiceSum() == 7) || (dice.getDiceSum() == 8))
                {
                    player1.setField(0);
                }
            }
            system("pause");
            system("CLS");
        }
    }
};
