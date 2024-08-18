/* C++ LAB 2

WRITE A PROGRAM TO MANIPULATE COMPLEX NUMBERS USING OPERATOR OVERLOADING (ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION)*/


#include <iostream>
using namespace std;

class secondClass;
class firstClass {
    int a;
    public:
        void input()
        {
            cout << "Enter a number: " << endl;
            cin >> a;
        }
        void output()
        {
            cout << a << endl;
        }
        friend void swapNumbers(firstClass &m1, secondClass &m2);
};
class secondClass {
    int b;
    public: 
        void input()
        {
            cout << "Enter a number: " << endl;
            cin >> b;
        }
        void output()
        {
            cout << b << endl;
        }
        friend void swapNumbers(firstClass &m1, secondClass &m2);
};
void swapNumbers(firstClass &m1, secondClass &m2)
{
    int temp = m1.a;
    m1.a = m2.b;
    m2.b = temp;
}
int main()
{
    firstClass m1;
    secondClass m2;
    m1.input();
    m2.input();




    cout << endl << "Original Numbers: " << endl;
    cout << "First Class: " << endl;
    m1.output();
    cout << "Second Class: " << endl;
    m2.output();


    swapNumbers(m1, m2);
    
    cout << endl << "Swapped Numbers: " << endl;
    cout << "First Class: " << endl;
    m1.output();
    cout << "Second Class: " << endl;
    m2.output();
}