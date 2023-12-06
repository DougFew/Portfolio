
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

int add(int num1, int num2)
{
    int newNum = num1 + num2;
    return newNum;
}
int subtract(int num1, int num2)
{
    int newNum = num1 - num2;
    return newNum;
}
int multiply(int num1, int num2)
{
    int newNum = num1 * num2;
    return newNum;
}
double divide(double num1, double num2)
{
    double newNum = num1 / num2;
    return newNum;
}

int main()
{

    string userInput;
    int num1;
    int num2;
    bool redo = false;

    cout << "Welcome to my calculator. Would you like to add, subtract, multiply or divide?" << endl;    

    do
    {
        cin >> userInput;
        transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) { return tolower(c); });

        if (userInput == "add")
        {
            cout << "Input two numbers: " << endl;
            cin >> num1 >> num2;
            cout << "The sum of " << num1 << " and " << num2 << " is: " << add(num1, num2);
        }
        else if (userInput == "subtract")
        {
            cout << "Input two numbers: " << endl;
            cin >> num1 >> num2;
            cout << "The difference between " << num1 << " and " << num2 << " is: " << subtract(num1, num2);
        }
        else if (userInput == "multiply")
        {
            cout << "Input two numbers: " << endl;
            cin >> num1 >> num2;
            cout << "The product of " << num1 << " and " << num2 << " is: " << multiply(num1, num2);
        }
        else if (userInput == "divide")
        {
            cout << "Input two numbers: " << endl;
            cin >> num1 >> num2;
            cout << "The quotient of " << num1 << " and " << num2 << " is: " << divide(num1, num2);
        }
        else
        {
            cout << "Not a valid option. Please make a valid selection." << endl;
            redo = true;
        }
    } while (redo == true);
    
    

    return 0;
}
