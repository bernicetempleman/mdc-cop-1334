// Bernice Templeman
// ICW- streams
// 10/15/2014

//Write a program that will read data from RandomData.txt
//and determine the max & min number in the data set.
// Display your findings

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{

    const int MIN = 600; //fake min & max
    const int MAX = 0;

    string filePath;
    ifstream myFile;
    int number, maxNum, minNum;

    //ask user
   // myFile.open(filePath.c_str());
   myFile.open("RandomData.txt");

    //defensive programming
    if (!myFile)
    {
        cout << "error";
    }

    minNum = MIN;
    maxNum = MAX;
    while (myFile >>number)
    {
        //determine min or max
        if (number > maxNum)
        {
            maxNum = number;
        }
        if (number < minNum)
        {
               minNum = number;
        }
    }
    //close the file
    cout << "MAX : " << maxNum << endl;
    cout << "MIN : " << minNum << endl;

    return 0;
}

