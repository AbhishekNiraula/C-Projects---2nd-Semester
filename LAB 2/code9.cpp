/* LAB 2

    Create a 'MATRIX' class of size m X n. Overload the ‘+’ operator to   Add Two MATRIX objects. Write a main function to implement it. */

#include <iostream>
#include <cstring>
using namespace std; 
#define MAX 5

class Matrix
{
    int m;
    int n;
    int mat[MAX][MAX];
    public:
        Matrix(int mi= 0, int ni=0) : m(mi), n(ni)
        {
            for (int i = 0; i < mi; i++) {
                for (int j = 0; j < mi; j++) 
                {
                    mat[i][j] = 0;
                }
            }
        }

        friend istream& operator>> (istream &is, Matrix &m1)
        {
            int row, col;
            cout << "Enter row length: ";
            cin >> row;
            cout  << "Enter column length: ";
            cin >> col;
            cout << "Enter matrix: " << endl;
            m1.m = row;
            m1.n = col;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) 
                {
                    cout << "Enter element [" << i << "]" << "[" << j << "]" << ": ";
                    is >> m1.mat[i][j];
                }
            }
            return is;
        }

        Matrix operator+(Matrix mat2)
        {
            Matrix temp(m, n);
            if (m != mat2.m || n != mat2.n)
            {
                cout << "Input Matrix can't be added." << endl;
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    temp.mat[i][j] = mat[i][j] + mat2.mat[i][j];
                }
            }
            return temp;
        }
        void output()
        {
            if (m == 0 && n == 0)
            {
                cout << "No Matrix Found." << endl;
                exit;
            }
            else {
                cout << "Matrix: " << endl;
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        cout << "a[" << i << "]" << "[" << j << "] : " << mat[i][j] << "  "; 
                    }
                    cout << endl;
                }
            }
        }
};
int main()
{
    Matrix m1;
    cin >> m1;
    m1.output();
    cout << endl << endl << endl;
    Matrix m2;
    cin >> m2;

    cout << endl << endl << endl;
    Matrix m3 = m1 + m2;
    m3.output();
}