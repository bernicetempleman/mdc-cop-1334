/* Programmer   : Bernice Templeman
 * Date         : 10/13/2014
 * MTE
 *
 * Description:
 You have been hired by the world famous celebrity astrologer Terry Nazon
 to help her create a program
 that given person’s day and month of birth
 will figure out person’s horoscope sign.

 She requested that this initial program
 automatically generates day and month and prints corresponding horoscope sign.
 The program then asks the user
 if they want to go again,
 and repeats the process until the user says that s/he is done.

 */

#include <iostream>
#include <ctime>     // time
#include <cstdlib>   // random function generator

using namespace std;

int main()
{
    const int MONTH_LOW = 1;    //low month range 1
    const int MONTH_HIGH = 12;  // high month range 12
    const int DAY_LOW = 1;      // low day range 1
    const int DAY_HIGH = 31;    // hight day range 31

    int month;
    int day;
    string sign;
    char next = 'Y';
    unsigned seed = time(0);   // get computer time

    while ((next == 'Y') || (next == 'y'))
    {

        srand( time( NULL ) );              // seed the random number generator

        //generate random month & day
        month = rand() % (MONTH_HIGH-MONTH_LOW + 1) + MONTH_LOW;
        day = rand() % (DAY_HIGH-DAY_LOW + 1) + DAY_LOW;

        //determine the sign based on month and day
        switch (month){
        case 1 :
            if (day <20)
            sign = "Capricorn";
            else
            sign = "Aquarius";
            break;

        case 2:
            if (day < 19)
                sign = "Aquarius";
            else
                sign = "Pisces";
            break;

        case 3:
            if (day < 21)
                sign = "Pisces";
            else
                sign = "Aries";
            break;

        case 4:
            if (day < 20 )
                sign = "Aries";
            else
                sign = "Taurus";
            break;

        case 5:
            if (day < 21)
                sign = "Taurus";
            else
                sign = "Gemini";
            break;

        case 6:
            if (day < 22)
                sign = "Gemini";
            else
                sign = "Cancer";
            break;

        case 7:
            if (day < 23)
                sign = "Cancer";
            else
                sign = "Leo";
            break;

        case 8:
            if (day <23)
                sign = "Leo";
            else
                sign = "Virgo";
            break;

        case 9:
            if (day < 23)
                sign = "Virgo";
            else
                sign = "Libra";
            break;

        case 10:
            if (day < 23)
                sign = "Libra";
            else
                sign = "Scorpio";
            break;

        case 11:
            if (day < 22)
                sign = "Scorpio";
            else
                sign = "Sagitarius";
            break;

        case 12:
            if (day < 22)
                sign = "Sagitarius";
            else
                sign = "Capricorn";
            break;
        //values other than 1-12 are error month
        default:
            sign = "Error";
            break;

        }
        //display the month, day & sign
        cout << "Person born on " << month << "/" << day << " is : " << sign << ". "<<endl;

        //ask if they want to continue
        cout << "Would you like to try another month/date? <Y/N>: ";
        cin >> next;

    }

    cout <<" thank you." << endl;

    return 0;
}
