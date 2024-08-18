/* C++ LAB 2

Create a class called 'TIME' that has

    - three integer data members for hours, minutes and seconds
    - constructor to initialize the object to zero
    - constructor to initialize the object to some constant value
    - overload +,- to add and subtract two TIME objects
    - overload > function to compare two time 
    - member functon to display time in HH:MM:SS format */


#include <iostream>
#include <iomanip>
using namespace std;

class Time 
{
    int hour;
    int minute;
    int second;

    public:
        // Constructor
        Time(int x = 0, int y = 0, int z = 0) : hour(x) , minute(y), second(z) {}
        

        Time operator + (Time t)
        {
            Time temp(0);
            temp.second = second + t.second;
            while (temp.second >= 60)
            {
                temp.minute++;
                temp.second = temp.second % 60;
            }
            temp.minute = temp.minute + minute + t.minute;
            while  (temp.minute >= 60)
            {
                temp.hour++;
                temp.minute = temp.minute % 60;
            }
            temp.hour = temp.hour + hour + t.hour;
            return temp;
        }
        Time operator - (Time t)
        {
            Time temp(0);
            temp.hour  = hour - t.hour;
            temp.minute = minute - t.minute;
            temp.second = second - t.second;
            return temp;
        }
        int operator > (Time t)
        {
            if (hour > t.hour)
            {
                return 1;
            }
            else if (hour < t.hour)
            {
                return 0;
            }
            else
            {
                if (minute > t.minute)
                {
                    return 1;
                }
                else if (minute < t.minute)
                {
                    return 0;
                }
                else
                {
                    if (second > t.second)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
        void output()
        {
            cout << "HH:MM:DD :::: ";
            cout <<  setw(2) << setfill('0') << hour % 100 << ":" <<  setw(2) << setfill('0') << minute % 100 << ":" <<  setw(2) << setfill('0') << second % 100 << endl;
        }    
};

void formatOP(int a)
{
    if (a == 1)
    {
        cout << "True" << endl;
    }
    else if (a == 0)
    {
        cout << "False" << endl;
    }
    else 
    {
        cout << "Invalid" << endl; 
    }
}

int main()
{
    // Input.
    Time t1, t2;
    int hr, min, sec;
    cout << "Enter time in hour, minute, second: ";
    cin >> hr >> min >> sec;
    t1 = Time(hr, min, sec);


    cout << "Enter time in hour, minute, second: ";
    cin >> hr >> min >> sec;
    t2 = Time(hr, min, sec);


    // Overloading operator.
    Time t3 = t1 + t2;
    Time t4 = t1 - t2;

    
    cout << "Addition: ";
    t3.output();
    cout << "Subtraction: ";
    t4.output();

    cout << "First Time > Second Time: ";
    formatOP(t1 > t2);
}