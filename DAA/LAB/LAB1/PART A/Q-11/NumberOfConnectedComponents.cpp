#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int n;
    vector<int> *adj;
    void DFS(int v, bool visited[], vector<int> &a);

public:
    Graph(int n);

    void addEdge(int u, int v);
    int NumberOfconnectedComponents();
};

int Graph::NumberOfconnectedComponents()
{
    bool *visited = new bool[n];
    vector<int> a;
    vector<int> ans;
    int count = 0;
    for (int v = 0; v < n; v++)
        visited[v] = false;

    for (int v = 0; v < n; v++)
    {
        a.clear();
        if (visited[v] == false)
        {
            DFS(v, visited, a);
            count += 1;
            ans.push_back(a.size());
        }
    }

    sort(ans.begin(), ans.end());

    cout << "sizes of the connected components : ";
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << "  ";
    }
    cout << endl;

    return count;
}

void Graph::DFS(int v, bool visited[], vector<int> &a)
{
    visited[v] = true;
    a.push_back(v);

    for (auto child : adj[v])
    {
        if (!visited[child])
        {
            DFS(child, visited, a);
        }
    }
}

Graph::Graph(int n)
{
    this->n = n;
    adj = new vector<int>[n];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Driver code
int main()
{
    Graph g(6);
    g.addEdge(1, 3);
    g.addEdge(0, 4);
    g.addEdge(5, 4);

    int c = g.NumberOfconnectedComponents();

    cout << "No. of connected components: " << c << endl;

    return 0;
}