/* LAB 4
    Create a class publication that stores the title and price of a
    publication. From this class derive two classes:book, which adds a
    page count and tape, which adds a playing time in minutes. Each of
    these three classes should have getdata() function to get its data
    from the user at the keyboard and putdata() function to display its
    data.
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

class Book: public Publication
{
    int page_count;

    public:
        void getData(){
            Publication::getData();
            cout << "Enter page count: ";
            cin >> page_count;
            cin.ignore();
        }

        void putData(){
            Publication::putData();
            cout << "Page count: " << page_count << endl;
        }
};

class Tape: public Publication
{
    int playing_time;
    
    public:
        void getData() {
            Publication::getData();
            cout << "Enter playing time (in minutes): ";
            cin >> playing_time;
            cin.ignore();
        }

        void putData() {
            Publication::putData();
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