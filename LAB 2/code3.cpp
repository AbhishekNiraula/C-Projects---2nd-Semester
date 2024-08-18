/* C++ LAB 2

WRITE A PROGRAM TO MANIPULATE COMPLEX NUMBERS USING OPERATOR OVERLOADING (ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION)*/

#include <iostream>
using namespace std;


class complex 
{
    int real;
    int imaginary;
    public:
        // Constructor Initialization.
        complex(int a = 0, int b = 0) : real(a), imaginary(b){}
        // Operator Overloading +
        complex operator + (complex m)
        {
            complex temp;
            temp.real = real + m.real;
            temp.imaginary = imaginary + m.imaginary;
            return temp;
        }
        complex operator - (complex n)
        {
            complex temp;
            temp.real = real - n.real;
            temp.imaginary = imaginary - n.imaginary;
            return temp;
        }
        complex operator * (complex m)
        {
            complex temp;
            // Real multiplies with real and two imaginary multiplies to give real as well.
            temp.real = real * m.real - imaginary * m.imaginary;
            temp.imaginary = real * m.imaginary + imaginary * m.real;
            return temp;
        }
        complex operator / (complex m)
        {
            complex temp;
            int denominator = real * m.real + imaginary * m.imaginary;
            temp.real = (real * m.real - imaginary * m.imaginary) / denominator;
            temp.imaginary = (real * m.imaginary + imaginary * m.real) / denominator;
            return temp;
        }
        void output()
        {
            if (real == 0  && imaginary == 0)
            {
                cout << " 0" << endl;
            }
            else if (real == 0)
            {
                cout << " i" << imaginary << endl;
            }
            else if (imaginary == 0)
            {
                cout << real <<  endl;
            }
            else {
                cout << real << " + " << " i" << imaginary << endl;
            }
        }

        ~ complex()
        {

        }

};


int main()
{

    // Input
    int rl, img;
    cout << "Enter two complex numbers (real and imaginary part)" << endl;
    cout << "First Complex Number" << endl;
    cin >> rl >> img;
    complex c1(rl, img);
    cout << "Second Complex Number" << endl;
    cin >> rl >> img;
    complex c2(rl, img);


    // Operations.
    complex c3 = c1 + c2;
    complex c4 = c1 - c2;
    complex c6 = c1 * c2;
    complex c7 = c1 / c2;

    // Output.
    cout << "Addition: " << endl;
    c3.output();
    cout << "Subtraction: " << endl;
    c4.output();
    cout << "Multiplication: " << endl;
    c6.output();
    cout << "Division: " << endl;
    c7.output();
}

