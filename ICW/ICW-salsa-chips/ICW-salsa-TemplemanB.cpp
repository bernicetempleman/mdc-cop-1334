//Bernice Templeman

/*Team Assignment: Chips and Salsa

Write a program that lets a maker of chips and salsa
keep track of sales for five different types of salsa:
mild ($2),
medium ($2),
sweet ($3),
hot ($4), and
zesty ($5).

The program should use 2 parallel 5-element arrays:
an array of strings that holds the five salsa names and
an array of integers that holds the number of jars sold during the past month for each salsa type.

The salsa names should be stored using the initialization list at the time the array is created.

The program should prompt the user to enter the number of jars sold for each type.

Once this sales data has been entered,
the program should produce a report that
displays sales for each salsa type,
 total sales,
 and the names of the highest selling and
 lowest selling products.

Input validation: Do not accept negative values for number of jars sold

*/

#include <iostream>
#include <iomanip>

using namespace std;

void getSales(int[], const string[], double[],double[], int );
void displayReport(int[], const string[], double[], int );

int main()
{
    const int SIZE = 5;         // size of array

    // set up parallel arrays
    //an array of strings that holds the five salsa names
    string  salsaName[SIZE]   = {"mild", "medium", "sweet", "hot", "zesty"};

    //array for salsa prices
    double price[SIZE] = {2.00,2.00,3.00,4.00,5.00};

    //an array of integers that holds the number of jars sold during the past month for each salsa type.
    int  jarsSold[SIZE];

    //array for total sales of each salsa
    double sales[SIZE];

    //get sales
    getSales(jarsSold, salsaName, price, sales, SIZE);

    //display report
    displayReport(jarsSold, salsaName, price, SIZE);

    return 0;
}


//The program should prompt the user to enter the number of jars sold for each type.
void getSales(int jars[], const string salsaName[], double price[], double sales[],int size)
{
    int n;         // temporary number to hold jar number input
    int flag = 0;  //flag for correct input

    for (int i = 0; i < size; i++)
    {
        //check for positive input for each salsa
        do{
            cout << "Please enter a positive number of jars sold for "
                << salsaName[i]
                << " :";
            cin >> n;

            if (cin.good())
            {
                if (n < 0)
                {
                    cout << "Negative.";
                    flag = 0;
                }
                else
                {
                    //cout << "Positive.";
                    flag = 1;}
                }
            else
            {
                cout << "Not an integer.";
                cin.clear();
                cin.ignore();
                flag = 0;
            }
        }while ((flag ==0) || n < 0);
        jars[i] = n;
        sales[i] = jars[i] * price[i];

        //no negative numbers
    }//end for
}
//displays sales for each salsa type,
// total sales,
// and the names of the highest selling and
// lowest selling products.
void displayReport(int jars[], const string salsaName[], double price[], int size)
{
    double totalSales= 0;
    int highestSelling = 0;
    int lowestSelling = 0;

    cout << endl;
    for (int i = 0; i < size; i++)
    {

        cout << "Sales: "
        << setw(11)
        << salsaName[i]
        << " : "
        << jars[i]
        << " jars : Total Sales $"
        << jars[i]* price[i]<< endl;

        totalSales = totalSales + (jars[i]* price[i]);

        //find highest & lowest selling
        if (jars[highestSelling] <=jars[i])
        {
            highestSelling = i;
        }

        if (jars[i] < jars[lowestSelling])
        {
            lowestSelling = i;
        }
    }//end for loop

    //display results
    cout <<endl;
    cout << "TotalSales: $"<< totalSales <<endl;
    cout << "Highest Selling: "<< salsaName[highestSelling] << endl;
    cout << "Lowest Selling: " << salsaName[lowestSelling]<<endl;
}
