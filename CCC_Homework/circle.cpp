#include <iostream>
#include "circle.h"
using namespace std;


int main(){
    double radii;

    cout << "Please enter the radius for the circle: " << endl;
    cin >> radii;

    Circle circle(radii);
    circle.setRadius(radii);
    cout << "Here is the diameter of your circle: " << circle.getDiameter() << "\n";
    cout << "Here is the area of your circle: " << circle.getArea() << "\n";
    cout << "Here is the circumference of your circle: " << circle.getCircumference() << "\n";

}
