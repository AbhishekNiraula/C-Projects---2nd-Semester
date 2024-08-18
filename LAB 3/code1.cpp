/* LAB 3

    Write a program to convert Nepalese currency(Rupees and paisa) to US Currency(Dollar and cents).*/

#include <iostream>
#include <iomanip>
using namespace std;
#define rate 98.51


class Dollar;
class NPR
{
    float rupees;
    float paisa;
    public:
        NPR(float a = 0, float b = 0) : rupees(a), paisa(b) {}

        void output()
        {
            cout << "Rupee: " << rupees << " and Paisa: " << paisa << endl;
        }
        friend Dollar exchange(NPR);
};

class Dollar
{
    float dollar;
    float cents;
    public:
        Dollar(float a = 0, float b = 0) : dollar(a), cents(b) {}

        void output()
        {
            if (dollar == 0)
            {
                cout << "Cents: " << cents << endl;
            }
            else if (cents == 0)
            {
                cout << "Dollar: " << dollar << endl;
            }
            else if (cents == 0 && dollar == 0)
            {
                cout << "No conversion." << endl;
            }
            else 
            {
                cout << "Dollar: " << dollar << " and Cents: " << cents << endl;
            }
        }
        friend Dollar exchange(NPR);
};

Dollar exchange(NPR r1)
{
    Dollar temp;
    float total_rupees = r1.rupees + (r1.paisa/100.0);
    float dollars = total_rupees / rate;
    temp.dollar = static_cast<int>(dollars);
    temp.cents = static_cast<int>((dollars - temp.dollar) * 100);
    return temp;
}

int main()
{
    int rupee, paisa;
    cout << "Enter your currency in Nepalese rupee: " << endl;
    cout << "Rupee: ";
    cin >> rupee;
    cout << "Paisa: ";
    cin  >> paisa;
    NPR r1 = NPR(rupee, paisa);
    
    Dollar d1 = exchange(r1);
    cout << "Equivalent currency in Dollars: " << endl;
    d1.output();

    return 0;
}