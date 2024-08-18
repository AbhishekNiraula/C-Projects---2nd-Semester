#include <iostream>
using namespace std;
class secondClass;
class firstClass
{
    int a;
    public:
        void input();
        friend void showSum(firstClass,secondClass);
        
};
void firstClass :: input()
{
    cout << "Enter first number: " << endl;
    cin >> a;
}
class secondClass
{
    int b;
    public:
        void input()
        {
            cout << "Enter second number: " << endl;
            cin >> b;
        }
    friend void showSum(firstClass,secondClass);
};
void showSum(firstClass val1, secondClass val2)
{
    cout << "The sum is: " << val1.a+  val2.b << endl;
}
int main()
{
    firstClass x;
    secondClass y;
    x.input();
    y.input();
    showSum(x,y);
    return 0;
}
