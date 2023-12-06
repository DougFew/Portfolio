// Overloading.cpp : This code contains five errors before it will work as desired.  Find those errors, 
// document a description of the errors and their fix, and fix them.  Try using the debugger to 
// step through the program to find the bugs.  As you step through, take notice of the information
// you can see.  
//

/*
Douglas Few
IT 312
Overloading.cpp
February 7, 2023
*/

#include <cstdlib>
#include <iostream>

using namespace std;

int add(int, int);
double add(double, double);

int main()
{
	int a, b, x;
	double c, d, y;  // changed float to double because function is of type double

	cout << "Enter two integers\n";
	cin >> a >> b;
	x = add(a, b);  // changed c to b
	cout << "Sum of integers: " << x << endl;

	cout << "Enter two doubles\n";
	cin >> c >> d;
	y = add(c, d);  // changed parameters to c and d
	cout << "Sum of doubles: " << y << endl;

	return 0;
}

int add(int a, int b)
{
	int sum;
	sum = a + b;
	return sum;  // added return sum
}

double add(double a, double b)
{
	double sum;
	sum = a + b;
	return sum;  //  added a semicolon to the end of this line
}