#include <iostream>
using namespace std;



class TollBooth
{
    unsigned int totalNumberOfCars;
    double totalAmount;

public:
    TollBooth() : totalNumberOfCars(0), totalAmount(0)
    {
    }

    void payingCar()
    {
        this->totalNumberOfCars++;
        this->totalAmount += 0.50;
    }

    void noPayCar()
    {
        this->totalNumberOfCars++;
    }

private:
    int numberOfNoPayingCars()
    {
        return ((0.50 * totalNumberOfCars) - this->totalAmount) / 0.50;
    }

public:
    void printOnConsole()
    {
        cout << endl;
        cout << "Total Amount: " << totalAmount << endl;
        cout << "Total Cars: " << totalNumberOfCars << endl;
        cout << "No Paying cars: " << this->numberOfNoPayingCars() << endl;
    }
};

void printActions()
{
    cout << endl;
    cout << "1. Add Paying car" << endl;
    cout << "2. Add No Paying car" << endl;
    cout << "3. print on console" << endl;
    cout << "0. Exit" << endl;
};

int handleTollBoth(TollBooth *tb)
{
    printActions();

    int action;
    cout << "Enter val: ";
    cin >> action;

    switch (action)
    {
    case 1:
        tb->payingCar();
        break;
    case 2:
        tb->noPayCar();
        break;
    case 3:
        tb->printOnConsole();
    case 0:
        break;
    }

    return action;
};

int main()
{

    TollBooth tb;
    while (handleTollBoth(&tb) != 0)
    {
    }

    cout << "Final result: " << endl;
    tb.printOnConsole();

    return 0;
}