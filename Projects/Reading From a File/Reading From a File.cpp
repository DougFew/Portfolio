/*
Douglas Few
IT 312
Final Project Building Block Four (Reading From a File)
February 8, 2023
*/


#include <iostream>
#include <fstream>  // ifstream is included in the fstream library, so we must include it
#include <string>  // without this, getline will not work

using namespace std;

int main()
{
	string farkleRules;  // this initializes a string variable named farkleRules, which will store the contents of each line of the text file

	ifstream ReadRules("farkleRules.txt");  // this function reads the contents of farkleRules.txt

	while (getline (ReadRules, farkleRules))  // this while loop reads each line of the text file and stores that line in the farkleRules variable
	{
		cout << farkleRules << endl;  // this part of the loop simply prints the current contents of farkleRules, then drops to the next line
	}

	return 0;
}

