#include<iostream>
using namespace std;

class Box
{
    double length;
    double width;
    double height;

public:
    Box(void): length(0), width(0), height(0){
        cout << "Perameterless constructor." << endl;
    }
    Box(double length, double width, double height){
        cout << "Perameterized constructor." << endl;
        this->length = length;
        this->width = width;
        this->height = height;
    }
    Box(double lwh){
        cout << "Single Perameterized constructor." << endl;
        this->length = lwh;
        this->width = lwh;
        this->height = lwh;
    }

    int calculateVolumeBox(){

        return this->length * this->width * this->height;
    }
};

int main()
{
    Box b1(12, 15, 20);
    double res1 = b1.calculateVolumeBox();
    cout << res1 << endl;
    
    Box b2(15);
    double res2 = b2.calculateVolumeBox();
    cout << res2 << endl;

    Box b3;
    double res3 = b3.calculateVolumeBox();
    cout << res3 << endl;


    

    return 0;
}