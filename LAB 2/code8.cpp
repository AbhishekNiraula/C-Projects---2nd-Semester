/* LAB 2

    A parking garage charges a $2.00 minimum fee to park for up to three hours. 
    The garage charges an additional $0.50 per hour for each hour or part thereof in excess of three hours. 
    People who park their cars for longer than 24 hours will pay $8.00 per day. 
    Write a program that calculates and prints the parking charges. 
    The inputs to your program are the date and time when a car enters the parking garage, and the date and time when the same car leaves the parking garage. 
    Keep track of number of cars in the garage overloading ++ and -- operators. */

#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
using namespace std;
#define MAX 20

void check_car(Car);

// Class to keep track of time.
class Time 
{
    int hour;
    int minute;
    int second;

    public:
        // Constructor
        Time(int x = 0, int y = 0, int z = 0) : hour(x) , minute(y), second(z) {}
        
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


class Car
{
    Time enter_time;
    Time exit_time;
    static int total_cars;
    float charge;
    string number_plate;
    public:
        int calculate_charge()
        {
            return 0;   
        }
};
int main()
{
    Car cars[MAX];
    string np;
    cout << "Enter car number plate" << endl;
    cin >> np;
    for (int i = 0; i < MAX;i++)
    {
        if (1)
        {
            check_car(cars[i]);
        }
        else 
        {
            cout << "There is no entry of car with that number plate." << endl;
        }
    }
    return 0;
}


void check_car()
{
    
}