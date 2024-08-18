// Object Oriented Programming - C++ LAB 1

// LAB 1 - Program 2

// Write a program to check order and provide suitable output as a pharmacy store.

#include <iostream>
using namespace std;

int main()
{
    int order;
    int storeAmount;
    cout << "Enter the store quantity: " << endl;
    cin >> storeAmount;
    cout << "Enter the order quantity: " << endl;
    cin >> order;
    if (order > storeAmount)
    {
        cout << "Not enough quantity." << endl;
    }
    else {
        if (order > 16 && storeAmount <= 40 )
        {
            cout << "You cannot order more than 16 item." << endl;
        }
        else {
            cout << "Your order is accepted." << endl;
        }
    }
}