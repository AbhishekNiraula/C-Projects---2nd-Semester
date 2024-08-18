/* LAB 4

    Hybrid Inheritance Example - Virtual - Diamond Inheritance problem

*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char const *subject[7] = {"Maths", "Physics", "Chemistry", "Geography", "Social Studies", "Nepali", "English"};
float total_marks = 875;

class Student
{
    protected:
        int roll_no;
        string name;
    public:
        void getInfo()
        {
            cout << "Enter student's name: ";
            getline(cin, name);
            cout << "Enter student's roll number: ";
            cin >> roll_no;
            cin.ignore();
        }
        void outInfo()
        {
            cout << "Student's Name: " << name << endl << "Roll Number: " << roll_no << endl; 
        }
};
class InternalExam : virtual public Student 
{
    protected:
        float marks[7];
    public:
        void getInfo()
        {
            cout << endl << endl << "Enter Internal exam marks: " << endl;
            for (int i = 0; i < 7; i++)
            {
                cout  << subject[i] << " Marks:  ";
                cin >> marks[i];
            }
        }
        void outInfo()
        {
            cout << endl << endl << "Internal exam marks: " << endl;
            for (int i = 0; i < 7; i++)
            {
                cout  << subject[i] << " :  " << marks[i] << endl;
            }
        }
};
class FinalExam : virtual public Student
{
    protected:
        float Fmarks[7];
    public:
        void getInfo()
        {
            cout << endl << endl << "Enter Final exam marks: " << endl;
            for (int i = 0; i < 7; i++)
            {
                cout  << subject[i] << " Marks:  ";
                cin >> Fmarks[i];
            }
        }
        void outInfo()
        {
            cout << endl << endl << "Final exam marks: " << endl;
            for (int i = 0; i < 7; i++)
            {
                cout  << subject[i] << " :  " << Fmarks[i] << endl;
            }
        }
};
class AvgMarks : public InternalExam, public FinalExam 
{
    float avgPer;
    public:
        void getInfo()
        {
            Student::getInfo();
            InternalExam::getInfo();
            FinalExam::getInfo();
            float total_Inmarks = 0;
            float total_FnMarks = 0;
            for (int i = 0; i < 7; i++)
            {
                total_Inmarks += marks[i];
                total_FnMarks += marks[i];
            }
            avgPer = ((total_FnMarks + (0.25 * total_Inmarks)) / total_marks) * 100;
        }
        void outInfo()
        {
            cout << endl << endl << "--Aggregate Marksheet--" << endl << endl << endl;
            Student::outInfo();
            InternalExam::outInfo();
            FinalExam::outInfo();
            cout << endl << endl << name << "'s Final Grade in Percentage: " << avgPer <<"%" << endl << endl; 
        }
};

int main()
{
    AvgMarks s1;
    s1.getInfo();
    s1.outInfo();

    return 0;
}