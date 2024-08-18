/* C++ LAB 2

    CREATE a 'STRING' class which char* and length as data member and overloads '+', '=' and '==' operators to perform respective
    operations. Use constructor and destructor whenever suitable.*/

#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char* name;
    int length;
    public: 
        // Constructor
        String() : name(nullptr), length(0) {}

        String(char* a) {
            length = strlen(a);
            name = new char[length + 1];
            strcpy(name, a);
        }
        // Copy constructor
        String(String& s) {
            length = s.length;
            name = new char[length + 1];
            strcpy(name, s.name);
        }

        String operator + (String s)
        {
            String temp;
            temp.length = length + s.length;
            temp.name = new char[temp.length + 1];
            strcpy(temp.name, name);
            strcat(temp.name, s.name);
            return temp;
        }

        String operator =(String s)
        {
            length = s.length;
            name = new char[length + 1];
            strcpy(name, s.name);
            return *this;
        }
        
        int operator ==(String s)
        {
            return (strcmp(name, s.name));
        }        

        void output()
        {
            cout << "Name: " << ( name ? name : "NULL") << endl << "Length of String: " << length << endl;
        }

        // Destructor
        ~ String(){
            delete[] name;
        }
};

int main()
{
    char name[50];
    cout << "Enter any string: " << endl;
    cin >> name;
    String s1 = name;
    cout << "Enter another string: " << endl;
    cin >> name;
    String s2 = name;

    String s3 = s1 + s2;

    s1.output();
    s2.output();
    s3.output();

    cout << endl << endl << "Assignment (s1 = s2): ";
    String s4 = s3;
    s4.output();
    cout << endl << endl << "Comparision operator (s1 == s2)? : ";
    (s1 == s2) == 0 ? (cout << "True") : (cout << "False");
    return 0;
}