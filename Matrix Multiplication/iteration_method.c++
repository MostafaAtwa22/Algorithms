#include <iostream>
using namespace std;

const int n = 4;
void multiply (int A[][n] , int B[][n] , int C [][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main (void)
{
    
    cout << "Enter the number of rows of and cols : ";
    int A[n][n];
    int B[n][n];
    int C[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter the elements of (B) !\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> B[i][j];
        }
    }

    cout << "The Multiply Result !\n";
    multiply (A , B , C);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << C[i][j] << ' ';
        }
        cout << '\n';
    }
}