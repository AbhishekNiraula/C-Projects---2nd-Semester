/* C++ LAB 2

    Overload >> and << operators to input and display time. */

#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
    int hour;
    int minute;
    int second;
    public:
        Time(int hr = 0, int min = 0, int sec = 0) : hour(hr), minute(min), second(sec) {}
        
        friend istream& operator>> (istream &is, Time &t)
        {
            cout << "Enter hour: " << endl;
            is >> t.hour;
            cout << "Enter minute: " << endl;
            is >> t.minute;
            cout << "Enter second: " << endl;
            is >> t.second;
            return is;   
        }
        friend ostream& operator<< (ostream &os, Time &t)
        {
            cout << "Time: "  << endl;
            os << "HH:MM:SS: " << setw(2) << setfill('0') << t.hour % 100 << " : " << setw(2) << setfill('0') << t.minute % 100 << " : " << setw(2) << setfill('0') << t.second % 100 << endl;
            return os;
        }

        Time operator + (Time t)
        {
            Time temp(0);
            temp.second = second + t.second;
            if (temp.second >= 60)
            {
                temp.minute++;
                temp.second = temp.second % 60;
            }
            temp.minute = temp.minute + minute + t.minute;
            if (temp.minute >= 60)
            {
                temp.hour++;
                temp.minute = temp.minute % 60;
            }
            temp.hour = temp.hour + hour + t.hour;
            return temp;
        }
};

int main()
{
    Time t1;
    Time t2;

    cout << "Enter first time: " << endl;
    cin >> t1;

    cout << "Enter second time: " << endl;
    cin >> t2;

    cout << endl << endl << endl << t1 << t2;

    Time t3 = t1 + t2;
    cout << endl << endl << "Addition: " << endl;
    cout << t3;
    return 0;
}
