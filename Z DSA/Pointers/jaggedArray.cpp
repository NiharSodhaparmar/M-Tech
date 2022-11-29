#include <iostream>
using namespace std;

int main()
{
    int row;
    cout << "Enter number of rows: ";
    cin >> row;

    int *column = new int[row];

    int **arr = new int *[row];

    for (int i = 0; i < row; i++)
    {
        cout << "Enter columns for row " << i << " ";
        cin >> column[i];
        arr[i] = new int[column[i]];
    }

    cout << "Enter data for matrix: " << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column[i]; j++)
        {
            cout << i << " " << j << " : ";
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
}