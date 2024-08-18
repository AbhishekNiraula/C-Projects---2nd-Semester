// Object Oriented Programming - C++ LAB 1

// LAB 1 - Program 1


// Write a program to segregate Employees based on designation

#include <iostream>
#include <cstring>
using namespace std;

class EMPLOYEE {
    int empid;
    string empName;
    char post[30];
    public:
        void getData()
        {
            cout << "Enter Employee ID: ";
            cin >> empid;
            cout << "Enter Employee Name: " ;
            cin >> empName;
            cout << "Enter Employee Designation: ";
            cin >> post;
        }
        int checkDesignation()
        {
            if (strcmp(post, "ENGINEER") == 0)
            {
                return 1;
            }
            else if (strcmp(post, "MANAGER") == 0)
            {
                return 0;
            }
            


    
        }
};

int main()
{
    EMPLOYEE employee[10];
    int countEng = 0, countManager = 0, countEmp;
    cout << "Enter the number of employees you want to upload: " << endl;
    cin >> countEmp;
    for (int i = 0; i < countEmp; i++)
    {
        employee[i].getData();
    }
    for (int j = 0; j < countEmp; j++)
    {
        if (employee[j].checkDesignation() == 1)
        {
            countEng++;
        }
        else if (employee[j].checkDesignation() == 0)
        {
            countManager++;
        }
    }
    if (countEng == 0)
    {
        cout << "The number of MANAGERS is: " << countManager << ". There are no ENGINEERS. \n" << "The total number of employees is: " << countEmp << endl;
    }
    else if (countManager == 0)
    {
        cout << "The number of ENGINEERS is: " << countEng << ". There are no MANAGERS. \n" << "The total number of employees is: " << countEmp << endl;
    }
    else
    {
        cout << "The number of MANAGERS is: " << countManager << ". The number of ENGINEERS is: " << countEng  << ". The total number of employees is: " << countEmp << endl;
    }
    return 0;
}
