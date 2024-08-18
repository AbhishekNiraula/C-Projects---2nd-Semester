/* LAB 4

    a. Define an instance object of class DateTime called Watch.
    
    b. Write a main () function that would initialize the values through the constructor
    functions, and then allows them to be reset through the set () functions. Be sure and
    display the results following the constructor before you use the set functions.

    c. Through the use of the display () function, the time and date are to be displayed. Note
    that the display () functions in all three classes need to be defined, as well as the
    constructor and all the access functions    

*/

#include <iostream>
#include <string>
#include <iomanip>


using namespace std;



class Date
{
    int day,month,year;
    public:

        // Default Constructor
        Date(): year(0) , month(0) , day(0)
        {}
        
        // Parametrized Constructor
        Date(int y,int m,int d): year(y), month(m), day(d)
        {}

        // displays the date
        void display()
        {
            cout << "YY::MM::DD   ::::   ";
            cout << setw(4) << setfill('0') << year % 10000 << "::" << setw(2) << setfill('0') << month % 100 << "::" << setw(2) << setfill('0') << day % 100 << endl;
        }
        // accesses the date members
        Date get()
        {
            return *this;
        }    

        // sets the date members
        void set(int y, int m, int d)
        {
            year = y;
            month = m;
            day = d;
        } 
        
        // Destructor
        ~Date()
        {

        }
};


class Time
{
    int hour;
    int minute;
    int second;
    public:
        // Default Constructor
        Time() : hour(0), minute(0), second(0) {}

        // Parameterized Constructor
        Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

        // Display the time
        void display(){
            cout << "HH::MM::SS   ::::   ";
            cout << setw(2) << setfill('0') << hour << "::" << setw(2) << setfill('0') << minute << "::" << setw(2) << setfill('0') << second << endl;
        }

        // Accessor to get time values
        Time get() const {
            return *this;
        }

        // Mutator to set time values
        void set(int h, int m, int s) {
            hour = h;
            minute = m;
            second = s;
        }

        // Destructor
        ~Time() {

        }
};


class DateAndTime : public Date, public Time
{
    public:
        void display()
        {
            Date::display();
            Time::display();
        }// prints date and time
};


int main()
{
    DateAndTime watch;

    int year, month, day, hour, minute, second;

    // Input for date
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;
    watch.Date::set(year, month, day);

    // Input for time
    cout << "Enter hour: ";
    cin >> hour;
    cout << "Enter minute: ";
    cin >> minute;
    cout << "Enter second: ";
    cin >> second;
    watch.Time::set(hour, minute, second);

    cout << "\nEntered date and time:" << endl;
    watch.display();

    char c;
    
    while (true)
    {
        cout << "Do you want to reset Date and Time?(y/n)" << endl;
        cin >> c;

        switch(c)
        {
            case 'y':
                main();
            case 'Y':
                main();
            default:
                cout << "Exiting...";
                exit(0);
        }
    }
    
    return 0;
}