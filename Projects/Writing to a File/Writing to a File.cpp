
/*
Douglas Few
IT 312
Writing to a File
February 7, 2023
*/


#include <fstream>  // this header is what makes reading and writing to files possible in c++
#include <iostream>


using namespace std;


class Player // this class is used to keep track of the name and current score of each player
{
public:
    string name;
    int score = 0;
    void getName();
    void getScore();
};

void Player::getName()  // this function sets the name of a created player object
{
    cout << "Enter your name:  ";
    cin >> name;    
}

void Player::getScore()  // this function sets the score of a player object
{    
    cin >> score;
}

int main()
{
    int playerNum = 0, roundNum = 0;  // these ints are used to set the number of players and number of rounds in the game
    ofstream Scores("scores.txt");    // this line creates a new text file named scores.txt 

    Player players_object[6];  // this is an array that will hold each player object created.  the max size is set to 6 currently, but can be increased

    do  // this do while loop will ask for the amount of players until a valid selection is made
    {
        cout << "How many players are there?  ";
        cin >> playerNum;


        if (playerNum <= 0)
        {
            cout << "You must have more than 0 players." << endl;
        }
        else if (playerNum > 6)
        {
            cout << "You may have a max of 6 players." << endl;
        }        

    } while (playerNum == 0 || playerNum > 6);

    do  // this do while loop will ask for the number of rounds until a valid selection is made
    {
        cout << "How many rounds will be played?  ";
        cin >> roundNum;
        if (roundNum <= 0)
        {
            cout << "There must be more than 0 rounds." << endl;
        }
    } while (roundNum == 0);

    int i; // this int i is created for the following for loops
    
    for (i = 0; i < playerNum; i++)  // this for loop creates a player object for however many players the user specifies, and then stores each object in the aforementioned array
    {
        players_object[i].getName();        
    }
       
    cout << endl << endl;
    
    int ii; // this int ii is created for the nested for loop

    for (i = 0; i < roundNum; i++)  // this for loops iterates through the number of rounds specified by the user
    {        
        Scores << "The results for round " << i+1 << " are: " << endl;  // this line writes to the scores.txt file, specifying what round each set of scores is for.

        for (ii = 0; ii < playerNum; ii++)  // this nested for loop iterates through player and collects their scores for the round
        {
            if (players_object[ii].name == "")  // this if statement checks if an index in the array is empty and, if it is, skips over it
            {
                continue;
            }
            
            cout << "What is " << players_object[ii].name << "'s score for round " << i+1 << "? ";
            players_object[ii].getScore();  // this calls the getScore function, which has the player input their score for that round
            Scores << players_object[ii].name << " had a score of " << players_object[ii].score << endl;  // this line writes the player's name and score for the current round to the scores.txt file            
        }

        cout << endl;
        Scores << endl << endl;
                
    }

    Scores.close(); // this line ensures that the text file is closed at the end of runtime
    return 0;
 }
