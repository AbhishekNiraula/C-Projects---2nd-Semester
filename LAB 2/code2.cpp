/* C++ LAB 2

Write a program to overload all relational operators to compare the currency with Nepalese currency.
Use conversion rate $1 = NRs. 101.36.(Note: make two classes to represent each currency.)*/


#include <iostream>
using namespace std;
#define rate 101.36

class Rupee;

class Dollar
{
    float dollar;
    public:
        // Constructor
        Dollar(float a = 0.0) : dollar(a) {}

        void output()
        {
            cout << "Dollar: " << dollar << endl;
        }
        friend Rupee exchange(Dollar);        
        ~ Dollar()
        {
        }   
};
class Rupee
{
    float rupee;
    public:
        Rupee(float a = 0.0) : rupee(a) {}

        void output()
        {
            cout << "Rupee: " << rupee << endl;
        }
        friend Rupee exchange(Dollar);

        // Overloading all the operators.
        int operator==(Rupee r)
        {
            if (rupee == r.rupee)
            {
                return 1;
            }
            else   
            {
                return 0;
            }
        }
        int operator <= (Rupee r)
        {
            if (rupee <= r.rupee)
            {
                return 1;
            }
            else {
                return 0;
            }
        }
        int operator >= (Rupee r)
        {
            if (rupee >= r.rupee)
            {
                return 1;
            }
            else {
                return 0;
            }
        }

        ~ Rupee ()
        {

        }
};

Rupee exchange(Dollar d1)
{
    Rupee temp;
    temp.rupee = d1.dollar * rate;
    return temp;
}

// Formatting the output to true or false.
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

    // Taking input from users.
    float n;
    Rupee r1;
    Dollar d1;
    cout << "Enter amounts in Rupee: " << endl;
    cin >> n;
    r1 = Rupee(n);
    cout << "Enter amounts in Dollar: " << endl;
    cin >> n;
    d1 = Dollar(n);

    // Output
    Rupee r2 = exchange(d1); 
    cout << "(Exchanged) ";
    // r2 = exchanged amount
    r2.output();
    r1.output();


    // Overloading the operators.
    cout << "Rupee == Dollar: ";
    formatOP(r1 == r2);
    cout << "Rupee <= Dollar: ";
    formatOP(r1 <= r2);
    cout << "Rupee >= Dollar: ";
    formatOP(r1 >= r2);
}