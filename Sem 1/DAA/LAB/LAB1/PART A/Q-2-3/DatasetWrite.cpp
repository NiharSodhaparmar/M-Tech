#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

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

            while (left > 0 || right < INT_MAX)
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
    struct timeval start, end;
    gettimeofday(&start, NULL);

    int N = 1000000;
    vector<int> nums;

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(0, 0xFFFFF);

    for (int i = 0; i < N; i++)
    {
        nums.push_back(abs(distribution(generator)));
    }

    cout << "Number Of duplicates in array: " << getNumberOfDuplicates(nums) << endl;

    removeDuplicateNumbers(nums);

    gettimeofday(&end, NULL);

    cout << "Number Of duplicates in array: " << getNumberOfDuplicates(nums) << endl;

    // Write data in file
    // ofstream outfile;
    // outfile.open("Dataset.txt");
    // if (!outfile)
    // { // file couldn't be opened
    //     cerr << "Error: file could not be opened" << endl;
    //     exit(1);
    // }

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     outfile << nums[i] << endl;
    // }

    // outfile.close();

    cout << "Time taken for removing duplicates" << endl;
    cout << "\tNo of seconds: " << end.tv_sec - start.tv_sec << endl;
    cout << "\tNo of micro seconds: " << end.tv_usec - start.tv_usec << endl;

    return 0;
}