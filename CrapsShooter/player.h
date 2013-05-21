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
    int come, comeOdds;
    int field;
    int dontPass, dontPassOdds;
    int dontCome, dontComeOdds;
    //center action
    int hard4, hard6, hard8, hard10;
    //one roll bets
    int two, three, eleven, twelve, hiLo, anyCraps, CE, any7;

    bool invalidInput;
public:
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
        comeOdds = 0;
        field = 0;
        dontPass = 0;
        dontPassOdds = 0;
        dontCome = 0;
        dontComeOdds = 0;
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
        cout<<"Input '0' when you're ready to roll! "<<endl<<endl;
        cin>>input;
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
                    while ((money - passLine < 0) || (passLine < 0))
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
                    while ((money - passLine < 0) || (passLine < 0))
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
                    while (money - passLineOdds < 0)
                    {
                        cout<<"You don't have enough money! Try again! "<<endl;
                        cin>>passLineOdds;
                        while ((passLineOdds < 0) || (passLineOdds > (passLine * 5)))
                        {
                            cout<<"Invalid Odds, try again!"<<endl;
                            cin>>passLineOdds;
                        }
                    }
                    while ((passLineOdds < 0) || (passLineOdds > (passLine * 5)))
                    {
                        cout<<"Invalid Odds, try again!"<<endl;
                        cin>>passLineOdds;
                        while (money - passLineOdds <= 0)
                        {
                            cout<<"You don't have enough money! Try again! "<<endl;
                            cin>>passLineOdds;
                        }
                    }
                    money = money - passLineOdds;
                }
                else
                {
                    cout<<"You can only bet on the pass line on the come out! "<<endl;
                    cout<<"It would be smarter to make a place bet anyway! "<<endl;
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
    void setField(int inField)
    {
        field = inField;
    }
    int getField()
    {
        return field;
    }
};
#endif
