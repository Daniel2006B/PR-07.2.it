#include <iostream>
#include <climits>
#include <ctime>
#include <cstdlib>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int FindMinInRow(int* row, const int n);
int FindSumOfMinElements(int** a, const int k, const int n);

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    int Low = -25;
    int High = 25;
    int k, n;

    cout << "Enter the number of rows (k): ";
    cin >> k;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);

    cout << "Matrix:" << endl;
    Print(a, k, n);

    int sumOfMinElements = FindSumOfMinElements(a, k, n);

    cout << "Sum of minimum elements in each row: " << sumOfMinElements << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int FindMinInRow(int* row, const int n)
{
    int minElement = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        minElement = (row[i] < minElement) ? row[i] : minElement;
    }

    return minElement;
}


int FindSumOfMinElements(int** a, const int k, const int n)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        int minInRow = FindMinInRow(a[i], n);
        sum += minInRow;
    }
    return sum;
}
