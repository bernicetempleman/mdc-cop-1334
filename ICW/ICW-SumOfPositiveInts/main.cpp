/* Programmer   :   Bernice Templeman
/* Date         :   10/13/2014

/* Description  :
Write a program that will ask the user to enter
even positive (integers) numbers.
If the user  enters a negative number,
or an odd number,
the program needs to display an error message
and quit.
Otherwise, compute the sum of even numbers
and display it.

*/



#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int number;
    int sum = 0;

    cout << "Please enter even positive integers, -1 to quit: ";
    cin >> number;

    if ((number > 0)&& ((number % 2) == 0))
        {
            while ((number > 0)&& ((number % 2) == 0))
            {
                sum = sum + number;
                cout << "Please enter even positive integers, -1 to quit: ";
                cin >> number;
                if ((number < 0)|| ((number % 2) != 0))
                   cout << "You entered an invalid number: " << number<< endl;
            }
         cout<< "Sum of Even Positive numbers  = " << sum << endl;
        }
    else
    {
        cout << "You entered an invalid number." << endl;
    }
    return 0;
}
