#include <iostream>

using namespace std;

static double PI = 3.14;

void getRadius(int );
double computeArea(int, double);
void displayArea(int , double);

int main()
{
    int radius;
    double Area;

    cout << "Hello world!" << endl;
    getRadius(radius);
    Area = computeArea(radis, PI);
    displayArea(radius, Area);


    return 0;
}



void getRadius(int &r)
{
    cout<< "enter radius";
    cin >> r;
}


//computeArea
//take in Pi & Radius
//return area
double computeArea(int r, double p)
{
    double area;

    area = p *r *r;

    return area;
}

void displayArea(int r, double a)
{
    cout<<"radius = " << r << "Area = " << area << endl;
}
