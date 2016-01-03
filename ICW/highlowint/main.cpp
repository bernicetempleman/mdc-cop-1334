#include <iostream>

using namespace std;

int main()
{

    const int SENTINNEL = -99;

    int number = 0;    //
    int highest = 0;   //
    int lowest = 0;    //

    cout << "Enter a positive integer or -99 to quit: ";
    cin >>number;

    if (number == SENTINNEL)
            cout <<"thank you"<< endl;
    else
    {
    highest = lowest = number;

    while ( number != SENTINNEL)
    {

        cout << "Enter a positive integer or -99 to quit: ";
        cin >>number;
        if (number == SENTINNEL)
            cout <<"thank you"<< endl;
        else
        {

            if (highest < number)
                highest = number;
            if (lowest > number)
                lowest = number;
        }
    }

    cout << "The highest number is: " << highest << endl;
    cout << "The lowest number is: " << lowest << endl;
    }

    return 0;


}
