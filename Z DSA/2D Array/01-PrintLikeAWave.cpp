#include <iostream>
#include <vector>
using namespace std;

int ROW = 2;
int COL = 2;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int col = 0; col < mCols; col++)
    {
        if (col % 2 == 0)
        {
            for (int row = 0; row < nRows; row++)
            {
                ans.push_back(arr[row][col]);
            }
        }
        else
        {
            for (int row = nRows - 1; row >= 0; row--)
            {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 2}, {3, 4}};
    vector<int> ans = wavePrint(arr, ROW, COL);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}