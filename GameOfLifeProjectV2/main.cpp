/* 
 * File:   main.cpp
 * Author: Michael Echaluse
 * Created on June, 2020
 * Purpose: Game Of Life Version 2
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <vector>
using namespace std;  //Libraries compiled under std

//User Level Libraries

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions

//Function Prototypes
void cont(int );
void intro();
void rules(char );
bool PlayA(char& );
//Execution Begins Here!
int main(int argc, char** argv) {
    //Random Number Seed Set Here
    
    //Variable Declarations
    char Rules, Play, College, Wheel;
    string dummy;
    int Moves, Spin, Job, PayDay, cash, NA, card;
    float Money;
    bool Game, Loop;
    vector<string> LifeC(0); //In case the player gets a certain amount of life cards
    //Variable Initialization
    Moves=0; //Sets a baseline of movement
    srand(time(0)); //True Random Selection
    card=0;
    Money=0;
    cout<<setprecision(2)<<fixed;
    Spin = rand() % 3 + 1; //Spins between 1 and 3
    intro();
    cout<<"Would you like to read the rules?(Y/N)"<<endl; //Option to read the rules
    cout<<endl;
    cin>>Rules;
    cout<<endl;
    if(Rules == 'Y' || Rules == 'y') {
        rules(Rules);
    }
    else if(Rules == 'N' || Rules == 'n') {
        cout<<"Then we will continue on...."<<endl; //Continue if declined
    }
    else { //Precaution in case the player does not answer thoroughly 
        cout<<"You did not respond with a Y so we will continue on...."<<endl;
    }
    cout<<"Are you ready to play the game?(Y/N)"<<endl; //Option to play the game
    cout<<endl;
    cin>>Play;
    if(Play == 'Y' || Play == 'y') { //If statement to play the game
        do {
            cout<<"Current Balance: $"<<Money<<endl; //Money Variable description
            cout<<endl;
            cout<<"You have the choice of attending college or not."<<endl;
            cout<<"By choosing college you have the possibility to earn a better job and a higher pay rate."<<endl;
            cout<<"Warning: If you choose the college route you will be put in debt and must pay it back over the course of the game."<<endl; 
            cout<<endl;
            cout<<"Do you want to attend college?(Y/N)"<<endl;
            cout<<endl;
            cin>>College;
            cout<<endl;
            if(College == 'Y' || College == 'y') { //PLayer choice in game
                cout<<"You take $40000 of loans for college"<<endl;
                Money += -40000;
                cout<<"Current Balance: $"<<Money<<endl;
                cout<<"Job Hunt"<<endl<<endl;
                cout<<"Pick a number between 1 and 6 to determine your job and pay rate."<<endl;
                cin>>Job;
                cout<<endl;
                if(Job>=1 && Job<=6) {
                    switch(Job) //Random choice of jobs the player can choose from
                    {
                        case 1: cout<<"You have chosen:"<<endl;
                                PayDay=30000;
                                cout<<"Hair Stylist\t\tPay Rate: $"<<PayDay<<endl;
                                cout<<endl;
                                break;
                        case 2: cout<<"You have chosen:"<<endl;
                                PayDay=70000;
                                cout<<"Accountant\t\tPay Rate: $"<<PayDay<<endl;
                                cout<<endl;
                                break;
                        case 3: cout<<"You have chosen:"<<endl;
                                PayDay=60000;
                                cout<<"Athlete\t\tPay Rate: $"<<PayDay<<endl;
                                cout<<endl;
                                break;
                        case 4: cout<<"You have chosen:"<<endl;
                                PayDay=40000;
                                cout<<"Teacher\t\tPay Rate: $"<<PayDay<<endl;
                                cout<<endl;
                                break;
                        case 5: cout<<"You have chosen:"<<endl;
                                PayDay=30000;
                                cout<<"Mechanic\t\tPay Rate: $"<<PayDay<<endl;
                                cout<<endl;
                                break;
                        case 6: cout<<"You have chosen:"<<endl;
                                PayDay=100000;
                                cout<<"Doctor\t\tPay Rate: $"<<PayDay<<endl;
                                cout<<endl;
                                break;
                    }
                }
                else {
                    cout<<"INVALID OPTION"<<endl;
                    cout<<"Restart the game in order to continue."<<endl;
                    cout<<endl;
                }
            }
            else {
                cout<<"You decide to skip college and to search for a job."<<endl;
                cout<<"Pick a number between 1 and 3 to determine your job and pay rate."<<endl;
                cin>>Job;
                cout<<endl;
                if(Job>=1 && Job<=3) { //Player choice of jobs...Randomized
                    switch(Job)
                    {
                        case 1: cout<<"You have chosen:"<<endl;
                                PayDay=30000;
                                cout<<"Mechanic\t\tPay Rate: $"<<PayDay<<endl;
                                cout<<endl;
                                break;
                        case 2: cout<<"You have chosen:"<<endl;
                                PayDay=30000;
                                cout<<"Hair Stylist\t\tPay Rate: $"<<PayDay<<endl;
                                cout<<endl;
                                break;
                        case 3: cout<<"You have chosen:"<<endl;
                                PayDay=40000;
                                cout<<"Teacher\t\tPay Rate: $"<<PayDay<<endl;
                                cout<<endl;
                                break;
                    }   
                }
                else {
                    cout<<"INVALID OPTION"<<endl;
                    cout<<"Restart the game in order to continue."<<endl;
                    cout<<endl;
                }
            }
            cont(NA);
            cin>>dummy;
            cout<<"The game will now begin for you to spin."<<endl;
            do { //As long as Moves is less than 50 spaces then it will loop
                cout<<"Current amount of money: $"<<Money<<endl;
                cout<<endl;
                cout<<"Current amount of Life Cards: "<<card<<endl;
                cout<<endl;
                cont(NA);
                cin>>dummy; //Emulate Press any key to continue by pausing the program.
                cout<<endl;
                Spin = rand() % 3 + 1; //Random Number Generator between 1 and 3
                Moves += Spin;
                cout<<"You spun a "<<Spin<<endl;
                cout<<endl;
                cont(NA);
                cin>>dummy;
                cout<<"You moved "<<Spin<<" spaces forward."<<endl;
                cout<<"You are now on space "<<Moves<<endl;
                cout<<endl;
                cont(NA);
                cin>>dummy;
                switch(Moves) //Moves determine scenarios
                {
                     case 1: cout<<"Get elected to youth committee"<<endl;
                            cout<<"You earned $5000"<<endl;
                            Money += 5000;
                            cout<<endl;
                            break;
                    case 2: cout<<"You are caught in a car accident."<<endl;
                            cout<<"You must pay repairs of about $2000"<<endl;
                            Money -= 2000;
                            cout<<endl;
                            break;
                    case 3: cout<<"PAYDAY!"<<endl;
                            cout<<"You are paid $"<<PayDay<<endl;
                            Money += PayDay;
                            cout<<endl;
                            break;
                    case 4: cout<<"Rent apartment."<<endl;
                            cout<<"You pay $2000"<<endl;
                            Money -= 2000;
                            cout<<endl;
                            break;
                    case 5: cout<<"You won a raffle."<<endl;
                            cout<<"You earned $3000"<<endl;
                            Money += 3000;
                            cout<<endl;
                            cout<<"You earned the Home Improvement Life Card"<<endl;
                            cout<<endl;
                            LifeC.push_back("Home Improvement");
                            card += 1;
                            break;
                    case 6: cout<<"Get a bonus for outstanding work."<<endl;
                            cout<<"You earned $500"<<endl;
                            Money += 500;
                            cout<<endl;
                            break;
                    case 7: cout<<"You loaned money to a friend."<<endl;
                            cout<<"You loaned $1000"<<endl;
                            Money -= 1000;
                            cout<<endl;
                            break;
                    case 8: cout<<"PAYDAY!"<<endl;
                            cout<<"You are paid $"<<PayDay<<endl;
                            Money += PayDay;
                            cout<<endl;
                            break;
                    case 9: cout<<"You lost your paycheck."<<endl;
                            cout<<"You lost $"<<PayDay<<endl;
                            Money -= PayDay;
                            cout<<endl;
                            break;
                    case 10: cout<<"Get a bonus for outstanding work."<<endl;
                            cout<<"You earned $500"<<endl;
                            Money += 500;
                            cout<<endl;
                            cout<<"You earned the Sailing Life Card"<<endl;
                            cout<<endl;
                            LifeC.push_back("Sailing");
                            card += 1;
                            break;
                    case 11: cout<<"Celebrate a friends birthday."<<endl;
                            cout<<"You paid $1000"<<endl;
                            Money -= 1000;
                            cout<<endl;
                            break;
                    case 12: cout<<"A fire occurs in your place of living"<<endl;
                            cout<<"You must pay repairs of about $7000"<<endl;
                            Money -= 7000;
                            cout<<endl;
                            break;
                    case 13: cout<<"You sprained your ankle."<<endl;
                            cout<<"You pay the hospital fees of $6000"<<endl;
                            Money -= 6000;
                            cout<<endl;
                            break;
                    case 14: cout<<"PAYDAY!"<<endl;
                            cout<<"You are paid $"<<PayDay<<endl;
                            Money += PayDay;
                            cout<<endl;
                            break;
                    case 15: cout<<"You scratched a lotto ticket."<<endl;
                            cout<<"You won $4000"<<endl;
                            Money += 4000;
                            cout<<endl;
                            cout<<"You earned the Artist Life Card"<<endl;
                            cout<<endl;
                            LifeC.push_back("Artist");
                            card += 1;
                            break;
                    case 16: cout<<"You decide to renovate your home."<<endl;
                            cout<<"You paid $8000"<<endl;
                            Money -= 8000;
                            cout<<endl;
                            break;
                    case 17: cout<<"Your credit card was stolen!"<<endl;
                            cout<<"You lost $6000"<<endl;
                            Money -= 6000;
                            cout<<endl;
                            break;
                    case 18: cout<<"PAYDAY!"<<endl;
                            cout<<"You are paid $"<<PayDay<<endl;
                            Money += PayDay;
                            cout<<endl;
                            break;
                    case 19: cout<<"You buy a new computer."<<endl;
                            cout<<"You paid $2000"<<endl;
                            Money -= 2000;
                            cout<<endl;
                            break;
                    case 20: cout<<"It's your birthday!"<<endl;
                            cout<<"You were gifted a total of $3000"<<endl;
                            Money += 3000;
                            cout<<endl;
                            cout<<"You earned the Dancer Life Card"<<endl;
                            cout<<endl;
                            LifeC.push_back("Dancer");
                            card += 1;
                            break;
                    case 21: cout<<"You bought a bike"<<endl;
                            cout<<"You paid $1000"<<endl;
                            Money -= 1000;
                            cout<<endl;
                            break;
                    case 22: cout<<"Your home was broken into!"<<endl;
                            cout<<"You were robbed to the amount of $4000"<<endl;
                            Money -= 4000;
                            cout<<endl;
                            break;
                    case 23: cout<<"PAYDAY!"<<endl;
                            cout<<"You are paid $"<<PayDay<<endl;
                            Money += PayDay;
                            cout<<endl;
                            break;
                    case 24: cout<<"You were sent back your tax return."<<endl;
                            cout<<"You received $3000"<<endl;
                            Money += 3000;
                            cout<<endl;
                            break;
                    case 25: cout<<"You bought a new phone."<<endl;
                            cout<<"You paid $1000"<<endl;
                            Money -= 1000;
                            cout<<endl;
                            cout<<"You earned the Wrote A Novel Life Card"<<endl;
                            cout<<endl;
                            LifeC.push_back("Wrote A Novel");
                            card += 1;
                            break;
                    case 26: cout<<"You win in a TV game show!"<<endl;
                            cout<<"You won $2000"<<endl;
                            Money += 2000;
                            cout<<endl;
                            break;
                    case 27: cout<<"You but a game console."<<endl;
                            cout<<"You paid $500"<<endl;
                            Money -= 500;
                            cout<<endl;
                            break;
                    case 28: cout<<"PAYDAY!"<<endl;
                            cout<<"You are paid $"<<PayDay<<endl;
                            Money += PayDay;
                            cout<<endl;
                            break;
                    case 29: cout<<"Your home burned down!"<<endl;
                            cout<<"You lost $9000"<<endl;
                            Money -= 9000;
                            cout<<endl;
                            break;
                    case 30: //Fail-Safe in case the player manages to spin over 30 spaces
                    case 31:
                    case 32:
                    case 33:
                    case 34:
                    case 35:
                    case 36: 
                            cout<<"You have reached the end!"<<endl;
                            cout<<endl;
                            cout<<"You have decided to retire."<<endl;
                            cout<<"You retired with a savings of $"<<Money<<endl;
                            cout<<endl;
                            cout<<"You ended the game with these Life Cards"<<endl;
                            for(int i=0;i<card;i++) {
                                cout<<LifeC[i]<<endl;
                            }
                            cout<<"CONGRATULATIONS!"<<endl;
                            cout<<"YOU HAVE FINISHED THE GAME OF LIFE!"<<endl;
                            cout<<endl; //Ending of scenarios

                }
            }while (Moves<30);
            PlayA(Play);
            Moves = 0;
            Money = 0;
        } while(Play == 'Y' || Play == 'y');
        cout<<"Thanks for playing the Game Of Life!"<<endl;
    }
    return 0;
}
void cont(int Press) {
    cout<<"Press any key then [Enter] to continue."<<endl;
    cout<<endl;
}
void rules(char Ans) {
    cout<<"The rules are simple, the player is given the choice of either choosing to go to"<<endl; //Rules
    cout<<"college or to immediately get a job. Afterwards, the player must spin the wheel to"<<endl;
    cout<<"move within 1-3 spaces of a total of 30 spaces spread across the board. As the"<<endl;
    cout<<"player moves throughout the board, they will come across different scenarios that"<<endl;
    cout<<"can either benefit the player or give them a disadvantage until they reach the end"<<endl;
    cout<<endl;    
}
void intro() {
    cout<<"Welcome to the Game Of Life!"<<endl; //Introduction
    cout<<endl;
    cout<<"Throughout the game, the player is tasked with moving through several"<<endl; //Description
    cout<<"tiles in order to amount as much money as they can before they must retire."<<endl;
    cout<<"While there is no clear way to win the Game Of Life, it is best for the player"<<endl;
    cout<<"to slowly build up their money through several means as the game progresses."<<endl;
    cout<<endl;    
}
bool PlayA(char& YN) {
    cout<<"Do you want to play again?"<<endl;
    cin>>YN;
    return YN;
}