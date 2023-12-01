#ifndef CIRCLE_H
#define CIRCLE_H

class Circle{
    private:
        double radius;
        double pi;
    public:
        Circle(double rad);
        void setRadius(double r){
            radius = r;
        }
        double getRadius(){
            return radius;
        }
        double getArea(){
            double area;
            area = pi * radius * radius;
            return area;
        }
        double getDiameter(){
            double diameter;
            diameter = radius * 2;
            return diameter;
        }
        double getCircumference(){
            double circumference;
            circumference = 2 * pi * radius;
            return circumference;
        }

};

Circle::Circle(double rad){
    radius = 0;
    pi = 3.14159;
}

#endif