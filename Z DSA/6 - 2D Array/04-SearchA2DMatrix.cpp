#include <iostream>
#include <vector>
using namespace std;

class Solution
{

private:
    bool binarySearch(vector<vector<int>> matrix, int start, int end, int row, int col, int target)
    {
        if (start <= end)
        {

            int mid = start + (end - start) / 2;

            int element = matrix[mid / col][mid % col];

            if (element == target)
                return true;

            if (target < element)
                return binarySearch(matrix, start, mid - 1, row, col, target);
            else
                return binarySearch(matrix, mid + 1, end, row, col, target);
        }

        return false;
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        return binarySearch(matrix, 0, row * col - 1, row, col, target);
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};

    int target = 13;
    Solution sol = Solution();

    cout << target << " is found? : " << (sol.searchMatrix(matrix, target) ? "TRUE" : "FALSE") << endl;
}