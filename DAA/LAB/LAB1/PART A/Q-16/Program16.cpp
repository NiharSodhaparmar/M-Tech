#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string, int> &a,
             pair<string, int> &b);

int main()
{
    vector<pair<string, int>> players = {
        {"Player01", 22},
        {"Player02", 16},
        {"Player03", 20},
        {"Player04", 18},
        {"Player05", 4},
        {"Player06", 9},
        {"Player07", 17},
        {"Player08", 5},
        {"Player09", 3},
        {"Player10", 6},
        {"Player11", 19},
        {"Player12", 7},
        {"Player13", 11},
        {"Player14", 15},
        {"Player15", 8},
        {"Player16", 2},
        {"Player17", 21},
        {"Player18", 10},
        {"Player19", 12},
        {"Player20", 13},
        {"Player21", 1},
        {"Player22", 14},
    };

    cout << "Given Player Statistics" << endl;
    for (auto &it : players)
    {

        cout << it.first << "\t" << it.second << endl;
    }
    cout << endl;

    // sort players
    sort(players.begin(), players.end(), compare);

    cout << "Team A" << endl;
    for (int i = 0; i < players.size() / 2; i++)
    {
        cout << players[i].first << "\t" << players[i].second << endl;
    }

    cout << endl;
    cout << "Team B" << endl;
    for (int i = (players.size() / 2); i < players.size(); i++)
    {
        cout << players[i].first << "\t" << players[i].second << endl;
    }
}

bool compare(pair<string, int> &a,
             pair<string, int> &b)
{
    return a.second < b.second;
}