#include <iostream>

/*

area = Pi * radius * radius;




You need the following funcitons:

1) getRadius - prompts the user for the radius

               and returns it




2) computeArea - takes in two parameters radius,

                 Pi and radius and computes the

                 area and returns it.




3) displayArea - takes in two parameters (radius,

                 area).

                 "Circle with 5 inch radius

                  has the??? area"




*/




using namespace std;




// function prototypes

int getRadius();

double computeArea(int, double);

void displayArea(int, double);




int main()

{

    int rad;            // to store the return value from the getRadius function

    double circleArea;  // to store the return value from the computeArea function




    rad = getRadius();

    circleArea = computeArea(rad,3.1415);

    displayArea(rad, circleArea);

    return 0;

}




int getRadius()

{

    int radius;

    cout << "Enter the radius: ";

    cin >> radius;




    return radius;

}




/*

     Function    : computeArea

     Parameters  : int radius, double Pi

     Returns     : double

     Description : takes in two parameters radius,Pi and radius and

                   computes the area and returns it.

*/

double computeArea(int radius, double pi)

{

    double area;

    area = pi * radius * radius;

    return area;

}




void displayArea(int radius, double area)

{

    cout << "Circle with : " << radius

         << " inch radius has : " << area

         << " area" << endl;




}
