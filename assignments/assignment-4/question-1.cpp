#include <iostream>
using namespace std;

class Time
{
    int hour;
    int minute;
    int second;

public:
    Time() : hour(0), minute(0), second(0) {}

    Time(int hour, int minute, int second)
    {
    }

    void setHour(int hour)
    {
        this->hour = hour;
    }
    int getHour()
    {
        return this->hour;
    }
    void setMinute(int minute)
    {
        this->minute = minute;
    }
    int getMinute()
    {
        return this->minute;
    }

    void setSecond(int second)
    {
        this->second = second;
    }
    int getSecond()
    {
        return this->second;
    }
    void addTime(int hour, int minute = 0, int second = 0)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }

    // increment hour
    void incrementHour()
    {
        if (this->hour < 23)
        {
            this->hour++;
        }
        else
        {
            this->hour = 0;
        }
    }

    // increment minute
    void incrementMinute()
    {
        if (minute < 59)
        {
            this->minute++;
        }
        else
        {
            this->minute = 0;
            incrementHour();
        }
    }

    // increment second
    void incrementSecond()
    {
        if (second < 59)
        {
            this->second++;
        }
        else
        {
            this->second = 0;
            incrementMinute();
        }
    }

    void displayTime()
    {
        cout << "Hour: " << this->hour << ", Minute: " << this->minute << ", Second: " << this->second << endl;
    }
};

int menuList(Time *times, int arrSize){
    int action;
    cout << "--ACTIONS--" <<endl;
    cout << "1. Enter Time" << endl;
    cout << "2. Display Time" << endl;
    cout << "3. Get hour" << endl;
    cout << "4. Display all times" << endl;
    cout << "0. Exit" << endl;

    cout << "Enter action: ";
    cin >> action;

    switch(action){
        case 1:
        {
            int index;
            int hour;
            int minute;
            int second;
            cout << "-----(total: " << arrSize <<"):Enter object index: ";
            cin >> index;
            cout << "----------Enter day: ";
            cin>>hour;
            cout << "----------Enter month: ";
            cin>>minute;
            cout << "----------Enter year: ";
            cin>>second;

            times[index].addTime(hour, minute, second);
            cout << "Time added in object: " << index<<endl;
            break;
        }

        case 2:
            {int index;
            cout << "-----(total: " << arrSize <<"):Enter object index: ";
            cin >> index;
            times[index].displayTime();
            break;
            }

        case 3:{
            int index;
            cout << "-----(total: " << arrSize <<"):Enter object index: ";
            cin>>index;
            int hour = times[index].getHour();
            cout << "display hour: " << hour <<endl;
            break;
        }
        case 4:
                for (int j = 0; j < arrSize; j++){   
                    times[j].displayTime();
                }
                break;
        case 0:
                cout << "Ended."<<endl;
                break;

        default: 
                cout << "you enter wrong option."<<endl;
                break;
                


    }

    return action;
};

int main()
{

    int arrSize;

    cout << "How much time object: ";
    cin >> arrSize;

    Time *times[arrSize];



    // create dynamic objects
    for (int i = 0; i < arrSize; i++)
    {
        times[i] = new Time();
    }

    while (menuList(*times, arrSize) != 0)
    {
        
    }
    

    // add time
    // for (int i = 0; i < arrSize; i++)
    // {
    //     times[i]->addTime(0, 0, 0);
    // }

    // testing
    // for (int i = 0; i < 86400; i++)
    // {
    //     times[0]->incrementSecond();
    // }

    // read all object times


    // display only hour of all objects
    // for (int i = 0; i < arrSize; i++)
    // {
    //     int hour = times[i]->getHour();
    //     cout << "Hour of: " << i << " object" << hour << endl;
    // }

    return 0;
}