#include <iostream>
using namespace std;

class Date
{
    private :

    int day;
    int month;
    int year;

    public:
    void initDate(){

    }

    void initDate(int d, int m, int y){
        this->day = d;
        this->month = m;
        this->year = y;
    }
    void printDateOnConsle(){
        cout << "---OUTPUT---" << endl;
        cout << "Day: " << day << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
    }
    void acceptDateFromConsole(){
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> day;
        cout << "Enter year: ";
        cin >> day;

    }

    void isLeapYear(){
        if(year % 4 == 0 && (year % 100 == 0 || year % 400 != 0)){
            cout << "Its leap year" << endl;
        }else{
            cout << "Its not a leap year" << endl;
        }
    }

};

int main()
{
    Date d;
    d.initDate();
    d.acceptDateFromConsole();
    d.printDateOnConsle();
    d.isLeapYear();

    return 0;
}



// Q2. Write a menu driven program for Date in a CPP language using structure and also using class.
// Date is having data members day, month, year. Implement the following functions.
// void initDate();
// void printDateOnConsole();
// void acceptDateFromConsole();
// bool isLeapYear();
