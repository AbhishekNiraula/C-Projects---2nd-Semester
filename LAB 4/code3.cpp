/* LAB 4

    Modify Q.2 to add base class sales that holds an array of three
    floats so that it can record the dollar sales of a particular
    publication for the last three months. Include getdata() function to
    get three Sales amount from the user and a putdata() function to
    display sales figures. Alter the book and tape classes so they are
    derived from both publication and sales. An object of class book or
    tape should input and output sales data along with its other data.

*/

#include <iostream>
#include <string>
using namespace std;

class Publication
{
    string title;
    float price;

    public:
        void getData()
        {
            cout << "Enter your book title: " << endl;
            getline(cin, title);
            cout << "Enter price of the book: " << endl;
            cin >> price;
            // To ignore the buffer left in the memory
            cin.ignore();
        }
        void putData()
        {
            cout << "Title:  " << title << endl << "Price:  Nrs." << price << endl;
        }
};


class Sales {

    float sales[3];

    public:
        void getData() {
            cout << "Enter sales for the last three months:" << endl;
            for (int i = 0; i < 3; i++) 
            {
                cout << "Month " << i + 1 << ": ";
                cin >> sales[i];
            }
        }

        void putData() {
            cout << "Sales for the last three months:" << endl;
            for (int i = 0; i < 3; i++) 
            {
                cout << "Month " << i + 1 << ": " << sales[i] << endl;
            }
        }
};

class Book: public Publication, public Sales
{
    int page_count;

    public:
        void getData(){
            Publication::getData();
            Sales::getData();
            cout << "Enter page count: ";
            cin >> page_count;
            cin.ignore();
        }

        void putData(){
            Publication::putData();
            Sales::putData();
            cout << "Page count: " << page_count << endl;
        }
};

class Tape: public Publication, public Sales
{
    int playing_time;
    
    public:
        void getData() {
            Publication::getData();
            Sales::getData();
            cout << "Enter playing time (in minutes): ";
            cin >> playing_time;
            cin.ignore();
        }

        void putData() {
            Publication::putData();
            Sales::putData();
            cout << "Playing time: " << playing_time << " minutes" << endl;
        }
};


int main()
{
    Book b1;
    Tape t1;

    cout << "Enter details for book:" << endl;
    b1.getData();

    cout << "Enter details for tape:" << endl;
    t1.getData();

    cout << "Book details: " << endl;
    b1.putData();

    cout << endl << endl << endl;

    cout << "Tape details:  " << endl;
    t1.putData();


    return 0;
}