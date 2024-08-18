// Object Oriented Programming - C++ LAB 1

// LAB 1 - Program 1

/* Create a 'DISTANCE' class with : 
- feet and inches as data members
- member functions to input _DISABLE_PER_THREAD_LOCALE_NEW
- member function to output distance
- member function to add two distance objects
Write a main function to create objects of 'DISTANCE' class. Input two distances and output the sum. */


#include <iostream>
using namespace std;  

// Defining an object.
class DISTANCE 
{
    // Private data members by default.
    int feet;
    int inches;
    public:
        // Public member functions. 
        void getDistance()
        {
            cout << "Enter distance in feet: " << endl;
            cin >> feet;
            cout << "Enter distance in inches: " << endl;
            cin >> inches;
        }
        void outDistance()
        {
            cout << "Distance in feet is: " << feet << endl;
            cout << "Distance in inches is: " << inches << endl;
        }
        void sum(DISTANCE dis1, DISTANCE dis2)
        {
            int total_feet = dis1.feet + dis2.feet;
            int total_inches = dis1.inches + dis2.inches;
            if (total_inches >= 12)
            {
                int quo = total_inches / 12;
                total_feet = total_feet + quo;
                total_inches = total_inches %  12;
            } 
            cout << "Total feet: " << total_feet << endl;
            cout << "Total inches: " << total_inches << endl;
        }
};


int main()
{
    // Initializing an object.
    DISTANCE d1, d2;
    d1.getDistance();
    d2.getDistance();
    d1.outDistance();
    d2.outDistance();
    DISTANCE d3;
    d3.sum(d1, d2);
    

} 