#include <iostream>

using namespace std;

int main()
{

    int number = 0;    //
    int highest = 0;   //
    int lowest = 0;    //

    cout << "Enter a positive integer or -99 to quit: ";
    cin >>number;

    while ( number > -99)
    {
        if (highest < number)
            highest = number;
        if (lowest > number)
            lowest = number;
        cout << "Enter a positive integer or -99 to quit: ";
        cin >>number;
    }

    cout << " The highest number: " << highest << endl;
    cout << "The lowest number : " << lowest << endl;
    return 0;

}
