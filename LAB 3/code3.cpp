/* LAB 3

    Write a program to convert Cartesian Coordinates to Polar Coordinates*/

#include <iostream>
#include <cmath>
#include <string>
#include <math.h>
using namespace std;

#define PI 3.141592

class Polar;
class Cartesian
{
    float x;
    float y;
    public:
        Cartesian(float a = 0, float b = 0) : x(a), y(b) {}

        float getXco()
        {
            return x;
        }
        float getYco()
        {
            return y;
        }

        void output()
        {
            cout << "(x, y) :::: (" << x << ",  " << y << ")" << endl;
        }
};

class Polar
{
    float rad;
    float ang;
    public:
        Polar(float a = 0, float b = 0) {
            rad = a;
            ang = b * (PI/180.0);
        }
        
        Polar(Cartesian c1)
        {
            float xCo, yCo;
            xCo = c1.getXco();
            yCo = c1.getYco();
            rad = sqrt(pow(xCo, 2) + pow(yCo, 2));
            ang = atan(yCo / xCo);       
        }

        void output()
        {
            cout << "(radian, angle(degrees)) :::: (" << rad << ", " << ang * (180.0 / PI) << " degrees)" <<  endl;
        }
};
int main() 
{
    float x, y;
    cout << "Enter your cartesian coordinates: " << endl;
    cout << "X Coordinates(x): ";
    cin >> x;
    cout << "Y COordinates(y): ";
    cin  >> y;
    Cartesian c1 = Cartesian(x, y);

    cout << endl << endl << endl;
    c1.output();
    
    Polar p1 = c1;
    cout << "Equivalent polar coordinates: " << endl;
    p1.output();

    return 0;
}