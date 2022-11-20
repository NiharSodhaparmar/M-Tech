#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int getNumberOfDuplicates(vector<int> &nums)
{
    int numberOfDuplicates = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int a = abs(nums[i]);
        if (nums[a] < 0)
        {
            numberOfDuplicates++;
        }
        else
        {
            nums[a] = -1 * nums[a];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            nums[i] = -1 * nums[i];
        }
    }

    return numberOfDuplicates;
}

void removeDuplicateNumbers(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> uniqueValues;

    for (int i = 0; i < n; i++)
    {
        // if value is not found in unique set
        if (uniqueValues.find(nums[i]) == uniqueValues.end())
        {
            uniqueValues.insert(nums[i]);
        }
        else
        {
            int left = nums[i] - 1;
            int right = nums[i] + 1;

            while (left > 0 || right < n)
            {
                if (left > 0)
                {
                    // left nearest value not found in set
                    if (uniqueValues.find(left) == uniqueValues.end())
                    {
                        nums[i] = left;
                        uniqueValues.insert(left);
                        break;
                    }
                    left--;
                }

                // right nearest value not found in set
                if (uniqueValues.find(right) == uniqueValues.end())
                {
                    nums[i] = right;
                    uniqueValues.insert(right);
                    break;
                }
                right++;
            }
        }
    }
}

int main()
{

    int N = 1000000;
    vector<int> nums;

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(0, 0xFFFFF);

    for (int i = 0; i < N; i++)
    {
        nums.push_back(abs(distribution(generator)));
    }

    auto start = high_resolution_clock::now();
    int numberOfDuplicates = getNumberOfDuplicates(nums);
    auto end = high_resolution_clock::now();

    cout << "Before" << endl;
    cout << "\tSize of array: " << nums.size() << endl;
    cout << "\tNumber Of duplicates in array: " << numberOfDuplicates << endl;

    cout << "Time taken for find duplicates" << endl;
    cout << "\tNo of seconds: " << duration<double>(end - start).count() << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;

    start = high_resolution_clock::now();
    removeDuplicateNumbers(nums);
    end = high_resolution_clock::now();

    cout << "After removing duplicates" << endl;
    cout << "\tSize of array: " << nums.size() << endl;
    cout << "\tNumber Of duplicates in array: " << getNumberOfDuplicates(nums) << endl;

    cout << "Time taken for removing duplicates" << endl;
    cout << "\tNo of seconds: " << duration<double>(end - start).count() << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;

    return 0;
}