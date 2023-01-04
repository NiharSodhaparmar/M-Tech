#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int visited[100], j, res[100];

void adjacencyMatrix(int arr[][100], int n);
void dfs(int u, int n, int a[][100]);
void topologicalOrder(int n, int a[][100]);

int main()
{
    int a[100][100], n, i, j;

    cout << "Enter number of vertices : ";
    cin >> n;

    adjacencyMatrix(a, n);
    auto start = high_resolution_clock::now();
    topologicalOrder(n, a);
    auto end = high_resolution_clock::now();

    cout << "\tAdjacency Matrix of the graph" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "\t" << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "\tTopological order : ";
    for (i = n - 1; i >= 0; i--)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    cout << "\tTime taken for topological ordering: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

    return 0;
}

void adjacencyMatrix(int a[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            a[i][j] = 0;
        }
    }

    int tmp[2];
    while (true)
    {
        cout << "\tEnter first vertex of edge : ";
        cin >> tmp[0];
        cout << "\tEnter second vertex of edge : ";
        cin >> tmp[1];
        if (tmp[0] < 0 || tmp[1] < 0 || tmp[0] >= n || tmp[1] >= n)
            cout << '\t' << tmp[0] << "->" << tmp[1] << " refers to a non-existent node. Enter edge again." << endl;
        else
        {
            int choice;
            a[tmp[0]][tmp[1]] = 1;
            cout << endl
                 << "\tWant to add more edges (1/0) ?";
            cin >> choice;
            cout << endl;
            if (choice != 1)
                break;
        }
    }
}

void dfs(int u, int n, int a[][100])
{
    visited[u] = 1;
    for (int v = 0; v < n; v++)
    {
        if (a[u][v] == 1 && visited[v] == 0)
        {
            dfs(v, n, a);
        }
    }
    res[j] = u;
    j += 1;
}

void topologicalOrder(int n, int a[][100])
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    j = 0;
    for (int u = 0; u < n; u++)
    {
        if (visited[u] == 0)
        {
            dfs(u, n, a);
        }
    }
    return;
}