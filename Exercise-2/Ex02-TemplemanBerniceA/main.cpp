/* Programmer     :      Bernice Templeman
*  Exercise 2     :      Geometry Calculator
*  Date Due       :      October 2nd, 2014
*
*  Description:
*  Write a program that displays the following menu:
*
*  Geometry Calculator
*  1. Calculate the Area of a Circle
*  2. Calculate the Area of a Rectangle
*  3. Calculate the Area of a Triangle
*  4. Quit
*  Enter your choice (1-4):
*
*If the user enters 1,
the program should ask for the radius of the circle
and then display its area.
Use the following formula:
area = π(the square of r)
Use 3.14159 for π and the radius of the circle for r.

If the user enters 2,
the program should ask for the length and width of the rectangle
and then display the rectangle’s area.
Use the following formula:
area = length * width

If the user enters 3,
the program should ask for the length of the triangle’s base and its height,
and then display its area.
Use the following formula:
area = base * height * .5

If the user enters 4, the program should end.

• Input Validation:
Display an error message if the user enters a number outside the range of 1 through 4
when selecting an item from the menu.

Do not accept negative values for the
circle’s radius,
the rectangle’s length or width,
or the triangle’s base or height.

• Prompts, Output Labels, and Messages:
Besides the output specified above,
issue the following messages under the indicated situations:

o After calculating an area,
the program prints "The area is " followed by the calculated area.

o If the user enters an improper menu choice (1-4),
the program prints "The valid choices are 1 through 4. Run the program again and select one of those."

o If the user enters a negative radius,
the program prints "The radius cannot be less than zero."

o If the user enters a negative value for height or base,
the program prints "Only enter positive values for base and height."


Create a Visio drawing of your logic. Make sure your source code compiles and runs properly.
Compress your Visio file and your source code file(.cpp) into an archive (.ZIP).
For this assignment, call the file Ex02-LastnameFirstNameInitial.zip i.e. Ex.02-ZejnilovicA.zip.
Make sure that the file contains as its first line a comment containing your name.
*/

#include <iostream>

using namespace std;

int main()
{

    // constants
    const double PI = 3.14159;   // PI

    // variables
    int userChoice;   // to hold user selection from the menu
    double radius,    // radius
           area,      // area
           length,    // length
           width,     // width
           base,      // base
           height;    // height

    // Welcome Message
    cout << "Geometry Calculator" << endl;

    // Create a menu
    cout << "1. Calculate the Area of a Circle" << endl;
    cout << "2. Calculate the Area of a Rectangle" << endl;
    cout << "3. Calculate the Area of a Triangle" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> userChoice;    // capture userChoice
    cin.ignore();         // defensive programming

    switch(userChoice)
    {// beginning of the switch
       case 1:
           // request the radius
           cout << "What is the radius of the circle: ";
           cin >> radius;

           //check for valid radius ("The radius cannot be less than zero.")
           if (radius < 0)
           {
                cout << "The radius cannot be less than zero."<< endl;
           }
           else //radius is valid
            {
                // compute the area (area = PI * radius **2)
                area = PI * radius * radius;

                //Display the area
                cout << "The area is " << area << endl;
           }
           break;
       case 2:
           //request the length
           cout << "What is the length of the rectangle : ";
           cin >> length;

           //check if length is valid
           if (length < 0)
           {
                cout << "Only enter positive values for length and width." << endl;

           }
           else
           {
                //request the width
                cout << "What is the width of the rectangle : ";
                cin >> width;

                //check if width is valid
                if (width < 0)
                {
                    cout << "Only enter positive values for length and width." << endl;

                }
                else
                {
                    // compute the area of the rectangle (area = length * width)
                    area = length * width;

                    //display the area
                    cout << "The area is " << area << endl;
                }
           }
           break;
       case 3:
           //request base
           cout << "What is the length of the base: ";
           cin >> base;

           //check for valid base
           if (base < 0)
           {
               cout << "Only enter positive values for base and height." << endl;
           }

           else
           {
                //request height
                cout << "What is the length of the height: ";
                cin >> height;


                //check for valid height ("Only enter positive values for base and height.")
                if (height <0)
                {
                    cout << "Only enter positive values for base and height." << endl;
                }

                else //valid base & height
                {
                    //calculate the area (area = base * height * .5)
                    area = base * height * .5;

                    //display the area
                    cout << "The area is " << area << endl;

                }
            }
           break;
       case 4:
           cout << "Thank You" << endl;
           break;
       default:
           cout << "The valid choices are 1 through 4. Run the program again and select one of those." << endl;
    }// end of the switch

    return 0;
}
