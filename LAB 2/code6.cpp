/* C++ LAB 2

    Modify above class to work with compile time memory allocation i.e. with char[]*/



#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100

class String
{
    char name[MAX];
    public: 
        // Constructor

        String(const char* a)
        {
            strcpy(name, a);
        }
        // Copy constructor
        String(const String& s) {
            strcpy(name, s.name);
        }
        String operator + (const String s)
        {
            char temp[MAX];
            strcpy(temp, name);
            strcat(temp, s.name);
            return String(temp);
        }

        String operator =(const String s)
        {
            strcpy(name, s.name);
            return *this;
        }
        
        int operator ==(const String s)
        {
            return (strcmp(name, s.name));
        }        

        void output()
        {
            cout << "Name: " << ( name ? name : "NULL") << endl;
        }

        // Destructor
        ~ String(){
        }
};

int main()
{
    char name[100];
    cout << "Enter any string: " << endl;
    cin >> name;
    String s1=name;
    cout << "Enter another string: " << endl;
    cin >> name;
    String s2=name;

    String s3 = s1 + s2;

    s1.output();
    s2.output();
    cout << endl;
    s3.output();

    cout << endl << endl << "Assignment (s1 = s2): ";
    String s4 = s3;
    s4.output();
    cout << endl << endl << "Comparision operator (s1 == s2)? : ";
    (s1 == s2) == 0 ? (cout << "True") : (cout << "False");
}
