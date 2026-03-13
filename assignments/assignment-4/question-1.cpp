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

int main()
{

    Time *times[5];

    // create dynamic objects
    for (int i = 0; i < 5; i++)
    {
        times[i] = new Time();
    }

    // add time
    for (int i = 0; i < 5; i++)
    {
        times[i]->addTime(0, 0, 0);
    }

    // testing
    for (int i = 0; i < 86400; i++)
    {
        times[0]->incrementSecond();
    }

    // read all object times
    for (int i = 0; i < 5; i++)
    {
        times[i]->displayTime();
    }

    // display only hour of all objects
    for (int i = 0; i < 5; i++)
    {
        int hour = times[i]->getHour();
        cout << "Hour of: " << i << " object" << hour << endl;
    }

    return 0;
}