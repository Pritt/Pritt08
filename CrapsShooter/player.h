#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "integerTest.cpp"
#include "interface.h"
using namespace std;

class Player
{
private:
    int money;
    int startingMoney;

    int point;
    int input;

    int passLine, passLineOdds;
    int place4, place5, place6, place8, place9, place10;
    int come, comeOption, comeOption2; //while it's on the table, waiting for a point to be established
    int come4, come5, come6, come8, come9, come10; //point has been established
    int come4Odds, come5Odds, come6Odds, come8Odds, come9Odds, come10Odds;
    int field;
    int dontPass, dontPassOdds, dontPassOption;
    int newDontCome;
    int dontCome, dontComeOption, dontComeOption2; //while its on the table, waiting for a point to be established
    int dontCome4, dontCome5, dontCome6, dontCome8, dontCome9, dontCome10; //point has been established
    int dontCome4Odds, dontCome5Odds, dontCome6Odds, dontCome8Odds, dontCome9Odds, dontCome10Odds;

    //center action
    int hard4, hard6, hard8, hard10;
    //one roll bets
    int two, three, eleven, twelve, hiLo, anyCraps, CE, any7;

    bool invalidInput;
public:
    //construct all bets and other stuff to 0
    Player()
    {
        point = 0;
        passLine = 0;
        passLineOdds = 0;
        place4 = 0;
        place5 = 0;
        place6 = 0;
        place8 = 0;
        place9 = 0;
        place10 = 0;
        come = 0;
        come4 = 0;
        come5 = 0;
        come6 = 0;
        come8 = 0;
        come9 = 0;
        come10 = 0;
        come4Odds = 0;
        come5Odds = 0;
        come6Odds = 0;
        come8Odds = 0;
        come9Odds = 0;
        come10Odds = 0;
        field = 0;
        dontPassOption = 0;
        dontPass = 0;
        dontPassOdds = 0;
        dontCome = 0;
        dontComeOption = 0;
        dontComeOption2 = 0;
        dontCome4 = 0;
        dontCome5 = 0;
        dontCome6 = 0;
        dontCome8 = 0;
        dontCome9 = 0;
        dontCome10 = 0;
        dontCome4Odds = 0;
        dontCome5Odds = 0;
        dontCome6Odds = 0;
        dontCome8Odds = 0;
        dontCome9Odds = 0;
        dontCome10Odds = 0;
        hard4 = 0;
        hard6 = 0;
        hard8 = 0;
        hard10 = 0;
        two = 0;
        three = 0;
        eleven = 0;
        twelve = 0;
        hiLo = 0;
        anyCraps = 0;
        CE = 0;
        any7 = 0;
    }
    void buyIn()
    {

        Test test;
        cout<<"How much are you going to buy in with? ";
        invalidInput = true;
        while (invalidInput == true)
        {
            invalidInput = false;
            cin>>money;
            startingMoney = money;
            test.testForInt(money);
            money = test.getNewValue();
            if (money < 5)
            {
                cout<<"     This table has a $5 minimum!"<<endl;
                cout<<"     Try again! ";
                invalidInput = true;
            }
            else if (money > 1000)
            {
                cout<<"     You're too much of a high roller for this table!"<<endl;
                cout<<"     Try again! ";
                invalidInput = true;
            }
            else
            {
                invalidInput = false;
            }
        }
    }
    void makeBets()
    {
        cout<<"What bet do you want to make? "<<endl;
        cout<<"Input '0' when you're ready to roll! ";
        cin>>input;
        cout<<endl<<endl;
        //pass line bet
        if (input == 1)
        {
            if (point == 0)
            {
                if (passLine > 0)
                {
                    cout<<"What do you want to change your pass line bet to? ";
                    money = money + passLine;
                    cin>>passLine;
                    while ((money - passLine < 0) || (passLine < 0) || (passLine % 5 != 0))
                    {
                        cout<<"Invalid amount! Try again! "<<endl;
                        cin>>passLine;
                    }
                    money = money - passLine;
                }
                else
                {
                    cout<<"How much do you want to put on the pass line? "<<endl;
                    cin>>passLine;
                    while ((money - passLine < 0) || (passLine < 0) || (passLine % 5 != 0))
                    {
                        cout<<"Invalid amount! Try again! "<<endl;
                        cin>>passLine;
                    }
                    money = money - passLine;
                }
            }
            if (point != 0)
            {
                if (passLine > 0)
                {
                    cout<<"What do you want to change the odds on your pass line bet to? "<<endl;
                    money = money + passLineOdds;
                    cin>>passLineOdds;
                    while ((money - passLineOdds < 0) || (passLineOdds < 0) || (passLineOdds > (passLine * 5)))
                    {
                        cout<<"Invalid bet, try again! ";
                        cin>>passLineOdds;
                        cout<<endl;
                    }
                    money = money - passLineOdds;
                }
                else
                {
                    cout<<"You can only bet on the pass line on the come out! "<<endl;
                    system("pause");
                }
            }
        }
        //place bets
        if (input == 2)
        {
            if (point > 0)
            {
                cout<<"Please input which place bet you would like to make: ";
                cin>>input;
                while ((input > 10) || (input < 4) || (input == 7))
                {
                    cout<<"That is not a valid Place bet! Please try again: ";
                    cin>>input;
                }
                if (input == 4)
                {
                    money = money + place4;
                    cout<<"How much money do you want to put on the four? ";
                    cin>>place4;
                    while ((place4 < 0) || (place4 > money) || (place4 % 5) != 0)
                    {
                        cout<<"Invalid bet, try again! ";
                        cin>>place4;
                    }
                    money = money - place4;
                }
                if (input == 5)
                {
                    money = money + place5;
                    cout<<"How much money do you want to put on the five? ";
                    cin>>place5;
                    while ((place5 < 0) || (place5 > money) || (place5 % 5) != 0)
                    {
                        cout<<"Invalid bet, try again! ";
                        cin>>place5;
                    }
                    money = money - place5;
                }
                if (input == 6)
                {
                    money = money + place6;
                    cout<<"How much money do you want to put on the six? ";
                    cin>>place6;
                    while ((place6 < 0) || (place6 > money) || (place6 % 6) != 0)
                    {
                        cout<<"Invalid bet, try again! ";
                        cin>>place6;
                    }
                    money = money - place6;
                }
                if (input == 8)
                {
                    money = money + place8;
                    cout<<"How much money do you want to put on the eight? ";
                    cin>>place8;
                    while ((place8 < 0) || (place8 > money) || (place8 % 6) != 0)
                    {
                        cout<<"Invalid bet, try again! ";
                        cin>>place8;
                    }
                    money = money - place8;
                }
                if (input == 9)
                {
                    money = money + place9;
                    cout<<"How much money do you want to put on the nine? ";
                    cin>>place9;
                    while ((place9 < 0) || (place9 > money) || (place9 % 5) != 0)
                    {
                        cout<<"Invalid bet, try again! ";
                        cin>>place9;
                    }
                    money = money - place9;
                }
                if (input == 10)
                {
                    money = money + place10;
                    cout<<"How much money do you want to put on the ten? ";
                    cin>>place10;
                    while ((place10 < 0) || (place10 > money) || (place10 % 5) != 0)
                    {
                        cout<<"Invalid bet, try again! ";
                        cin>>place10;
                    }
                    money = money - place10;
                }
                input = 50;
            }
            else
            {
                cout<<"Wait until a point is established to make a place bet! "<<endl;
                cin.get();
                cin.ignore(100000, '\n');
            }
        }
        //come bet
        if (input == 3)
        {
            cout<<endl<<endl;
            cout<<"Input '1' to make/change your come bet"<<endl;
            cout<<"Input '2' to change your odds on a come bet "<<endl;
            cout<<"To go back, input '0': ";
            comeOption = 100; //"clear" comeOption variable
            cin>>comeOption;
            cout<<endl;
            while ((comeOption < 0) || (comeOption > 2))
            {
                cout<<"Invalid choice, Try again! ";
                cin>>comeOption;
                cout<<endl;
            }
            if (comeOption == 1)
            {
                if (point == 0)
                {
                    cout<<"You can't have a Come bet on the come out roll!"<<endl;
                    cout<<"Bet on the Pass Line instead!"<<endl<<endl;
                    system("pause");
                }
                else
                {
                    if (come > 0)
                    {
                        cout<<"What do you want to change your come bet to? ";
                        money = money + come;
                        cin>>come;
                        cout<<endl;
                        while ((money - come < 0) || (come < 0) || (come % 5 != 0))
                        {
                            cout<<"Invalid come bet, try again! ";
                            cin>>come;
                            cout<<endl;
                        }
                        money = money - come;
                    }
                    else
                    {
                        cout<<"How much of a come bet do you want to make? ";
                        cin>>come;
                        cout<<endl;
                        while ((money - come < 0) || (come < 0) || (come % 5 !=0))
                        {
                            cout<<"Invalid come bet, try again! ";
                            cin>>come;
                            cout<<endl;
                        }
                        money = money - come;
                    }
                }
            }
            if (comeOption == 2)
            {
                comeOption == 100;
                if ((come4 == 0) && (come5 == 0) && (come6 == 0) && (come8 == 0) && (come9 == 0) && (come10 == 0))
                {
                    cout<<"You don't have a Come bet to change the odds on! "<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"Which Come bet do you want to change the odds on? "<<endl;
                    if (come4 > 0)
                    {
                        cout<<" Four (4)"<<endl;
                    }
                    if (come5 > 0)
                    {
                        cout<<" Five (5)"<<endl;
                    }
                    if (come6 > 0)
                    {
                        cout<<"  Six (6)"<<endl;
                    }
                    if (come8 > 0)
                    {
                        cout<<"Eight (8)"<<endl;
                    }
                    if (come9 > 0)
                    {
                        cout<<" Nine (9)"<<endl;
                    }
                    if (come10 > 0)
                    {
                        cout<<" Ten (10)"<<endl;
                    }
                    cout<<"Go back (0) ";
                    cin>>comeOption2;
                    cout<<endl;
                    while ((comeOption2 < 0) || (comeOption2 == 1) || (comeOption2 == 2) || (comeOption2 == 3) || (comeOption2 == 7) || (comeOption2 > 10))
                    {
                        cout<<"Invalid option, try again! ";
                        cin>>comeOption2;
                        cout<<endl;
                    }
                    if ((comeOption2 == 4) && (come4 > 0))
                    {
                        cout<<"What do you want to change your Four Come bet odds to? "<<endl;
                        money = money + come4Odds;
                        cin>>come4Odds;
                        while ((come4Odds < 0) || (money - come4Odds < 0) || (come4Odds > come4 * 5))
                        {
                            cout<<"Invalid odds, try again! ";
                            cin>>come4Odds;
                            cout<<endl;
                        }
                        money = money - come4Odds;
                    }
                    else if ((comeOption2 == 5) && (come5 > 0))
                    {
                        cout<<"What do you want to change your Five Come bet odds to? "<<endl;
                        money = money + come5Odds;
                        cin>>come5Odds;
                        while ((come5Odds < 0) || (money - come5Odds < 0) || (come5Odds > come5 * 5))
                        {
                            cout<<"Invalid odds, try again! ";
                            cin>>come5Odds;
                            cout<<endl;
                        }
                        money = money - come5Odds;
                    }
                    else if ((comeOption2 == 6) && (come6 > 0))
                    {
                        cout<<"What do you want to change your Six Come bet odds to? "<<endl;
                        money = money + come6Odds;
                        cin>>come6Odds;
                        while ((come6Odds < 0) || (money - come6Odds < 0) || (come6Odds > come6 * 5))
                        {
                            cout<<"Invalid odds, try again! ";
                            cin>>come6Odds;
                            cout<<endl;
                        }
                        money = money - come6Odds;
                    }
                    else if ((comeOption2 == 8) && (come8 > 0))
                    {
                        cout<<"What do you want to change your Eight Come bet odds to? "<<endl;
                        money = money + come8Odds;
                        cin>>come8Odds;
                        while ((come8Odds < 0) || (money - come8Odds < 0) || (come8Odds > come8 * 5))
                        {
                            cout<<"Invalid odds, try again! ";
                            cin>>come8Odds;
                            cout<<endl;
                        }
                        money = money - come8Odds;
                    }
                    else if ((comeOption2 == 9) && (come9 > 0))
                    {
                        cout<<"What do you want to change your Nine Come bet odds to? "<<endl;
                        money = money + come9Odds;
                        cin>>come9Odds;
                        while ((come9Odds < 0) || (money - come9Odds < 0) || (come9Odds > come9 * 5))
                        {
                            cout<<"Invalid odds, try again! ";
                            cin>>come9Odds;
                            cout<<endl;
                        }
                        money = money - come9Odds;
                    }
                    else if ((comeOption2 == 10) && (come10 > 0))
                    {
                        cout<<"What do you want to change your Ten Come bet odds to? "<<endl;
                        money = money + come10Odds;
                        cin>>come10Odds;
                        while ((come10Odds < 0) || (money - come10Odds < 0) || (come10Odds > come10 * 5))
                        {
                            cout<<"Invalid odds, try again! ";
                            cin>>come10Odds;
                            cout<<endl;
                        }
                        money = money - come10Odds;
                    }
                    else if (comeOption2 == 0)
                    {

                    }
                    else
                    {
                        cout<<"You don't have a Come bet on that number! "<<endl;
                        system("pause");
                    }
                }
            }
            if (comeOption == 0)
            {

            }
        }
        //field bet
        if (input == 4)
        {
            cout<<"How much do you want to put on the field? "<<endl;
            money = money + field;
            cin>>field;
            while ((money - field < 0) || (field < 0) || (field == 1) || (field == 2) || (field == 3) || (field == 4))
            {
                cout<<"Invalid amount! Try again! "<<endl;
                cin>>field;
            }
            money = money - field;
        }
        //don't pass
        if (input == 5)
        {
            cout<<endl<<endl;
            cout<<"Input '1' to make/remove your Don't Pass Line bet"<<endl;
            cout<<"Input '2' to change your odds on your Don't Pass Line bet "<<endl;
            cout<<"To go back, input '0': ";
            cin>>dontPassOption;
            cout<<endl;
            while ((dontPassOption < 0) || (dontPassOption > 2))
            {
                cout<<"Invalid choice, Try again! ";
                cin>>dontPassOption;
            }
            if (dontPassOption == 1)
            {
                if (dontPass > 0)
                {
                    money = money + dontPassOdds;
                    money = money + dontPass;
                    cout<<"You removed your Don't Pass Line bet "<<endl;
                    dontPassOdds = 0;
                    dontPass = 0;
                }
                else
                {
                    if (point != 0)
                    {
                        cout<<"You can only bet on the don't pass line on the come out roll! "<<endl;
                        cout<<"Try a don't come bet instead! "<<endl<<endl;
                        system("pause");
                    }
                    if (point == 0)
                    {
                        cout<<"How much do you want to put on the Don't Pass line? ";
                        cin>>dontPass;
                        while ((money - dontPass < 0) || (dontPass < 0) || (dontPass % 5 != 0))
                        {
                            cout<<"Invalid bet, try again! ";
                            cin>>dontPass;
                            cout<<endl;
                        }
                        money = money - dontPass;
                    }
                }
            }
            if (dontPassOption == 2)
            {
                if (dontPass <= 0)
                {
                    cout<<"You have to have a Don't Pass Line bet to lay odds on it! "<<endl<<endl;
                    system("pause");
                }
                else if (point == 0)
                {
                    cout<<"A point must be established before you can lay odds on the Don't Pass Line bet!"<<endl<<endl;
                    system("pause");
                }
                else
                {
                    if ((point == 4) || (point == 10))
                    {
                        money = money + dontPassOdds;
                        cout<<"What odds do you want your Don't Pass Line bet to have? ";
                        cin>>dontPassOdds;
                        cout<<endl;
                        while ((money - dontPassOdds < 0) || (dontPassOdds < 0) || (dontPass * 10 < dontPassOdds))
                        {
                            cout<<"Invalid odds, try again! ";
                            cin>>dontPassOdds;
                            cout<<endl;
                        }
                        money = money - dontPassOdds;
                    }
                    if ((point == 5) || (point == 9))
                    {
                        money = money + dontPassOdds;
                        cout<<"What odds do you want your Don't Pass Line bet to have? ";
                        cin>>dontPassOdds;
                        cout<<endl;
                        while ((money - dontPassOdds < 0) || (dontPassOdds < 0) || ((((dontPass * 5) * 3) / 2) < dontPassOdds))
                        {
                            cout<<"Invalid odds, try again! ";
                            cin>>dontPassOdds;
                            cout<<endl;
                        }
                        money = money - dontPassOdds;
                    }
                    if ((point == 6) || (point == 8))
                    {
                        money = money + dontPassOdds;
                        cout<<"What odds do you want your Don't Pass Line bet to have? ";
                        cin>>dontPassOdds;
                        cout<<endl;
                        while ((money - dontPassOdds < 0) || (dontPassOdds < 0) || ((((dontPass * 5) * 6) / 5) < dontPassOdds))
                        {
                            cout<<"Invalid odds, try again! ";
                            cin>>dontPassOdds;
                            cout<<endl;
                        }
                        money = money - dontPassOdds;
                    }
                }
            }
        }
        //don't come
        if (input == 6)
        {
            cout<<endl<<endl;
            cout<<"Input '1' to make/change your Don't Come bet"<<endl;
            cout<<"Input '2' to change your Don't Come bet that has an established point"<<endl;
            cout<<"To go back, input '0': ";
            dontComeOption = 100; //"clear" dontComeOption variable
            cin>>dontComeOption;
            cout<<endl;
            while ((dontComeOption < 0) || (dontComeOption > 2))
            {
                cout<<"Invalid choice, Try again! ";
                cin>>dontComeOption;
                cout<<endl;
            }
            if (dontComeOption == 1) //make/change a dont come bet
            {
                if (point == 0) //if there hasn't been a point established
                {
                    cout<<"You can't have a Don't Come bet on the come out roll!"<<endl;
                    cout<<"Bet on the Don't Pass Line instead!"<<endl<<endl;
                    system("pause");
                }
                else //if there has been a point established
                {
                    if (dontCome > 0) //if there is already a don't come bet on the table
                    {
                        cout<<"What do you want to change your Don't Come bet to? ";
                        money = money + dontCome;
                        cin>>dontCome;
                        cout<<endl;
                        while ((money - dontCome < 0) || (dontCome < 0) || (dontCome % 5 != 0))
                        {
                            cout<<"Invalid bet, try again!";
                            cin>>dontCome;
                            cout<<endl;
                        }
                        money = money - dontCome;
                    }
                    else //if there is no don't come bet on the table
                    {
                        cout<<"How much of a Don't Come bet do you want to make? ";
                        money = money + dontCome;
                        cin>>dontCome;
                        cout<<endl;
                        while ((money - dontCome < 0) || (dontCome < 0) || (dontCome % 5 != 0))
                        {
                            cout<<"Invalid bet, try again!";
                            cin>>dontCome;
                            cout<<endl;
                        }
                        money = money - dontCome;
                    }
                }
            }
            if (dontComeOption == 2) //change dont come bet/dont come odds
            {
                if ((dontCome4 == 0) && (dontCome5 == 0) && (dontCome6 == 0) && (dontCome8 == 0) && (dontCome9 == 0) && (dontCome10 == 0))
                {
                    cout<<"You don't have any Don't Come bets that have established points!"<<endl<<endl<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"Which Don't Come bet do you want to change?"<<endl;
                    if (dontCome4 > 0)
                    {
                        cout<<" Four (4)"<<endl;
                    }
                    if (dontCome5 > 0)
                    {
                        cout<<" Five (5)"<<endl;
                    }
                    if (dontCome6 > 0)
                    {
                        cout<<"  Six (6)"<<endl;
                    }
                    if (dontCome8 > 0)
                    {
                        cout<<"Eight (8)"<<endl;
                    }
                    if (dontCome9 > 0)
                    {
                        cout<<" Nine (9)"<<endl;
                    }
                    if (dontCome10 > 0)
                    {
                        cout<<" Ten (10)"<<endl;
                    }
                    cout<<"Go back (0) ";
                    cin>>dontComeOption2;
                    cout<<endl;
                    while ((dontComeOption2 < 0) || (dontComeOption2 == 1) || (dontComeOption2 == 2) || (dontComeOption2 == 3) || (dontComeOption2 == 7) || (dontComeOption2 > 10))
                    {
                        cout<<"Invalid option, try again! ";
                        cin>>dontComeOption2;
                        cout<<endl;
                    }
                    if ((dontComeOption2 == 4) && (dontCome4 > 0))
                    {
                        money = money + dontCome4;
                        money = money + dontCome4Odds;
                        dontCome4Odds = 0;
                        cout<<"What do you want to change your Four Don't Come bet to? ";
                        cin>>newDontCome;
                        cout<<endl<<endl;
                        while ((dontCome4 < 5) || (money - dontCome4 < 0) || ((dontCome4 % 5) != 0) || (newDontCome > dontCome4))
                        {
                            cout<<"Invalid bet, try again! ";
                            cin>>newDontCome;
                            cout<<endl;
                        }
                        dontCome4 = newDontCome;
                        money = money - dontCome4;
                        if (dontCome4 > 0);
                        {
                            cout<<"Input the amount of odds you want to lay on your Four Don't Come bet: ";
                            cin>>dontCome4Odds;
                            cout<<endl;
                            while ((dontCome4Odds < 0) || (money - dontCome4Odds < 0) || (dontCome4 * 10 < dontCome4Odds))
                            {
                                cout<<"Invalid odds, try again!";
                                cin>>dontCome4Odds;
                                cout<<endl;
                            }
                            money = money - dontCome4Odds;
                        }
                    }
                    else if ((dontComeOption2 == 5) && (dontCome5 > 0))
                    {
                        money = money + dontCome5;
                        money = money + dontCome5Odds;
                        dontCome5Odds = 0;
                        cout<<"What do you want to change your Five Don't Come bet to? ";
                        cin>>newDontCome;
                        cout<<endl<<endl;
                        while ((dontCome5 < 5) || (money - dontCome5 < 0) || ((dontCome5 % 5) != 0) || (newDontCome > dontCome5))
                        {
                            cout<<"Invalid bet, try again! ";
                            cin>>newDontCome;
                            cout<<endl;
                        }
                        dontCome5 = newDontCome;
                        money = money - dontCome5;
                        if (dontCome5 > 0)
                        {
                            cout<<"Input the amount of odds you want to lay on your Five Don't Come bet: ";
                            cin>>dontCome5Odds;
                            cout<<endl;
                            while ((dontCome5Odds < 0) || (money - dontCome5Odds < 0) || ((((dontCome5 * 5) * 3) / 2) < dontCome5Odds))
                            {
                                cout<<"Invalid odds, try again!";
                                cin>>dontCome5Odds;
                                cout<<endl;
                            }
                            money = money - dontCome5Odds;
                        }
                    }
                    else if ((dontComeOption2 == 6) && (dontCome6 > 0))
                    {
                        money = money + dontCome6;
                        money = money + dontCome6Odds;
                        dontCome6Odds = 0;
                        cout<<"What do you want to change your Six Don't Come bet to? ";
                        cin>>newDontCome;
                        cout<<endl<<endl;
                        while ((dontCome6 < 5) || (money - dontCome6 < 0) || ((dontCome6 % 5) != 0) || (newDontCome > dontCome6))
                        {
                            cout<<"Invalid bet, try again! ";
                            cin>>newDontCome;
                            cout<<endl;
                        }
                        dontCome6 = newDontCome;
                        money = money - dontCome6;
                        if (dontCome6 > 0)
                        {
                            cout<<"Input the amount of odds you want to lay on your Six Don't Come bet: ";
                            cin>>dontCome6Odds;
                            cout<<endl;
                            while ((dontCome6Odds < 0) || (money - dontCome6Odds < 0) || ((((dontCome6 * 5) * 6) / 5) < dontCome6Odds))
                            {
                                cout<<"Invalid odds, try again!";
                                cin>>dontCome6Odds;
                                cout<<endl;
                            }
                            money = money - dontCome6Odds;
                        }
                    }
                    else if ((dontComeOption2 == 8) && (dontCome8 > 0))
                    {
                        money = money + dontCome8;
                        money = money + dontCome8Odds;
                        dontCome8Odds = 0;
                        cout<<"What do you want to change your Eight Don't Come bet to? ";
                        cin>>newDontCome;
                        cout<<endl<<endl;
                        while ((dontCome8 < 5) || (money - dontCome8 < 0) || ((dontCome8 % 5) != 0) || (newDontCome > dontCome8))
                        {
                            cout<<"Invalid bet, try again! ";
                            cin>>newDontCome;
                            cout<<endl;
                        }
                        dontCome8 = newDontCome;
                        money = money - dontCome8;
                        if (dontCome8 > 0)
                        {
                            cout<<"Input the amount of odds you want to lay on your Eight Don't Come bet: ";
                            cin>>dontCome8Odds;
                            cout<<endl;
                            while ((dontCome8Odds < 0) || (money - dontCome8Odds < 0) || ((((dontCome8 * 5) * 6) / 5) < dontCome8Odds))
                            {
                                cout<<"Invalid odds, try again!";
                                cin>>dontCome8Odds;
                                cout<<endl;
                            }
                            money = money - dontCome8Odds;
                        }
                    }
                    else if ((dontComeOption2 == 9) && (dontCome9 > 0))
                    {
                        money = money + dontCome9;
                        money = money + dontCome9Odds;
                        dontCome9Odds = 0;
                        cout<<"What do you want to change your Nine Don't Come bet to? ";
                        cin>>newDontCome;
                        cout<<endl<<endl;
                        while ((dontCome9 < 5) || (money - dontCome9 < 0) || ((dontCome9 % 5) != 0) || (newDontCome > dontCome9))
                        {
                            cout<<"Invalid bet, try again! ";
                            cin>>newDontCome;
                            cout<<endl;
                        }
                        dontCome9 = newDontCome;
                        money = money - dontCome9;
                        if (dontCome9 > 0)
                        {
                            cout<<"Input the amount of odds you want to lay on your Nine Don't Come bet: ";
                            cin>>dontCome8Odds;
                            cout<<endl;
                            while ((dontCome9Odds < 0) || (money - dontCome9Odds < 0) || ((((dontCome9 * 5) * 3) / 2) < dontCome9Odds))
                            {
                                cout<<"Invalid odds, try again!";
                                cin>>dontCome9Odds;
                                cout<<endl;
                            }
                            money = money - dontCome9Odds;
                        }
                    }
                    else if ((dontComeOption2 == 10) && (dontCome10 > 0))
                    {
                        money = money + dontCome10;
                        money = money + dontCome10Odds;
                        dontCome10Odds = 0;
                        cout<<"What do you want to change your Ten Don't Come bet to? ";
                        cin>>newDontCome;
                        cout<<endl<<endl;
                        while ((dontCome10 < 5) || (money - dontCome10 < 0) || ((dontCome10 % 5) != 0) || (newDontCome > dontCome10))
                        {
                            cout<<"Invalid bet, try again! ";
                            cin>>newDontCome;
                            cout<<endl;
                        }
                        dontCome10 = newDontCome;
                        money = money - dontCome10;
                        if (dontCome10 > 0)
                        {
                            cout<<"Input the amount of odds you want to lay on your Ten Don't Come bet: ";
                            cin>>dontCome10Odds;
                            cout<<endl;
                            while ((dontCome10Odds < 0) || (money - dontCome10Odds < 0) || (dontCome10 * 10 < dontCome10Odds))
                            {
                                cout<<"Invalid odds, try again!";
                                cin>>dontCome10Odds;
                                cout<<endl;
                            }
                            money = money - dontCome10Odds;
                        }
                    }
                    else if (dontComeOption2 == 0)
                    {

                    }
                    else
                    {
                        cout<<"You don't have a Don't Come bet on that number! "<<endl;
                        system("pause");
                    }
                }
            }
            if (dontComeOption == 0) //go back
            {

            }
        }
        //cashout
        if (input == 8)
        {
            system("CLS");
            cout<<"You started with "<<startingMoney<<" and ended with "<<money<<". "<<endl;
            if (money > startingMoney)
            {
                cout<<"You made a little bit of money today!"<<endl;
            }
            else
            {
                cout<<"Better luck next time..."<<endl;
            }
            return;
        }
    }

    //setters and getters
    void setMoney(int inMoney)
    {
        money = inMoney;
    }
    int getMoney()
    {
        return money;
    }
    void setPoint(int inPoint)
    {
        point = inPoint;
    }
    int getPoint()
    {
        return point;
    }
    void setInput(int inInput)
    {
        input = inInput;
    }
    int getInput()
    {
        return input;
    }
    void setPassLine(int inPass)
    {
        passLine = inPass;
    }
    int getPassLine()
    {
        return passLine;
    }
    void setPassLineOdds(int inPassOdds)
    {
        passLineOdds = inPassOdds;
    }
    int getPassLineOdds()
    {
        return passLineOdds;
    }
    void setPlace4 (int inPlace)
    {
        place4 = inPlace;
    }
    int getPlace4 ()
    {
        return place4;
    }
    void setPlace5 (int inPlace)
    {
        place5 = inPlace;
    }
    int getPlace5 ()
    {
        return place5;
    }
    void setPlace6 (int inPlace)
    {
        place6 = inPlace;
    }
    int getPlace6 ()
    {
        return place6;
    }
    void setPlace8 (int inPlace)
    {
        place8 = inPlace;
    }
    int getPlace8 ()
    {
        return place8;
    }
    void setPlace9 (int inPlace)
    {
        place9 = inPlace;
    }
    int getPlace9 ()
    {
        return place9;
    }
    void setPlace10 (int inPlace)
    {
        place10 = inPlace;
    }
    int getPlace10 ()
    {
        return place10;
    }
    void setCome (int inCome)
    {
        come = inCome;
    }
    int getCome()
    {
        return come;
    }
    void setCome4 (int inCome)
    {
        come4 = inCome;
    }
    int getCome4 ()
    {
        return come4;
    }
    void setCome5 (int inCome)
    {
        come5 = inCome;
    }
    int getCome5 ()
    {
        return come5;
    }
    void setCome6 (int inCome)
    {
        come6 = inCome;
    }
    int getCome6 ()
    {
        return come6;
    }
    void setCome8 (int inCome)
    {
        come8 = inCome;
    }
    int getCome8 ()
    {
        return come8;
    }
    void setCome9 (int inCome)
    {
        come9 = inCome;
    }
    int getCome9 ()
    {
        return come9;
    }
    void setCome10 (int inCome)
    {
        come10 = inCome;
    }
    int getCome10 ()
    {
        return come10;
    }
    void setCome4Odds(int inCome)
    {
        come4Odds = inCome;
    }
    int getCome4Odds()
    {
        return come4Odds;
    }
    void setCome5Odds(int inCome)
    {
        come5Odds = inCome;
    }
    int getCome5Odds()
    {
        return come5Odds;
    }
    void setCome6Odds(int inCome)
    {
        come6Odds = inCome;
    }
    int getCome6Odds()
    {
        return come6Odds;
    }
    void setCome8Odds(int inCome)
    {
        come8Odds = inCome;
    }
    int getCome8Odds()
    {
        return come8Odds;
    }
    void setCome9Odds(int inCome)
    {
        come9Odds = inCome;
    }
    int getCome9Odds()
    {
        return come9Odds;
    }
    void setCome10Odds(int inCome)
    {
        come10Odds = inCome;
    }
    int getCome10Odds()
    {
        return come10Odds;
    }
    void setField(int inField)
    {
        field = inField;
    }
    int getField()
    {
        return field;
    }
    void setDontPass(int inDont)
    {
        dontPass = inDont;
    }
    int getDontPass()
    {
        return dontPass;
    }
    void setDontPassOdds(int inDont)
    {
        dontPassOdds = inDont;
    }
    int getDontPassOdds()
    {
        return dontPassOdds;
    }
    void setDontCome(int inDont)
    {
        dontCome = inDont;
    }
    int getDontCome()
    {
        return dontCome;
    }
    void setDontCome4(int inDont)
    {
        dontCome4 = inDont;
    }
    int getDontCome4()
    {
        return dontCome4;
    }
    void setDontCome5(int inDont)
    {
        dontCome5 = inDont;
    }
    int getDontCome5()
    {
        return dontCome5;
    }
    void setDontCome6(int inDont)
    {
        dontCome6 = inDont;
    }
    int getDontCome6()
    {
        return dontCome6;
    }
    void setDontCome8(int inDont)
    {
        dontCome8 = inDont;
    }
    int getDontCome8()
    {
        return dontCome8;
    }
    void setDontCome9(int inDont)
    {
        dontCome9 = inDont;
    }
    int getDontCome9()
    {
        return dontCome9;
    }
    void setDontCome10(int inDont)
    {
        dontCome10 = inDont;
    }
    int getDontCome10()
    {
        return dontCome10;
    }
    void setDontCome4Odds(int inDont)
    {
        dontCome4Odds = inDont;
    }
    int getDontCome4Odds()
    {
        return dontCome4Odds;
    }
    void setDontCome5Odds(int inDont)
    {
        dontCome5Odds = inDont;
    }
    int getDontCome5Odds()
    {
        return dontCome5Odds;
    }
    void setDontCome6Odds(int inDont)
    {
        dontCome6Odds = inDont;
    }
    int getDontCome6Odds()
    {
        return dontCome6Odds;
    }
    void setDontCome8Odds(int inDont)
    {
        dontCome8Odds = inDont;
    }
    int getDontCome8Odds()
    {
        return dontCome8Odds;
    }
    void setDontCome9Odds(int inDont)
    {
        dontCome9Odds = inDont;
    }
    int getDontCome9Odds()
    {
        return dontCome9Odds;
    }
    void setDontCome10Odds(int inDont)
    {
        dontCome10Odds = inDont;
    }
    int getDontCome10Odds()
    {
        return dontCome10Odds;
    }
};
#endif
