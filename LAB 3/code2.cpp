/* LAB 3

    Write a program to convert Polar Coordinates to Cartesian Coordinates*/

#include <iostream>
#include <cmath>
#include <string>
#include <math.h>
using namespace std;

#define PI 3.141592


class Polar
{
    float rad;
    float ang;
    public:
        Polar(float a = 0, float b = 0) {
            rad = a;
            ang = b * (PI/180.0);
        }
        float getRad()
        {
            return rad;
        }
        float getAng()
        {
            return ang;
        }
        

        void output()
        {
            cout << "(radian, angle(degrees)) :::: (" << rad << ", " << ang * (180.0 / PI) << " degrees)" <<  endl;
        }
       // friend class Cartesian;
};

class Cartesian
{
    float x;
    float y;
    public:
        Cartesian(float a = 0, float b = 0) : x(a), y(b) {}

        Cartesian(Polar p1)
        {
            float rad1, ang1;   
            rad1 = p1.getRad();
            ang1 = p1.getAng();    
            x = rad1 * cos(ang1);
            y = rad1 * sin(ang1);
        }
 
        void output()
        {
            cout << "(x, y) :::: (" << x << ",  " << y << ")" << endl;
        }
       // friend class Polar;
};

// Cartesian::Cartesian(Polar p1)
// {
//     x = p1.rad * cos(p1.ang);
//     y = p1.rad * sin(p1.ang);
// }

int main() 
{
    float r, a;
    cout << "Enter your polar coordinates: " << endl;
    cout << "Radian(r): ";
    cin >> r;
    cout << "Angle(in degrees): ";
    cin  >> a;
    Polar p1 = Polar(r, a);

    cout << endl << endl << endl;
    p1.output();
    
    Cartesian c1 = p1;
    cout << "Equivalent polar coordinates: " << endl;
    c1.output();

    return 0;
}