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
    int odds;
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
            //pay come bets
            {
                if ((dice.getDiceSum() == 4) && (player1.getCome4() > 0))
                {
                    amountMade = (player1.getCome4() + (player1.getCome4Odds() * 2));
                    cout<<"You won $"<<amountMade<<" from your four come bet, and got your original bet back! "<<endl;
                    player1.setMoney(player1.getMoney() + (player1.getCome4() * 2) + (player1.getCome4Odds() * 3));
                    player1.setCome4(0);
                    player1.setCome4Odds(0);
                }
                if ((dice.getDiceSum() == 5) && (player1.getCome5() > 0))
                {
                    amountMade = (player1.getCome5() + ((player1.getCome5Odds() * 3) / 2));
                    cout<<"You won $"<<amountMade<<" from your five come bet, and got your original bet back! "<<endl;
                    player1.setMoney(player1.getMoney() + (player1.getCome5() * 2) + player1.getCome5Odds() + ((player1.getCome5Odds() * 3) / 2));
                    player1.setCome5(0);
                    player1.setCome5Odds(0);
                }
                if ((dice.getDiceSum() == 6) && (player1.getCome6() > 0))
                {
                    amountMade = (player1.getCome6() + ((player1.getCome6Odds() * 6) / 5));
                    cout<<"You won $"<<amountMade<<" from your six come bet, and got your original bet back! "<<endl;
                    player1.setMoney(player1.getMoney() + (player1.getCome6() * 2) + player1.getCome6Odds() + ((player1.getCome6Odds() * 6) / 5));
                    player1.setCome6(0);
                    player1.setCome6Odds(0);
                }
                if ((dice.getDiceSum() == 8) && (player1.getCome8() > 0))
                {
                    amountMade = (player1.getCome8() + ((player1.getCome8Odds() * 6) / 5));
                    cout<<"You won $"<<amountMade<<" from your eight come bet, and got your original bet back! "<<endl;
                    player1.setMoney(player1.getMoney() + (player1.getCome8() * 2) + player1.getCome8Odds() + ((player1.getCome8Odds() * 6) / 5));
                    player1.setCome8(0);
                    player1.setCome8Odds(0);
                }
                if ((dice.getDiceSum() == 9) && (player1.getCome9() > 0))
                {
                    amountMade = (player1.getCome9() + ((player1.getCome9Odds() * 3) / 2));
                    cout<<"You won $"<<amountMade<<" from your nine come bet, and got your original bet back! "<<endl;
                    player1.setMoney(player1.getMoney() + (player1.getCome9() * 2) + player1.getCome9Odds() + ((player1.getCome9Odds() * 3) / 2));
                    player1.setCome9(0);
                    player1.setCome9Odds(0);
                }
                if ((dice.getDiceSum() == 10) && (player1.getCome10() > 0))
                {
                    amountMade = (player1.getCome10() + ((player1.getCome10Odds() * 2)));
                    cout<<"You won $"<<amountMade<<" from your ten come bet, and got your original bet back! "<<endl;
                    player1.setMoney(player1.getMoney() + (player1.getCome10() * 2) + (player1.getCome10Odds() * 3));
                    player1.setCome10(0);
                    player1.setCome10Odds(0);
                }
            }
            //pay don't come bets
            if (dice.getDiceSum() == 7)
            {
                if (player1.getDontCome4() > 0)
                {
                    amountMade = (player1.getDontCome4() + (player1.getDontCome4Odds() / 2));
                    cout<<"You won "<<amountMade<<"from your Don't come bet that was on the Four, and got your original bet back! "<<endl;
                    player1.setMoney((player1.getMoney()) + (player1.getDontCome4() * 2) + (player1.getCome4Odds()) + (player1.getCome4Odds() / 2));
                    player1.setDontCome4(0);
                    player1.setDontCome4Odds(0);
                }
                if (player1.getDontCome5() > 0)
                {
                    amountMade = (player1.getDontCome5() + (player1.getDontCome5Odds() / 2));
                    cout<<"You won "<<amountMade<<"from your Don't come bet that was on the Five, and got your original bet back! "<<endl;
                    player1.setMoney((player1.getMoney()) + (player1.getDontCome5() * 2) + (player1.getCome5Odds()) + ((player1.getCome5Odds() * 2) / 3));
                    player1.setDontCome5(0);
                    player1.setDontCome5Odds(0);
                }
                if (player1.getDontCome6() > 0)
                {
                    amountMade = (player1.getDontCome6() + (player1.getDontCome6Odds() / 2));
                    cout<<"You won "<<amountMade<<"from your Don't come bet that was on the Six, and got your original bet back! "<<endl;
                    player1.setMoney((player1.getMoney()) + (player1.getDontCome6() * 2) + (player1.getCome6Odds()) + ((player1.getCome6Odds() * 5) / 6));
                    player1.setDontCome6(0);
                    player1.setDontCome6Odds(0);
                }
                if (player1.getDontCome8() > 0)
                {
                    amountMade = (player1.getDontCome8() + (player1.getDontCome8Odds() / 2));
                    cout<<"You won "<<amountMade<<"from your Don't come bet that was on the Eight, and got your original bet back! "<<endl;
                    player1.setMoney((player1.getMoney()) + (player1.getDontCome8() * 2) + (player1.getCome8Odds()) + ((player1.getCome6Odds() * 5) / 6));
                    player1.setDontCome8(0);
                    player1.setDontCome8Odds(0);
                }
                if (player1.getDontCome9() > 0)
                {
                    amountMade = (player1.getDontCome9() + (player1.getDontCome9Odds() / 2));
                    cout<<"You won "<<amountMade<<"from your Don't come bet that was on the Nine, and got your original bet back! "<<endl;
                    player1.setMoney((player1.getMoney()) + (player1.getDontCome9() * 2) + (player1.getCome9Odds()) + ((player1.getCome9Odds() * 2) / 3));
                    player1.setDontCome9(0);
                    player1.setDontCome9Odds(0);
                }
                if (player1.getDontCome10() > 0)
                {
                    amountMade = (player1.getDontCome10() + (player1.getDontCome10Odds() / 2));
                    cout<<"You won "<<amountMade<<"from your Don't come bet that was on the Ten, and got your original bet back! "<<endl;
                    player1.setMoney((player1.getMoney()) + (player1.getDontCome10() * 2) + (player1.getCome10Odds()) + (player1.getCome10Odds() / 2));
                    player1.setDontCome10(0);
                    player1.setDontCome10Odds(0);
                }
            }
            //take don't come bets
            {
                if ((dice.getDiceSum() == 4) && (player1.getDontCome4() > 0))
                {
                    player1.setDontCome4(0);
                    player1.setDontCome4Odds(0);
                    cout<<"You lost your Don't Come bet that was on the Four. "<<endl;
                }
                if ((dice.getDiceSum() == 5) && (player1.getDontCome5() > 0))
                {
                    player1.setDontCome5(0);
                    player1.setDontCome5Odds(0);
                    cout<<"You lost your Don't Come bet that was on the Five. "<<endl;
                }
                if ((dice.getDiceSum() == 6) && (player1.getDontCome6() > 0))
                {
                    player1.setDontCome6(0);
                    player1.setDontCome6Odds(0);
                    cout<<"You lost your Don't Come bet that was on the Six. "<<endl;
                }
                if ((dice.getDiceSum() == 8) && (player1.getDontCome8() > 0))
                {
                    player1.setDontCome8(0);
                    player1.setDontCome8Odds(0);
                    cout<<"You lost your Don't Come bet that was on the Eight. "<<endl;
                }
                if ((dice.getDiceSum() == 9) && (player1.getDontCome9() > 0))
                {
                    player1.setDontCome9(0);
                    player1.setDontCome9Odds(0);
                    cout<<"You lost your Don't Come bet that was on the Nine. "<<endl;
                }
                if ((dice.getDiceSum() == 10) && (player1.getDontCome10() > 0))
                {
                    player1.setDontCome10(0);
                    player1.setDontCome10Odds(0);
                    cout<<"You lost your Don't Come bet that was on the Ten. "<<endl;
                }
            }
            //if a point has not been established
            if (player1.getPoint() == 0)
            {
                //frontline winner
                if ((dice.getDiceSum() == 7) || dice.getDiceSum() == 11)
                {
                    if (player1.getPassLine() > 0)
                    {
                        cout<<"You won "<<player1.getPassLine()<<" from your Pass Line bet, and got your original bet back"<<endl;
                        player1.setMoney((player1.getPassLine() * 2) + player1.getMoney());
                        player1.setPassLine(0);
                    }
                    if (player1.getDontPass() > 0)
                    {
                        cout<<"You lost your Don't Pass Line bet "<<endl;
                        player1.setDontPass(0);
                    }
                }
                //crap is rolled
                if ((dice.getDiceSum() == 2) || (dice.getDiceSum() == 3) || (dice.getDiceSum() == 12))
                {
                    if (player1.getPassLine() > 0)
                    {
                        cout<<"You lost your pass line bet because a crap was rolled "<<endl;
                    }
                    player1.setPassLine(0);
                    if (player1.getDontPass() > 0)
                    {
                        if ((dice.getDiceSum() == 2) || (dice.getDiceSum() == 3))
                        {
                            amountMade = (player1.getDontPass());
                            cout<<"You won "<<amountMade<<" from your Don't Pass Line bet because a crap was rolled, and got your original bet back! "<<endl;
                            player1.setMoney(player1.getMoney() + (player1.getDontPass() * 2));
                            player1.setDontPass(0);
                        }
                        if (dice.getDiceSum() == 12)
                        {
                            amountMade = player1.getDontPass();
                            cout<<"Your Don't Pass Line pushed and you got your bet back."<<endl;
                            player1.setMoney(player1.getMoney() + player1.getDontPass());
                            player1.setDontPass(0);
                        }
                    }
                }
                //establish point, set odds if applicable
                if ((dice.getDiceSum() == 4) || (dice.getDiceSum() == 5) || (dice.getDiceSum() == 6) ||
                    (dice.getDiceSum() == 8) || (dice.getDiceSum() == 9) || (dice.getDiceSum() == 10))
                {
                    player1.setPoint(dice.getDiceSum());
                    cout<<"The point was set to "<<dice.getDiceSum()<<endl<<endl;
                    if (player1.getPassLine() > 0)
                    {
                        cout<<"Dealer: 'Do you want odds on your Pass Line bet?' "<<endl<<endl;
                        cout<<"Enter odds you want on your Pass Line bet, or enter 0 for none: ";
                        cin>>input;
                        cout<<endl;
                        while ((player1.getMoney() - input < 0) || (input < 0) || (input > (player1.getPassLine() * 5)))
                        {
                            cout<<"Invalid bet, try again! ";
                            cin>>input;
                            cout<<endl;
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
                    //if player has a don't pass line bet, ask for odds
                    if (player1.getDontPass() > 0)
                    {
                        cout<<"Dealer: 'Do you want odds on your Don't Pass Line bet? "<<endl;
                        cout<<"Enter odds you want on your Don't Pass Line bet, or enter 0 for none: ";
                        cin>>odds;
                        cout<<endl;
                        if ((player1.getPoint() == 4) || (player1.getPoint() == 10))
                        {
                            while ((player1.getMoney() - odds < 0) || (odds < 0) || (player1.getDontPass() * 10 < odds))
                            {
                                cout<<"Invalid odds, try again! ";
                                cin>>odds;
                                cout<<endl;
                            }
                        }
                        else if ((player1.getPoint() == 5) || (player1.getPoint() == 9))
                        {
                            while ((player1.getMoney() - odds < 0) || (odds < 0) || ((((player1.getDontPass() * 5) * 3) / 2) < odds))
                            {
                                cout<<"Invalid odds, try again! ";
                                cin>>odds;
                                cout<<endl;
                            }
                        }
                        else if ((player1.getPoint() == 6) || (player1.getPoint() == 8))
                        {
                            while ((player1.getMoney() - odds < 0) || (odds < 0) || ((((player1.getDontPass() * 5) * 6) / 5) < odds))
                            {
                                cout<<"Invalid odds, try again! ";
                                cin>>odds;
                                cout<<endl;
                            }
                        }
                        player1.setDontPassOdds(odds);
                        player1.setMoney(player1.getMoney() - player1.getDontPassOdds());
                    }
                }

            }
            //if a point has been established
            else if (player1.getPoint() != 0)
            {
                //if there is a don't pass line bet
                if (player1.getDontPass() > 0)
                {
                    if (dice.getDiceSum() == 7)
                    {
                        if ((player1.getPoint() == 4) || (player1.getPoint() == 10))
                        {
                            amountMade = (player1.getDontPass() + (player1.getDontPassOdds() / 2));
                            cout<<"You made $"<<amountMade<<" from your Don't Pass Line bet, and got your original bet back! "<<endl;
                            player1.setMoney(player1.getMoney() + (player1.getDontPass() * 2) + (player1.getDontPassOdds()) + (player1.getDontPassOdds() / 2));
                            player1.setDontPass(0);
                            player1.setDontPassOdds(0);
                        }
                        if ((player1.getPoint() == 5) || (player1.getPoint() == 9))
                        {
                            amountMade = (player1.getDontPass() + ((player1.getDontPassOdds() * 2 / 3)));
                            cout<<"You made $"<<amountMade<<" from your Don't Pass Line bet, and got your original bet back! "<<endl;
                            player1.setMoney(player1.getMoney() + (player1.getDontPass() * 2) + (player1.getDontPassOdds()) + ((player1.getDontPassOdds() * 2) / 3));
                            player1.setDontPass(0);
                            player1.setDontPassOdds(0);
                        }
                        if ((player1.getPoint() == 6) || (player1.getPoint() == 8))
                        {
                            amountMade = (player1.getDontPass() + ((player1.getDontPassOdds() * 5) / 6));
                            cout<<"You made $"<<amountMade<<" from your Don't Pass Line bet, and got your original bet back! "<<endl;
                            player1.setMoney(player1.getMoney() + (player1.getDontPass() * 2) + (player1.getDontPassOdds()) + ((player1.getDontPassOdds() * 5) / 6));
                            player1.setDontPass(0);
                            player1.setDontPassOdds(0);
                        }
                    }
                    if (dice.getDiceSum() == player1.getPoint())
                    {
                        player1.setDontPass(0);
                        player1.setDontPassOdds(0);
                        cout<<"You lost your Don't Pass Line bet and odds because the point was made! "<<endl<<endl;
                        system("pause");
                    }
                }
                //if there is a come bet on the table
                if (player1.getCome() > 0)
                {
                    if ((dice.getDiceSum() == 7) || (dice.getDiceSum() == 11))
                    {
                        amountMade = (player1.getCome());
                        cout<<"You won "<<amountMade<<" from your Come bet, and got your original Come bet back!"<<endl;
                        player1.setMoney(player1.getMoney() + (player1.getCome() * 2));
                        player1.setCome(0);
                    }
                    if ((dice.getDiceSum() == 2) || (dice.getDiceSum() == 3) || (dice.getDiceSum() == 12))
                    {
                        cout<<"You lost your Come bet because a crap was rolled. "<<endl;
                        player1.setCome(0);
                    }
                    {
                        if (dice.getDiceSum() == 4)
                        {
                            player1.setCome4(player1.getCome());
                            player1.setCome(0);
                            cout<<"Your Come bet was put on the four "<<endl;
                            if (player1.getPoint() != 4)
                            {
                                cout<<"Dealer: 'Do you want odds on your Come bet?' "<<endl<<endl;
                                cout<<"Enter the amount of odds you want on your Come bet, or '0' for none: ";
                                cin>>odds;
                                cout<<endl;
                                while ((odds < 0) || (player1.getMoney() - odds < 0) || (odds > player1.getCome4() * 5))
                                {
                                    cout<<"Invalid odds, try again! ";
                                    cin>>odds;
                                    cout<<endl;
                                }
                                player1.setCome4Odds(odds);
                                player1.setMoney(player1.getMoney() - player1.getCome4Odds());
                            }
                        }
                        if (dice.getDiceSum() == 5)
                        {
                            player1.setCome5(player1.getCome());
                            player1.setCome(0);
                            cout<<"Your Come bet was put on the five "<<endl;
                            if (player1.getPoint() != 5)
                            {
                                cout<<"Dealer: 'Do you want odds on your Come bet?' "<<endl<<endl;
                                cout<<"Enter the amount of odds you want on your Come bet, or '0' for none: ";
                                cin>>odds;
                                cout<<endl;
                                while ((odds < 0) || (player1.getMoney() - odds < 0) || (odds > player1.getCome5() * 5))
                                {
                                    cout<<"Invalid odds, try again! ";
                                    cin>>odds;
                                    cout<<endl;
                                }
                                player1.setCome5Odds(odds);
                                player1.setMoney(player1.getMoney() - player1.getCome5Odds());
                            }
                        }
                        if (dice.getDiceSum() == 6)
                        {
                            player1.setCome6(player1.getCome());
                            player1.setCome(0);
                            cout<<"Your Come bet was put on the six "<<endl;
                            if (player1.getPoint() != 6)
                            {
                                cout<<"Dealer: 'Do you want odds on your Come bet?' "<<endl<<endl;
                                cout<<"Enter the amount of odds you want on your Come bet, or '0' for none: ";
                                cin>>odds;
                                cout<<endl;
                                while ((odds < 0) || (player1.getMoney() - odds < 0) || (odds > player1.getCome6() * 5))
                                {
                                    cout<<"Invalid odds, try again! ";
                                    cin>>odds;
                                    cout<<endl;
                                }
                                player1.setCome6Odds(odds);
                                player1.setMoney(player1.getMoney() - player1.getCome6Odds());
                            }
                        }
                        if (dice.getDiceSum() == 8)
                        {
                            player1.setCome8(player1.getCome());
                            player1.setCome(0);
                            cout<<"Your Come bet was put on the eight "<<endl;
                            if (player1.getPoint() != 8)
                            {
                                cout<<"Dealer: 'Do you want odds on your Come bet?' "<<endl<<endl;
                                cout<<"Enter the amount of odds you want on your Come bet, or '0' for none: ";
                                cin>>odds;
                                cout<<endl;
                                while ((odds < 0) || (player1.getMoney() - odds < 0) || (odds > player1.getCome8() * 5))
                                {
                                    cout<<"Invalid odds, try again! ";
                                    cin>>odds;
                                    cout<<endl;
                                }
                                player1.setCome8Odds(odds);
                                player1.setMoney(player1.getMoney() - player1.getCome8Odds());
                            }
                        }
                        if (dice.getDiceSum() == 9)
                        {
                            player1.setCome9(player1.getCome());
                            player1.setCome(0);
                            cout<<"Your Come bet was put on the nine "<<endl;
                            if (player1.getPoint() != 9)
                            {
                                cout<<"Dealer: 'Do you want odds on your Come bet?' "<<endl<<endl;
                                cout<<"Enter the amount of odds you want on your Come bet, or '0' for none: ";
                                cin>>odds;
                                cout<<endl;
                                while ((odds < 0) || (player1.getMoney() - odds < 0) || (odds > player1.getCome9() * 5))
                                {
                                    cout<<"Invalid odds, try again! ";
                                    cin>>odds;
                                    cout<<endl;
                                }
                                player1.setCome9Odds(odds);
                                player1.setMoney(player1.getMoney() - player1.getCome9Odds());
                            }
                        }
                        if (dice.getDiceSum() == 10)
                        {
                            player1.setCome10(player1.getCome());
                            player1.setCome(0);
                            cout<<"Your Come bet was put on the 10 "<<endl;
                            if (player1.getPoint() != 10)
                            {
                                cout<<"Dealer: 'Do you want odds on your Come bet?' "<<endl<<endl;
                                cout<<"Enter the amount of odds you want on your Come bet, or '0' for none: ";
                                cin>>odds;
                                cout<<endl;
                                while ((odds < 0) || (player1.getMoney() - odds < 0) || (odds > player1.getCome10() * 5))
                                {
                                    cout<<"Invalid odds, try again! ";
                                    cin>>odds;
                                    cout<<endl;
                                }
                                player1.setCome10Odds(odds);
                                player1.setMoney(player1.getMoney() - player1.getCome10Odds());
                            }
                        }
                    }
                }
                //if there is a don't come bet on the table
                if (player1.getDontCome() > 0)
                {
                    if ((dice.getDiceSum() == 2) || (dice.getDiceSum() == 3))
                    {
                        amountMade = (player1.getDontCome());
                        cout<<"You won "<<amountMade<<" from your Don't Come bet, and got your original Don't Come bet back!"<<endl;
                        player1.setMoney(player1.getMoney() + (player1.getDontCome() * 2));
                        player1.setDontCome(0);
                    }
                    if ((dice.getDiceSum() == 7) || (dice.getDiceSum() == 11))
                    {
                        cout<<"You lost your Don't Come bet. "<<endl;
                        player1.setDontCome(0);
                    }
                    if (dice.getDiceSum() == 12)
                    {
                        cout<<"Your Don't Come bet pushed because a twelve was rolled."<<endl;
                    }
                    if (dice.getDiceSum() == 4)
                    {
                        player1.setDontCome4(player1.getDontCome());
                        player1.setDontCome(0);
                        cout<<"Your Don't Come bet was put on the Four"<<endl;
                        cout<<"Dealer: 'Do you want odds on your Don't Come bet?' "<<endl<<endl;
                        cout<<"Enter the amount of odds you want to lay on your Don't Come bet, or '0' for none: ";
                        cin>>odds;
                        cout<<endl;
                        while ((odds < 0) || (player1.getMoney() - odds < 0) || (odds > player1.getDontCome4() * 10))
                        {
                            cout<<"Invalid odds, try again! ";
                            cout<<"test 10 "<<player1.getDontCome4()*10<<endl;
                            cin>>odds;
                            cout<<endl;
                        }
                        player1.setDontCome4Odds(odds);
                        player1.setMoney(player1.getMoney() - player1.getDontCome4Odds());
                    }
                    if (dice.getDiceSum() == 5)
                    {
                        player1.setDontCome5(player1.getDontCome());
                        player1.setDontCome(0);
                        cout<<"Your Don't Come bet was put on the Five"<<endl;
                        cout<<"Dealer: 'Do you want odds on your Don't Come bet?' "<<endl<<endl;
                        cout<<"Enter the amount of odds you want to lay on your Don't Come bet, or '0' for none: ";
                        cin>>odds;
                        cout<<endl;
                        while ((odds < 0) || (player1.getMoney() - odds < 0) || (((odds > player1.getDontCome5() * 5) * 3) / 2))
                        {
                            cout<<"Invalid odds, try again! ";
                            cout<<"test 5 "<<player1.getDontCome5()*5*3/2<<endl;
                            cin>>odds;
                            cout<<endl;
                        }
                        player1.setDontCome5Odds(odds);
                        player1.setMoney(player1.getMoney() - player1.getDontCome5Odds());
                    }
                    if (dice.getDiceSum() == 6)
                    {
                        player1.setDontCome6(player1.getDontCome());
                        player1.setDontCome(0);
                        cout<<"Your Don't Come bet was put on the Six"<<endl;
                        cout<<"Dealer: 'Do you want odds on your Don't Come bet?' "<<endl<<endl;
                        cout<<"Enter the amount of odds you want to lay on your Don't Come bet, or '0' for none: ";
                        cin>>odds;
                        cout<<endl;
                        while ((odds < 0) || (player1.getMoney() - odds < 0) || (((odds > player1.getDontCome6() * 5) * 6) / 5))
                        {
                            cout<<"Invalid odds, try again! ";
                            cout<<"test 6 "<<player1.getDontCome6()*5*6/5<<endl;
                            cin>>odds;
                            cout<<endl;
                        }
                        player1.setDontCome6Odds(odds);
                        player1.setMoney(player1.getMoney() - player1.getDontCome6Odds());
                    }
                    if (dice.getDiceSum() == 8)
                    {
                        player1.setDontCome8(player1.getDontCome());
                        player1.setDontCome(0);
                        cout<<"Your Don't Come bet was put on the Eight"<<endl;
                        cout<<"Dealer: 'Do you want odds on your Don't Come bet?' "<<endl<<endl;
                        cout<<"Enter the amount of odds you want to lay on your Don't Come bet, or '0' for none: ";
                        cin>>odds;
                        cout<<endl;
                        while ((odds < 0) || (player1.getMoney() - odds < 0) || (((odds > player1.getDontCome8() * 5) * 6) / 5))
                        {
                            cout<<"Invalid odds, try again! ";

                            cout<<"test 8 "<<player1.getDontCome8()*5*6/5<<endl;
                            cin>>odds;
                            cout<<endl;
                        }
                        player1.setDontCome8Odds(odds);
                        player1.setMoney(player1.getMoney() - player1.getDontCome8Odds());
                    }
                    if (dice.getDiceSum() == 9)
                    {
                        player1.setDontCome9(player1.getDontCome());
                        player1.setDontCome(0);
                        cout<<"Your Don't Come bet was put on the Nine"<<endl;
                        cout<<"Dealer: 'Do you want odds on your Don't Come bet?' "<<endl<<endl;
                        cout<<"Enter the amount of odds you want to lay on your Don't Come bet, or '0' for none: ";
                        cin>>odds;
                        cout<<endl;
                        while ((odds < 0) || (player1.getMoney() - odds < 0) || (((odds > player1.getDontCome9() * 5) * 3) / 2))
                        {
                            cout<<"Invalid odds, try again! ";
                            cout<<"test 9 "<<player1.getDontCome9()*5*3/2<<endl;
                            cin>>odds;
                            cout<<endl;
                        }
                        player1.setDontCome9Odds(odds);
                        player1.setMoney(player1.getMoney() - player1.getDontCome9Odds());
                    }
                    if (dice.getDiceSum() == 10)
                    {
                        player1.setDontCome10(player1.getDontCome());
                        player1.setDontCome(0);
                        cout<<"Your Don't Come bet was put on the Ten"<<endl;
                        cout<<"Dealer: 'Do you want odds on your Don't Come bet?' "<<endl<<endl;
                        cout<<"Enter the amount of odds you want to lay on your Don't Come bet, or '0' for none: ";
                        cin>>odds;
                        cout<<endl;
                        while ((odds < 0) || (player1.getMoney() - odds < 0) || (odds > player1.getDontCome10() * 10))
                        {
                            cout<<"Invalid odds, try again! ";
                            cout<<"test 10 "<<player1.getDontCome10()*10<<endl;
                            cin>>odds;
                            cout<<endl;
                        }
                        player1.setDontCome10Odds(odds);
                        player1.setMoney(player1.getMoney() - player1.getDontCome10Odds());
                    }
                }
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
                    //set point to 0 and turn off come bet odds
                    player1.setPoint (0);
                    player1.setMoney(player1.getMoney() + player1.getCome4Odds() + player1.getCome5Odds() + player1.getCome6Odds() +
                         player1.getCome8Odds() + player1.getCome9Odds() + player1.getCome10Odds());
                    player1.setCome4Odds(0);
                    player1.setCome5Odds(0);
                    player1.setCome6Odds(0);
                    player1.setCome8Odds(0);
                    player1.setCome9Odds(0);
                    player1.setCome10Odds(0);
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
                //place bets
                {
                    if ((dice.getDiceSum() == 4) && (player1.getPlace4() > 0))
                    {
                        amountMade = ((player1.getPlace4() / 5) * 9);
                        player1.setMoney(player1.getMoney() + ((player1.getPlace4() / 5) * 9));
                        cout<<"Dealer: 'Your Place bet made you $"<<amountMade<<"!"<<endl;
                        amountMade = 0;
                    }
                    if ((dice.getDiceSum() == 5) && (player1.getPlace5() > 0))
                    {
                        amountMade = ((player1.getPlace5() / 5) * 7);
                        player1.setMoney(player1.getMoney() + ((player1.getPlace5() / 5) * 7));
                        cout<<"Dealer: 'Your Place bet made you $"<<amountMade<<"!"<<endl;
                        amountMade = 0;
                    }
                    if ((dice.getDiceSum() == 6) && (player1.getPlace6() > 0))
                    {
                        amountMade = ((player1.getPlace6() / 6) * 7);
                        player1.setMoney(player1.getMoney() + ((player1.getPlace6() / 5) * 7));
                        cout<<"Dealer: 'Your Place bet made you $"<<amountMade<<"!"<<endl;
                        amountMade = 0;
                    }
                    if ((dice.getDiceSum() == 8) && (player1.getPlace8() > 0))
                    {
                        amountMade = ((player1.getPlace8() / 6) * 7);
                        player1.setMoney(player1.getMoney() + ((player1.getPlace8() / 6) * 7));
                        cout<<"Dealer: 'Your Place bet made you $"<<amountMade<<"!"<<endl;
                        amountMade = 0;
                    }
                    if ((dice.getDiceSum() == 9) && (player1.getPlace9() > 0))
                    {
                        amountMade = ((player1.getPlace9() / 5) * 7);
                        player1.setMoney(player1.getMoney() + ((player1.getPlace9() / 5) * 7));
                        cout<<"Dealer: 'Your Place bet made you $"<<amountMade<<"!"<<endl;
                        amountMade = 0;
                    }
                    if ((dice.getDiceSum() == 10) && (player1.getPlace10() > 0))
                    {
                        amountMade = ((player1.getPlace10() / 5) * 9);
                        player1.setMoney(player1.getMoney() + ((player1.getPlace10() / 5) * 9));
                        cout<<"Dealer: 'Your Place bet made you $"<<amountMade<<"!"<<endl;
                        amountMade = 0;
                    }
                }
            }
            //if player has a field bet, determine if it's a winner
            if (player1.getField() > 0)
            {
                if ((dice.getDiceSum() == 2) || (dice.getDiceSum() == 3) || (dice.getDiceSum() == 4) || (dice.getDiceSum() == 9) ||
                    (dice.getDiceSum() == 10) || (dice.getDiceSum() == 11) || (dice.getDiceSum() == 12))
                {
                    if ((dice.getDiceSum() == 2) || (dice.getDiceSum() == 12))
                    {
                        amountMade = (player1.getField() * 2);
                        cout<<"You won "<<amountMade<<" from your Field bet, and got your original bet back!"<<endl<<endl;
                        player1.setMoney(player1.getMoney() + (player1.getField() * 3));
                        player1.setField(0);
                    }
                    else
                    {
                        amountMade = (player1.getField());
                        cout<<"You won "<<amountMade<<" from your Field bet, and got your original bet back!"<<endl<<endl;
                        player1.setMoney(player1.getMoney() + (player1.getField() * 2));
                        player1.setField(0);
                    }
                }
                if ((dice.getDiceSum() == 5) || (dice.getDiceSum() == 6) || (dice.getDiceSum() == 7) || (dice.getDiceSum() == 8))
                {
                    cout<<"You lost your Field bet. "<<endl<<endl;
                    player1.setField(0);
                }
            }
            //take the come bets on a 7
            if (dice.getDiceSum() == 7)
            {
                player1.setCome4(0);
                player1.setCome5(0);
                player1.setCome6(0);
                player1.setCome8(0);
                player1.setCome9(0);
                player1.setCome10(0);
                player1.setCome4Odds(0);
                player1.setCome5Odds(0);
                player1.setCome6Odds(0);
                player1.setCome8Odds(0);
                player1.setCome9Odds(0);
                player1.setCome10Odds(0);
            }
            system("pause");
            system("CLS");
        }
    }
};
