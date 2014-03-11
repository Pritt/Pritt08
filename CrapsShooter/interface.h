#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <cstdlib>
#include "player.h"
using namespace std;

class Interface
{
private:
    int diceSum;
public:
    void initialize()
    {
        cout<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"           ___                                  ___    /                /'          "<<endl;
        cout<<"         /'   )                               /'   )  /             ___/___         "<<endl;
        cout<<"        /      ___    ___     ___    __      (____   /___   ___  ___  /   ___   ___ "<<endl;
        cout<<"       /      )'  ) /'   )  /'   ) ('  )          ) /    ) /   )/   )/  /'   ) /'  )"<<endl;
        cout<<"      /      /'    /'   /  /    /   '-,          / /    / /   //   //  /(__,/ /     "<<endl;
        cout<<"     (___,/ /'    (___,/( /(__,/  (__,/    (___,/ /    (_(___/(___/(_ (____, /      "<<endl;
        cout<<"                         /                                                          "<<endl;
        cout<<"                        /                                                           "<<endl;
        cout<<"                       /                                                            "<<endl;
        cout<<"                              ........."<<endl;
        cout<<"                             :~, *   * ~,"<<endl;
        cout<<"                             : ~, *   * ~."<<endl;
        cout<<"                             :* ~........~"<<endl;
        cout<<"                             :  :         :      ~'~,"<<endl;
        cout<<"                             :  :         :    ~' *  ~,"<<endl;
        cout<<"                             ~ *:    *    : ,~' *    * ~,"<<endl;
        cout<<"                              ~,:         :.~,*    *  ,~ :"<<endl;
        cout<<"                               ~:.........::  ~, *  ,~   :"<<endl;
        cout<<"              By Andy Pritt                : *  ~,,~  *  :"<<endl;
        cout<<"                                           :* * * :  *   :"<<endl;
        cout<<"                                            ~, *  : *  ,~"<<endl;
        cout<<"                                              ~,  :  ,~"<<endl;
        cout<<"                                                ~,:,~"<<endl;
        cout<<endl<<endl;
        cout<<"                                Press 'Enter' to begin!"<<endl;
        cin.ignore(100000, '\n');
        cout<<endl<<endl;
    }
    void printAbove(Player& player1)
    {
        cout<<"   BETTING LEGEND"<<endl<<endl;
        cout<<"  Roll the dice = 0          Current Money "<<player1.getMoney()<<endl;
        cout<<"      Pass Line = 1          The Point is currently "<<player1.getPoint()<<endl;
        cout<<"     Place Bets = 2 "<<endl;
        cout<<"       Come Bet = 3 "<<endl;
        cout<<"      Field Bet = 4 "<<endl;
        cout<<"Don't Pass Line = 5 "<<endl;
        cout<<"     Don't Come = 6 "<<endl;
        //cout<<"  Center Action = 7 "<<endl;
        //cout<<"       Cash out = 8 "<<endl;
        cout<<endl<<endl;
    }

    //prints current money and bets currently active
    void printBelow(Player& player1)
    {
        //pass line w/odds
        if (player1.getPassLine() > 0)
        {
            cout<<"Pass Line bet: "<<player1.getPassLine()<<" with "<<player1.getPassLineOdds()<<" odds"<<endl;
        }
        //place bets
        if ((player1.getPlace4() > 0) || (player1.getPlace5() > 0) || (player1.getPlace6() > 0) ||
            (player1.getPlace8() > 0) || (player1.getPlace9() > 0) || (player1.getPlace10() > 0))
        {
            cout<<"Place Bets: "<<endl;
            if (player1.getPlace4() > 0)
            {
                cout<<"    Four: "<<player1.getPlace4()<<endl;
            }
            if (player1.getPlace5() > 0)
            {
                cout<<"    Five: "<<player1.getPlace5()<<endl;
            }
            if (player1.getPlace6() > 0)
            {
                cout<<"     Six: "<<player1.getPlace6()<<endl;
            }
            if (player1.getPlace8() > 0)
            {
                cout<<"   Eight: "<<player1.getPlace8()<<endl;
            }
            if (player1.getPlace9() > 0)
            {
                cout<<"    Nine: "<<player1.getPlace9()<<endl;
            }
            if (player1.getPlace10() > 0)
            {
                cout<<"     Ten: "<<player1.getPlace10()<<endl;
            }
        }
        //come bet (before it's established a point)
        if (player1.getCome() > 0)
        {
            cout<<"Come bet: "<<player1.getCome()<<endl;
        }
        //come bet w/ odds (once its point's been established)
        if ((player1.getCome4() > 0) || (player1.getCome5() > 0) || (player1.getCome6() > 0) ||
            (player1.getCome8() > 0) || (player1.getCome9() > 0) || (player1.getCome10() > 0))
        {
            cout<<"Come bets: "<<endl;
            if (player1.getCome4() > 0)
            {
                cout<<" Four Come Bet: "<<player1.getCome4()<<" with "<<player1.getCome4Odds()<<" odds"<<endl;
            }
            if (player1.getCome5() > 0)
            {
                cout<<" Five Come Bet: "<<player1.getCome5()<<" with "<<player1.getCome5Odds()<<" odds"<<endl;
            }
            if (player1.getCome6() > 0)
            {
                cout<<"  Six Come Bet: "<<player1.getCome6()<<" with "<<player1.getCome6Odds()<<" odds"<<endl;
            }
            if (player1.getCome8() > 0)
            {
                cout<<"Eight Come Bet: "<<player1.getCome8()<<" with "<<player1.getCome8Odds()<<" odds"<<endl;
            }
            if (player1.getCome9() > 0)
            {
                cout<<" Nine Come Bet: "<<player1.getCome9()<<" with "<<player1.getCome9Odds()<<" odds"<<endl;
            }
            if (player1.getCome10() > 0)
            {
                cout<<"  Ten Come Bet: "<<player1.getCome10()<<" with "<<player1.getCome10Odds()<<" odds"<<endl;
            }
        }
        //field bet
        if (player1.getField() > 0)
        {
            cout<<"Field bet: "<<player1.getField()<<endl;
        }
        //don't pass
        if (player1.getDontPass() > 0)
        {
            cout<<"Don't Pass Line bet: "<<player1.getDontPass()<<" with "<<player1.getDontPassOdds()<<" odds"<<endl;
        }
        //don't come bet
        if (player1.getDontCome() > 0)
        {
            cout<<"Don't Come bet: "<<player1.getDontCome()<<endl;
        }
        //don't come w/ odds (once its point's been established
        if ((player1.getDontCome4() > 0) || (player1.getDontCome5() > 0) || (player1.getDontCome6() > 0) ||
            (player1.getDontCome8() > 0) || (player1.getDontCome9() > 0) || (player1.getDontCome10() > 0))
        {
            cout<<"Don't Come bets: "<<endl;
            if (player1.getDontCome4() > 0)
            {
                cout<<" Four Don't Come Bet: "<<player1.getDontCome4()<<" with "<<player1.getDontCome4Odds()<<" odds"<<endl;
            }
            if (player1.getDontCome5() > 0)
            {
                cout<<" Five Don't Come Bet: "<<player1.getDontCome5()<<" with "<<player1.getDontCome5Odds()<<" odds"<<endl;
            }
            if (player1.getDontCome6() > 0)
            {
                cout<<"  Six Don't Come Bet: "<<player1.getDontCome6()<<" with "<<player1.getDontCome6Odds()<<" odds"<<endl;
            }
            if (player1.getDontCome8() > 0)
            {
                cout<<"Eight Don't Come Bet: "<<player1.getDontCome8()<<" with "<<player1.getDontCome8Odds()<<" odds"<<endl;
            }
            if (player1.getDontCome9() > 0)
            {
                cout<<" Nine Don't Come Bet: "<<player1.getDontCome9()<<" with "<<player1.getDontCome9Odds()<<" odds"<<endl;
            }
            if (player1.getDontCome10() > 0)
            {
                cout<<"  Ten Don't Come Bet: "<<player1.getDontCome10()<<" with "<<player1.getDontCome10Odds()<<" odds"<<endl;
            }
        }
        cout<<endl<<endl<<endl;
    }

    void rollResult(int inDie1, int inDie2, int inPoint)
    {
        diceSum = inDie1 + inDie2;
        switch (diceSum)
        {
            case 2: cout<<"Stickman: 'Two! Crap, two! Aces!' "<<endl<<endl; break;
            case 3: cout<<"Stickman: 'Three! Crap! Ace, deuce! Three!'"<<endl<<endl; break;
            case 4: cout<<"Stickman: 'Four! "; break;
            case 5: cout<<"Stickman: 'Five, fever five!' "<<endl<<endl; break;
            case 6: cout<<"Stickman: 'Six! "; break;
            case 7: cout<<"Stickman: 'Seven"; break;
            case 8: cout<<"Stickman: 'Eight! "; break;
            case 9: cout<<"Stickman: 'Nine! Nina, Nine!' "<<endl<<endl; break;
            case 10: cout<<"Stickman: 'Ten! "; break;
            case 11: cout<<"Stickman: 'Eleven! Yo, eleven!' "<<endl<<endl; break;
            case 12: cout<<"Stickman: 'Twelve! Crap, twelve!' "<<endl<<endl; break;
        }
        //check for hard ways
        if (diceSum == 4)
        {
            if (inDie1 == inDie2)
            {
                cout<<"Hard four! Hard four!' "<<endl<<endl;
            }
            else
            {
                cout<<"It came easy! Four came easy!' "<<endl<<endl;
            }
        }
        if (diceSum == 6)
        {
            if (inDie1 == inDie2)
            {
                cout<<"Hard six! Hard six!' "<<endl<<endl;
            }
            else
            {
                cout<<"It came easy! Easy six!' "<<endl<<endl;
            }
        }
        if (diceSum == 8)
        {
            if (inDie1 == inDie2)
            {
                cout<<"Hard eight! Hard eight!' "<<endl<<endl;
            }
            else
            {
                cout<<"It came easy! Easy Eight!' "<<endl<<endl;
            }
        }
        if (diceSum == 10)
        {
            if (inDie1 == inDie2)
            {
                cout<<"Hard ten! Hard ten!' "<<endl<<endl;
            }
            else
            {
                cout<<"It came easy! Ten came easy!' "<<endl<<endl;
            }
        }
        if ((diceSum == 7) && (inPoint == 0))
        {
            cout<<"! Front line winner seven! "<<endl<<endl;
        }
        if ((diceSum == 7) && (inPoint !=0 ))
        {
            cout<<", out...'"<<endl<<endl;
        }

    }

};
#endif
