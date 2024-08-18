/* LAB 3

    Write a program to convert time (hour, minute and second) in 12-hr format to 
    24-hr format.*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;



class Time24;
class Time12
{
    int hour;
    int minute;
    int second;
    int ispm; // 1 = pm and 0 = am
    public:
        // Constructor
        Time12(int x = 0, int y = 0, int z = 0, int w = 0) : hour(x) , minute(y), second(z), ispm(w) {}


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
        int getPm()
        {
            return ispm;
        }

        void output()
        {
            cout << "HH:MM:DD :::: ";
            cout <<  setw(2) << setfill('0') << hour % 100 << ":" <<  setw(2) << setfill('0') << minute % 100 << ":" <<  setw(2) << setfill('0') << second % 100;
            ispm == 1 ? (cout << " PM" << endl) : (cout << " AM" << endl);
        }

        friend class Time24;
};

class Time24
{
    int hour;
    int minute;
    int second;
    public:
        Time24(int x = 0, int y = 0, int z = 0) : hour(x), minute(y), second(z) {}

        Time24(Time12 t1)
        {
            hour = t1.getHour();
            if (t1.getPm() == 1)
            {
                hour = t1.getHour() + 12;
            }
            if (t1.getHour() == 12)
            {
                hour = 12;
            }
            minute = t1.getMinute();
            second = t1.getMinute();     
        }

        void output()
        {
            cout << "HH:MM:DD :::: ";
            cout <<  setw(2) << setfill('0') << hour % 100 << ":" <<  setw(2) << setfill('0') << minute % 100 << ":" <<  setw(2) << setfill('0') << second % 100 << endl;
        }
        friend class Time12;
};

int main()
{
    // Input.
    Time12 t1;
    int hr, min, sec, ispmi;
    string ispm;
    cout << "Enter time in hour, minute, second along with AM or PM: ";
    cin >> hr >> min >> sec;
    cin >> ispm;

    std::transform(ispm.begin(), ispm.end(), ispm.begin(),
        [](unsigned char c){ return tolower(c); });

    if ( ispm == "pm" || ispm == "p.m.")
    {
        ispmi = 1;
    }
    else if ( ispm  == "am" || ispm == "a.m.")
    {
        ispmi = 0;
    }
    else {
        cout << "Invalid Time input." << endl;
    }
    t1 = Time12(hr, min, sec, ispmi);
    
    cout << "Time in 12 Hour Format: ";
    t1.output();
    cout << endl << endl;
    cout << "Time in 24 Hour Format: ";
    Time24 t2 = t1;
    t2.output();
}