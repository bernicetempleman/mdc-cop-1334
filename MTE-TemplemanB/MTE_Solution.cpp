#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int dayOfBirth;
    int monthOfBirth;
    char userAns;
    unsigned seed = time(0);
    srand(seed);

    do
    {
        // get the day
        dayOfBirth = 1 + rand() % 31;

        // get month of birth
        monthOfBirth = 1 + rand() % 12;

        cout << "Person born on "
             << monthOfBirth
             << "/"
             << dayOfBirth
             << " is : ";


        switch (monthOfBirth)
        {
            case 1:
                if (dayOfBirth <=19)
                    cout << "Capricorn" << endl;
                else
                    cout << "Aquarius" << endl;
                break;
            case 2:
                if (dayOfBirth <=18)
                    cout << "Aquarius" << endl;
                else
                    cout << "Pisces" << endl;
                break;
            case 3:
                if (dayOfBirth <=20)
                    cout << "Pisces" << endl;
                else
                    cout << "Aries" << endl;
                break;
            case 4:
                if (dayOfBirth <=19)
                    cout << "Aries" << endl;
                else
                    cout << "Taurus" << endl;
                break;
            case 5:
                if (dayOfBirth <=20)
                    cout << "Taurus" << endl;
                else
                    cout << "Gemini" << endl;
                break;
            case 6:
                if (dayOfBirth <=21)
                    cout << "Gemini" << endl;
                else
                    cout << "Cancer" << endl;
                break;
            case 7:
                if (dayOfBirth <=22)
                    cout << "Cancer" << endl;
                else
                    cout << "Leo" << endl;
                break;
            case 8:
                if (dayOfBirth <=22)
                    cout << "Leo" << endl;
                else
                    cout << "Virgo" << endl;
                break;
            case 9:
                if (dayOfBirth <=22)
                    cout << "Virgo" << endl;
                else
                    cout << "Libra" << endl;
                break;
            case 10:
                if (dayOfBirth <=22)
                    cout << "Libra" << endl;
                else
                    cout << "Scorpio" << endl;
                break;
            case 11:
                if (dayOfBirth <=21)
                    cout << "Scorpio" << endl;
                else
                    cout << "Sagittarius" << endl;
                break;
            case 12:
                if (dayOfBirth <=21)
                    cout << "Sagittarius" << endl;
                else
                    cout << "Capricorn" << endl;
                break;
        }
     cout << "Would you like to try another month/date? <Y/N>: ";
     cin >> userAns;
    }while (userAns == 'y' && userAns!='Y');
    return 0;
}
