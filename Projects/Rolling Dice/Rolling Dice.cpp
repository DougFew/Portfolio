
/*
Douglas Few
January 27, 2023
IT-312
Final Project Building Block One: Rolling Dice
*/
#include <iostream>
#include <random>

using namespace std;

void RollDice(int userGuess) /*this function rolls 2 dice and compares the sum of those dice to the user's guess.
                              It is a void function because for the purpose of this assignment, it did not need to return a value*/ 
{
    int tries = 0, dieOne, dieTwo, dieTotal;  

    random_device rd;  // the following three lines are what allows the program to generate random integers
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 6);  // this line sets the number distribution for the random numbers to be between 1 and 6

    do  // this do-while loop will roll two dice and compare the sum to the user's guess
    {
        dieOne = dis(gen); // this sets the value of the first die to a random integer
        dieTwo = dis(gen); // this sets the value of the second die to a random integer
        dieTotal = dieOne + dieTwo; // this calculates the total of the two dice
        
        cout << "Die one is " << dieOne << " and die two is " << dieTwo << endl;
        cout << "Die total is " << dieTotal << endl << endl;

        tries = tries++;

    } while (dieTotal != userGuess); // this tells the loop to continue so long as the die total does NOT equal the user's guess

    
    cout << "The dice were rolled " << tries << " times." << endl;
    
}

int main()
{
    int userGuess = 1;  // I initialize the userGuess variable to 1 so the following while loop will work
    
    

    while (userGuess < 2 || userGuess > 12)  // this while loop will continue until the user inputs a valid guess
    {
        cout << "Input a number between 2 and 12: ";
        cin >> userGuess;

        if (userGuess < 2 || userGuess > 12)
        {
            cout << "That is an invalid guess, please try again." << endl << endl;  // this lets the user know that their guess was invalid
        }
        else
        {
            break; // this breaks from the while loop so the program can continue
        }
    }

    RollDice(userGuess); // this calls the RollDice function and passes the userGuess variable

    return 0;
}

