// LoopingArrays.cpp : This program loops through to create an array based on user input and then 
// sorts the array in order of smallest integer to largest.  Format the code following the code
// styling document.

/*
Douglas Few
IT 312
January 26, 2023
Looping Through Arrays
*/

#include <iostream>
#include <cstdlib> // added a space after this line

using namespace std;

void main()
{
	int loopedArray[10], t; // added a space after this line, also changed the name of the array to be more descriptive

	for (int x = 0; x < 10; x++) // as a personal preference, I dropped the first curly brace down to the next line
	{
		cout << "Enter Integer No. " << x + 1 << " : " << endl;
		cin >> loopedArray[x];  
	} // added a space after this line
	
	for (int x = 0; x < 10; x++) 
	{
		for (int y = 0; y < 9; y++) 
		{
			if (loopedArray[y] > loopedArray[y + 1]) 
			{
				t = loopedArray[y];
				loopedArray[y] = loopedArray[y + 1];
				loopedArray[y + 1] = t;
			}
		}
	} // added a space after this line
	
	cout << "Array in ascending order is : "; // added a space after this line
	
	for (int x = 0; x < 10; x++)
	{
		cout << endl << loopedArray[x];  // nested this line within curly braces
	} // added a space after this line		
	
	return;
}