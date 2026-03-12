#include <iostream>
using namespace std;

class Cylinder
{
public:
    static double PI;

private:
    double radius;
    double height;

public:
    Cylinder() : radius(0), height(0){
    }

    Cylinder(double radius, double height){
        this->radius = radius;
        this->height = height;
    }
    void setRadius(double radius){
        this->radius = radius;
    }
    double getRadius(){
        return this->radius;
    }
    void setHeight(double height){
        this->height = height;
    }
    double getHeight(){
        return this->radius;
    }

    double calculateVolume(){
        return (Cylinder::PI * radius * radius * height);
    }
};

double Cylinder::PI = 22 / 7;

int main()
{
    class Cylinder c(12, 13);

    c.setRadius(2);
    c.setHeight(2);

    double result = c.calculateVolume();

    cout << "Cylinder volume is: " << result << endl;
}