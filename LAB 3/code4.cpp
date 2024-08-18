/* LAB 3

    Write a program to convert time (hour, minute and second) in 24-hr format to 
    12-hr format.*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
using namespace std;

class Time24
{
    int hour;
    int minute;
    int second;
    public:
        Time24(int x = 0, int y = 0, int z = 0) : hour(x), minute(y), second(z) {}


        int getHour()
        {
            return hour;
        }
        
        int getMinute()
        {
            return minute;
        }
        
        int getSecond()
        {
            return second;
        }

        void output()
        {
            cout << "HH:MM:DD :::: ";
            cout <<  setw(2) << setfill('0') << hour % 100 << ":" <<  setw(2) << setfill('0') << minute % 100 << ":" <<  setw(2) << setfill('0') << second % 100 << endl;
        }
};


class Time12
{
    int hour;
    int minute;
    int second;
    int ispm; // 1 = pm and 0 = am
    public:
        // Constructor
        Time12(int x = 0, int y = 0, int z = 0, int w = 0) : hour(x) , minute(y), second(z), ispm(w) {}

        Time12(Time24 t1)
        {
            int hrs = t1.getHour();
            ispm = hrs >= 12 ? 1 : 0;
            int hrs12 = hrs % 12;
            if (hrs12 == 0)
            {
                hrs12 = 12;
            }
            hour = hrs12;
            minute = t1.getMinute();
            second = t1.getSecond(); 
        }

        void output()
        {
            cout << "HH:MM:DD :::: ";
            cout <<  setw(2) << setfill('0') << hour % 100 << ":" <<  setw(2) << setfill('0') << minute % 100 << ":" <<  setw(2) << setfill('0') << second % 100;
            ispm == 1 ? (cout << " PM" << endl) : (cout << " AM" << endl);
        }

        friend class Time24;
};

int main()
{
    // Input.
    Time24 t1;
    int hr, min, sec;
    cout << "Enter time in hour, minute, second: ";
    cin >> hr >> min >> sec;
    t1 = Time24(hr, min, sec);
    
    cout << "Time in 24 Hour Format: ";
    t1.output();
    cout << endl << endl;
    cout << "Time in 12 Hour Format: ";
    Time12 t2 = t1;
    t2.output();
}