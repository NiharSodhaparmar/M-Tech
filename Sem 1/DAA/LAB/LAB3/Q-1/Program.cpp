#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

string getSmallestLexicographicalOrder(string s);

int main()
{
    string s;
    char x;
    vector<int> n = {100, 1000, 10000, 100000};
    srand(time(0));

    for (int k = 0; k < n.size(); k++)
    {

        s.clear();
        for (int i = 0; i < n[k]; i++)
        {
            x = (char)(97 + (rand() % 26));
            s = s + x;
        }

        auto start = high_resolution_clock::now();
        string ans = getSmallestLexicographicalOrder(s);
        auto end = high_resolution_clock::now();

        cout << "Smallest in lexicographical order among all possible results: " << ans << endl;
        cout << "Time taken for string of length " << s.length() << ": " << duration_cast<microseconds>(end - start).count() << " microseconds" << endl;
        cout << endl;
    }
}

string getSmallestLexicographicalOrder(string s)
{
    string res = "";
    int count[26] = {0};
    int visited[26] = {0};
    int n = s.length();

    for (int i = 0; i < s.length(); i++)
    {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < n; i++)
    {
        count[s[i] - 'a']--;

        if (!visited[s[i] - 'a'])
        {
            while (res.size() > 0 && res.back() > s[i] && count[res.back() - 'a'] > 0)
            {
                visited[res.back() - 'a'] = 0;
                res.pop_back();
            }

            res += s[i];
            visited[s[i] - 'a'] = 1;
        }
    }

    return res;
}