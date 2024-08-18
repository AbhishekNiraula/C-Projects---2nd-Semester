#include <iostream>
#include <cstring>
using namespace std;

template <class T>

void swap(T *a, T *b)
{
    T *temp;
    *temp = a;
    *a = *b;
    *b = *temp;
}
void swap(string a,string b)
{
    string temp = a;
    a = b;
    b = temp;
}


int main()
{
    int a, b;
    char c, d;
    string x; 
    string y;

    cout << "Enter any two integer variables: ";
    cin >> a >> b;

    swap(a, b);

    cout << "Swapped integers are: " << a << "\t" << b;

    cout << endl << "Enter any two character variables: ";
    cin >> c >> d;

    swap(c, d);

    cout <<  "Swapped characters are: " << c << "\t" << d;

    cout << endl << "Enter any two string variables: ";
    cin >> x;
    cin >> y;

    swap(x, y);

    cout << endl << "Swapped string are: " << x << "\t" << y;

    return 0;
}