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
#include <cstring>
using namespace std;

class Inventory
{
    private:
        int quant; // number on hand
        int reorder; // reorder quantity
        double price; // price per unit
        char const *descrip; // description of item

    public:
        Inventory(int q, int r, double p, char const *d)
        { 
            // initialize data members 
            quant = q;
            reorder = r;
            price = p;
            descrip = new char[strlen(d) + 1];
            strcpy(const_cast<char *>(descrip), d);
        }
        ~Inventory()
        { 
            //release dynamically allocated memory
            delete[] descrip;
        }
        void print()
        {
            cout << "Available quantity: " << quant << endl << "Quantity on reorder: " << reorder << endl << "Price per unit: $" << price << endl << "Description: " << descrip << endl;
        }
};

// first derived class


class Auto : public Inventory
{
    char const *manufacturer;
    public:
        Auto (int q, int r, double p, char const * d, char const *man): Inventory(q, r, p, d)
        { //initialize base and derive members
            manufacturer = new char[strlen(man) + 1];
            strcpy(const_cast<char *>(manufacturer), man);
        }
        void print()
        {
            Inventory::print();
            cout << "Manufacturer: " << manufacturer << endl;
        }
        ~Auto()
        {
            delete[] manufacturer;
        }
};

// Second derived class

class Transmission : public Inventory
{
    char const *vendor;
    public:
        Transmission (int q, int r, double p, char const *d, char const * ven): Inventory(q, r, p, d)
        {
            vendor = new char[strlen(ven) + 1];
            strcpy(const_cast<char *>(vendor), ven);
        }
        void print()
        {
            Inventory::print();
            cout << "Vendor: " << vendor << endl;
        }
        ~ Transmission (){
            delete[] vendor;
        }
};

int main()
{
    char const *desc = "From the Toyota";
    char const *manu = "Toyota";
    Auto car(5, 2, 15545.91, desc, manu);
    car.print();

    cout << endl << endl << endl;

    desc = "From the Aztec";
    char const *vend = "Aztec Inc.";
    Transmission aztec(25, 10, 1789.98, desc, vend);
    aztec.print();
    return 0;
}