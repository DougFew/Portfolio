#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int digits;
    cout << "Enter the number of digits to print: ";
    cin >> digits;

    // Set the maximum number of digits to 15 (C++'s limit for float precision)
    if (digits > 15) {
        digits = 15;
    }

    double pi = round(M_PI * pow(10, digits)) / pow(10, digits);

    cout << setprecision(digits + 2) << "Pi to " << digits << " decimal places: " << pi << endl;

    return 0;
}