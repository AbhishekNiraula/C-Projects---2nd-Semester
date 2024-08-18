// Object Oriented Programming - C++ LAB 1

// LAB 1 - Program 1

/* Program: given that EMPLOYEE class contains following member: data members: Employee number, employee name, Basic, DA, IT, Net Salary and print data members. */

#include <iostream>
#include <cstring>
using namespace std;

class EMPLOYEE {
    int id;
    char empName[30];
    int BS;
    int IT;
    int DA;
    int gross_salary;
    int net_salary;
    public:
        void get_info()
        {
            cout << "Enter your Employee ID: " << endl;
            cin >> id;
            cout << "Enter your name: ";
            cin >> empName;
            cout << "Enter your Basic Salary : " << endl;
            cin >> BS;
            DA = 0.53 * BS;
            gross_salary = DA + BS;
            IT = 0.30 * gross_salary;
            net_salary = gross_salary - IT;
        }
        void output()
        {
            cout << "Employee ID: " << id << endl;
            cout << "Employee Name: " << empName << endl;
            cout << "Basic Salary: " << BS << endl;
            cout << "Gross Salary: " << gross_salary << endl;
            cout << "Daily Allowances: " << DA << endl;
            cout << "Net Salary" << net_salary << endl;           
        }
};

int main()
{
    EMPLOYEE e[10];
    int n;
    cout << "Enter the number of employees you want to record: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        e[i].get_info();
    }
    for (int i = 0; i < n; i++)
    {
        e[i].output();
    }
    return 0;
}