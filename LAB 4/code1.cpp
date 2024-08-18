/* LAB 4
    Assume class person stores the Name, Age and ID, class employee
    stores the designation, basic salary, total overtime(hr) in a month
    and hourly rate and class computedSalary stores the total salary of
    the employee. Implement above concept using appropriate inheritance.
*/


#include<iostream>
using namespace std;


class Person
{
    char name[50];
    int age;
    int id;   
    public:
        void get_info()
        {
            cout << "Enter employee name: ";
            cin >> name;
            cout << "Enter employee age: ";
            cin >> age;
            cout << "Enter employee id: ";
            cin >> id;        
        }
        void out_info()
        {
            cout << "Employee name: " << name << endl << "Employee age: " << age << endl << "Employee id: " << id << endl;
        }
};
class Employee: public Person
{
    protected:
        char designation[50];
        float bas_salary;
        int overtime;
        float hr_rate;
    public:
        void get_info()
        {
            cout << "Enter employee designation: ";
            cin >> designation;
            cout << "Enter employee basic salary: ";
            cin >> bas_salary;
            cout << "Enter employee overtime hours in a month: ";
            cin >> overtime;
            cout << "Enter employee hourly rate: ";
            cin >> hr_rate;        
        }
        void out_info()
        {
            cout << "Employee designation: " << designation << endl << "Employee basic salary: " << bas_salary << endl << "Employee overtime hours: " << overtime << endl << "Employee hourly rate: " << hr_rate << endl;
        }
};
class computedSalary: public Employee
{
    float total_salary;
    public:
        void get_info()
        {
            Person::get_info();
            Employee::get_info();
            float gross_sal = bas_salary + overtime * hr_rate;
            total_salary = gross_sal - 0.3 * gross_sal;
        }
        void out_info()
        {
            Person::out_info();
            Employee::out_info();
            cout << "Employee total salary: " << total_salary << endl;
        }
};

int main()
{
    computedSalary s1;
    s1.get_info();
    s1.out_info();
    return 0;
}