/*
Douglas Few
IT 312
February 22, 2023
Final Project -- Farkle
*/



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

using namespace std;

class Player  // this player class will be used to create player objects based on user input
{
public:
    string name;  // this string will store the player's name
    int score = 0;    // this string will store the player's score
};

class Dice  // this dice class will be used to create the dice set and add them to an array
{
public:    
    int value = 1;  // the dice value is initialized to 1
    bool reroll = true;  // this boolean determines if the die will be rerolled or not
};

void RollDice(Dice* Dice, int size)  // this function is called whenever dice need to be rolled
{
       

    random_device rd;  // the following lines set up the random number generator
    mt19937 roll(rd());
    uniform_int_distribution<> dis(1, 6);  // this line sets the number distribution to be between 1 and 6
   

    for (int i = 0; i < 6; i++)  // this for loop iterates through the Dice[] array and only rolls dice where bool reroll equals true
    {
        if (Dice[i].reroll == true)
        {
            Dice[i].value = dis(roll);        
        }
        else
        {
            continue;
        }
        
    }    
}

void ShowDice(Dice* Dice, int size)  // this function is called whenever the rolled dice should be displayed to the user
{
    for (int i = 0; i < 6; i++)  // this for loop iterates through the Dice[] array and displays the value of each die
    {
        std::cout << "Die " << i+1 << ": " << Dice[i].value << endl;
    }    
}

int CheckForTriples(Dice* Dice, int size)  // this function checks the Dice array for any triple values currently in the array
{
    int triples = -1;  // this value is initialized to -1 and will be checked later in the function
    
    for (int i = 0; i < 6; i++)  // this for loop iterates through the 6 possible values of each die
    {
        int count = 0;  
        for (int j = 0; j < size; j++)  // this imbedded for loop iterates through the Dice[] array and checks each value
        {
            if (Dice[j].value == i)  // if the value of the current die matches the value being checked in the outer loop, the count variable is increased by one
            {
                count++;
            }
        }
        if (count >= 3)  // if count is greater than or equal to 3, triples is set to i and the loop ends
        {
            triples = i;
            break;
        }
    }

    if (triples == 1)  // if triples equals 1, a value of 1000 is returned because that means there were 3 ones.
    {
        return 1000;
    }
    else if (triples != -1) // if triples is anything other than 1 or -1, the value of triples times 100 is returned
    {
        return (triples * 100);
    }
    else // if triples still equals -1, no triples were rolled and 0 is returned
    {
        return 0;
    }
}

int CheckForScore(Dice* Dice, int size)  // this function checks for any scoring dice besides the triples
{
    int score = 0;
    for (int i = 0; i < size; i++)  // this for loop iterates through the Dice[] array to check for any dice with values of 1 or 5
    {
        if (Dice[i].value == 1)
        {
            score = score + 100;  // if the value of the die in the current position equals 1, score is increased by 100
        }
        else if (Dice[i].value == 5)
        {
            score = score + 50;  // if the value of the die in the current position equals 5, score is increased by 50
        }
    }

    return score;  // the value of score is returned
}

bool CheckForFarkle(Dice* Dice, int size)  // this function checks for a farkle and returns either true or false
{
    int ones = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0;  // these values are initialized to zero and add up by 1 each time an instance of that number is rolled
    bool onesOrFives = true, triples = true;
    
    for (int j = 0; j < size; j++)  // this for loop iterates through the Dice[] array and counts each time an instance of each number is rolled
    {
        if (Dice[j].value == 1)
        {
            ones = ones++;
        }
        else if (Dice[j].value == 2)
        {
            twos = twos++;
        }
        else if (Dice[j].value == 3)
        {
            threes = threes++;
        }
        else if (Dice[j].value == 4)
        {
            fours = fours++;
        }
        else if (Dice[j].value == 5)
        {
            fives = fives++;
        }
        else if (Dice[j].value == 6)
        {
            sixes = sixes++;
        }
    }

    if (ones == 0 && fives == 0)  // if there were no ones AND no fives, the onesOrFives variable is set to false
    {
        onesOrFives = false;
    }
    if (ones < 3 || twos < 3 || threes < 3 || fours < 3 || fives < 3 || sixes < 3)  // if there is no instance of any number being rolled three times, triples is set to false
    {
        triples = false;
    }

    if (onesOrFives == false && triples == false)  // if both variables are false, a farkle occured
    {
        return true;
    }
    else // if either variable is true, a farkle did not occur and false is returned
    {
        return false;
    }
}

void Rules()  // this function displays the rules for the game
{
    string farkleRules;

    ifstream ReadRules("farkleRules.txt");  // this line declares a variable that holds the value of the farkleRules.txt document

    while (getline(ReadRules, farkleRules))  // this while loop reads each line of the text file and stores that line in the farkleRules variable
    {
        std::cout << farkleRules << endl;  // this part of the loop simply prints the current contents of farkleRules, then drops to the next line
    }
}

int main()
{
    int choice, playerNum = 0, triples, points = 0; 
    char playAgain;  // this char variable is used to ask the player if they would like to reroll any dice
    
    vector<Player> players;  // this vector is used to store the objects created from the Player class
    
    Dice DiceSet[6];  // this array is used to store the objects from the Dice class
    const int size = 6;  // this int stores the constant value of 6, the size of the DiceSet array

    std::cout << "Welcome to Farkle! Press (1) to play, press (2) to display the rules: ";
    
    do  // here, the user has the option to either begin the game or view the rules.  this loops until the user presses 1 to begin the game
    {
        cin >> choice;
        switch (choice)
        {
        case 1:            
            break; // if the user selects 1, breaks from loop to begin game
        case 2:
            Rules(); // if the user selects 2, calls the Rules() function which displays the rules
            std::cout << endl << endl << "Press (1) if you are ready to play: "; // prompts the user to press 1 to begin the game
            continue;
        default:
            std::cout << "Invalid choice. Please press (1) to play or (2) to display the rules: "; // if an invalid selection is made, prompts the user for a valid selection
            continue;
        }
    } while (choice != 1);   

    std::cout << "How many players will there be? ";  // the user is asked how many players there will be

    do  // this loop repeats until the user inputs an interger of at least 2, ensuring there are at least 2 players
    {
        cin >> playerNum; 

        if (playerNum >= 2)
        {
            for (int i = 0; i < playerNum; i++)  // this for loop creates a player object based on how many players the user decided and adds them to the players vector
            {
                Player player;
                std::cout << "What is player " << i + 1 << "'s name? ";
                cin >> player.name;

                players.push_back(player);
            }
        }
        else
        {
            std::cout << "There must be at least 2 players." << endl; // if there are less than 2 players, the loop repeats
        }

    } while (playerNum < 2);
    
    

    for (int k = 0; k < 6; k++)  // this loop creates the dice objects and adds them the the DiceSet array
    {
        Dice die;
        DiceSet[k] = die;
    }
    

    while (true) // this while loop is the main code of the game, it repeats until the game ends
    {
        for (int j = 0; j < players.size(); j++)  // this for loop iterates through the number of players, indicating who's turn it is
        {
            RollDice(DiceSet, size);  // call the RollDice function, passing a pointer to the DiceSet array and the size of the array as arguments
            ShowDice(DiceSet, size);  // call the ShowDice function, passing a pointer to the DiceSet array and the size of the array as arguments
            bool farkle = CheckForFarkle(DiceSet, size);  // call the CheckForFarkle function, passing a pointer to the DiceSet array and the size of the array as arguments and stores the returned value into a variable called farkle
            
            if (farkle == true)  // if farkle is equal to true, this player's turn ends and they recieve no points
            {
                std::cout << players[j].name << " got a Farkle! No points this turn!" << endl;
                continue;
            }

            triples = CheckForTriples(DiceSet, size);  // call the CheckForTriples function, passing a pointer to the DiceSet array and the size of the array as arguments and stores the returned value into a variable called triples
            
            if (triples == 0)
            {
                points = CheckForScore(DiceSet, size); // if CheckForTriples returns as 0, call the CheckForScore function, passing a pointer to the DiceSet array and the size of the array as arguments and stores the returned value into a variable called score
            }
        
            

            if (players[j].score >= 10000)  // this if statement ends the game if the current player has a score of 10,000 or more
            {
                std::cout << players[j].name << " wins! Congratulations!" << endl;
                return 0;  // return 0 ends the program
            }
            else  // if the current player hasn't reached 10,000 points, they may roll again
            {
                std::cout << "Would " << players[j].name << " like to roll again? (y/n)  ";
                cin >> playAgain;
            }
                      
            
            
            while (true)  
            {
                if (playAgain == 'y')  // this if statement runs if the user chooses to reroll dice
                {
                    j--;  // j is subtracted by 1 to make sure the turn does not pass to the next player
                    
                    
                    for (int l = 0; l < 6; l++)  // this for loop iterates through the DiceSet array and asks the user if they'd like to reroll each die
                    {
                        char selectDieToReroll;
                        std::cout << "Would you like to reroll die " << l + 1 << "? (y/n)  ";  // this outputs the number of the current die in the array
                        cin >> selectDieToReroll;  // the user must input either 'y' or 'n' to decide if they want to reroll the current die

                        if (selectDieToReroll == 'y')  // if the user inputs 'y', the reroll value of the current die will be set to true
                        {
                            DiceSet[l].reroll = true;
                        }
                        else if (selectDieToReroll == 'n') // if the user inputs 'n', the reroll value of the current die will be set to false
                        {
                            DiceSet[l].reroll = false;                            
                        }
                    }
                    break;
                   
                }
                else if (playAgain == 'n') // this code block runs when the user decides to stop rerolling
                {         
                    players[j].score = players[j].score + triples + points; // this adds up the points accumulated by the user this turn, and adds it to their score
                    std::cout << players[j].name << "'s score is " << players[j].score << endl << endl; // this displays the user's name and score
                    break;
                }
                else  // this code runs if a valid response is not detected
                {
                    std::cout << "Not a valid response. Please press either 'y' or 'n': ";
                    cin >> playAgain;
                    continue;
                }
            }
                        
        }  
    }    
    
    return 0;
}

