// Object Oriented Programming - C++ LAB 1

// LAB 1 - Program 2

/* Write a program that determines the maximum and the minimum of three numbers. */


#include <iostream>

// namespace are reserved names in C++ libraries. Here using std namespace tells the programs statments are within std namespace.
using namespace std;

int main()
{
    int a, b, c;
 
    cout << "Enter three numbers: " << endl;
    // endl causes the output buffer to be flushed and print new line automatically.
    cin >> a >> b >> c;
    if ( a > b && a > c)
    {
        cout << a << " is the greatest.\n" << endl;
    }
    else if ( b > c) 
    {
        cout << b << " is the greatest.\n" << endl;
    }
    else 
    {
        cout << c << " is the greatest.\n" << endl;
    }
    return 0;
}