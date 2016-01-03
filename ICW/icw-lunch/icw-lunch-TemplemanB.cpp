//Bernice Templeman
// Frank

#include <iostream>

using namespace std;

void displayMenu(int &);
double totalSpentWeek(double []);
double mostExpensive(double []);
double leastExpensive(double []);
double aveSpending(double []);
void displayAll(double []);

int main()
{

    double  lunchArray[] = {17.65, 21.88, 7.80, 12.15, 22.75};
    int userChoice;

do
{

    displayMenu(userChoice);
    switch(userChoice)
    {
    case 1:
        //total amount spent entire week
        cout << "Total: " << totalSpentWeek( lunchArray) << endl;
        break;

    case 2:
        //most expensive
        cout << "Most Expensive:" <<mostExpensive(lunchArray)<< endl;
        break;

    case 3:
        //least expensive
        cout <<"Least Expensive:" << leastExpensive(lunchArray)<< endl;
        break;

    case 4:
        //Average spending
        cout << "Average: "<<aveSpending(lunchArray) << endl;
        break;

    case 5:
        //display all days
        displayAll(lunchArray);
        break;

    case 6:
        //exit
        break;

    default:
        cout << "Please enter 1, 2, 3, 4, 5,or 6 only!";

    }
  }while(userChoice !=6);

    return 0;
}



//display menu
void displayMenu(int &userChoice)
{
    cout << "Menu:" << endl;
    cout << "_________" << endl;
    cout << "1. Total amount spent the entire week " << endl;
    cout << "2. Most expensive" << endl;
    cout << "3. Least expensive" << endl;
    cout << "4. Average Spending" << endl;
    cout << "5. Display All Days" << endl;
    cout << "6. exit" << endl;
    cout << "Enter Your Choice: ";
    cin >> userChoice;
}

void displayAll(double lunchArray[])
{
    for (int i = 0; i <5; i++)
    {
        cout <<lunchArray[i] << endl;
    }
}

double totalSpentWeek(double lunchArray[])
{
    double total = 0;

    for (int i = 0; i <5; i++)
    {
        total = total+lunchArray[i];
    }

    return total;
}

double mostExpensive(double lunchArray[])
{
 double price;
 price = lunchArray[0];

    for (int i = 0; i <5; i++)
    {
        if (lunchArray[i] > price)
            price = lunchArray[i];
    }

    return price;
}

double leastExpensive(double lunchArray[])
{
 double price;
 price = lunchArray[0];

    for (int i = 0; i <5; i++)
    {
        if (lunchArray[i] < price)
            price = lunchArray[i];
    }

    return price;
}

double aveSpending(double lunchArray[])
{
double ave;
    double total = 0;

    for (int i = 0; i <5; i++)
    {
        total = total+lunchArray[i];
    }

    ave = total/5;

    return ave;

}



