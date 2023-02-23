#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row * col;
        int count = 0;

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;

        vector<int> ans;

        while (count < total)
        {
            for (int i = startingCol; i <= endingCol && count < total; i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            for (int i = startingRow; i <= endingRow && count < total; i++)
            {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;

            for (int i = endingCol; i >= startingCol && count < total; i--)
            {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            for (int i = endingRow; i >= startingRow; i--)
            {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Solution sol = Solution();
    vector<int> ans = sol.spiralOrder(matrix);

    cout << "Spiral Order: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}