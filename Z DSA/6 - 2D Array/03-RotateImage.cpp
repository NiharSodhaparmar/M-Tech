#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = i; j < col; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < row; i++)
        {
            int left = 0;
            int right = col - 1;

            while (left < right)
            {
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {{5, 1, 9, 11},
                                  {2, 4, 8, 10},
                                  {13, 3, 6, 7},
                                  {15, 14, 12, 16}};
    int row = matrix.size();
    int col = matrix[0].size();

    Solution sol = Solution();
    sol.rotate(matrix);

    cout << "Rotated Matrix: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}