// lab 7.3(2).cpp 
// Опрацювання динамічних багатовимірних масивів 
// Сацик Вікторії
// 20 варіант
// Ітераційний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Part2_SaddlePoint(int** a, const int rowCount, const int colCount);
bool IsMaxInRowN(int** a, const int n, const int k, const int colCount);
bool IsMinInColK(int** a, const int n, const int k, const int rowCount);
int main()
{
    srand((unsigned)time(NULL));
    int Low = -5;
    int High = -27;
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Part2_SaddlePoint(a, rowCount, colCount);
    cout << endl;
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

bool IsMaxInRowN(int** a, const int n, const int k, const int colCount)
{
    for (int j = 0; j < colCount; j++)
        if (a[n][j] > a[n][k])
        {
            return false;
        }
    return true;
}
bool IsMinInColK(int** a, const int n, const int k, const int rowCount)



{
    for (int i = 0; i < rowCount; i++)
        if (a[i][k] < a[n][k])
        {
            return false;
        }
    return true;
}
void Part2_SaddlePoint(int** a, const int rowCount, const int colCount)
{
    cout << "Saddle points: max in row & min in col" << endl;
    cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
    int No = 0;
    for (int n = 0; n < rowCount; n++)
        for (int k = 0; k < colCount; k++)
            if (IsMaxInRowN(a, n, k, colCount) && IsMinInColK(a, n, k, rowCount))
            {
                cout << setw(4) << ++No << setw(6) << n << setw(6) << k << endl;
            }
}
