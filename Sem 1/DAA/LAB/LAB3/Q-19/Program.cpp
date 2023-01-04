#include <iostream>
#include <chrono>
#include <algorithm>
#include <climits>
using namespace std::chrono;
using namespace std;

class EdgeKruskal
{
public:
    int scr;
    int dest;
    int weight;
};

bool compare(EdgeKruskal e1, EdgeKruskal e2)
{
    return (e1.weight < e2.weight);
}

int getParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return getParent(parent[v], parent);
}

EdgeKruskal *kruskal(EdgeKruskal *edges, int n, int E)
{
    // sort array of EdgeKruskal class in increasing order of weight
    sort(edges, edges + E, compare);

    // Output EdgeKruskal class of size (n-1)
    EdgeKruskal *output = new EdgeKruskal[n - 1];

    // Parent array to handle cycle in MST
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while (count < (n - 1))
    {
        EdgeKruskal currentEdge = edges[i];
        int scrParent = getParent(currentEdge.scr, parent);
        int destParent = getParent(currentEdge.dest, parent);

        if (scrParent != destParent)
        {
            output[count] = currentEdge;
            count += 1;
            parent[scrParent] = destParent;
        }
        i += 1;
    }
    return output;
}

int getMinVertex(bool *visited, int *wgt, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && ((minVertex == -1) || (wgt[minVertex] > wgt[i])))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int **edg, int n)
{
    bool *visited = new bool[n];
    int *parent = new int[n];
    int *weight = new int[n];

    for (int i = 0; i < n; i++)
    {
        weight[i] = INT_MAX;
        visited[i] = false;
    }

    // For Starting Vertex
    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < n; i++)
    {
        // Get minVertex from unvisited vertices
        int minVertex = getMinVertex(visited, weight, n);
        visited[minVertex] = true;

        // Check for all unvisited neighbours of minVertex and update weight and parent of that neighbour vertices
        for (int j = 0; j < n; j++)
        {
            if (edg[minVertex][j] != 0 && !visited[j])
            {
                if (weight[j] > edg[minVertex][j])
                {
                    weight[j] = edg[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    // for (int t = 1; t < n; t++)
    // {
    //     cout << parent[t] << "  " << t << " " << weight[t] << endl;
    // }

    delete[] parent;
    delete[] visited;
    delete[] weight;
}

int main()
{
    srand(time(0));
    for (int k = 10; k <= 10000; k = k * 10)
    {
        // v = number of vertices
        int v = k;

        // E = number of edges
        int E = k;

        // For Kruskal Algo
        EdgeKruskal *edgesKruskal = new EdgeKruskal[E];

        // adjMatrix for Prims Algo
        int **edgePrims = new int *[v];
        for (int i = 0; i < v; i++)
        {
            edgePrims[i] = new int[v];
            // Assign 0 to all entry in adjMatrix
            for (int j = 0; j < v; j++)
            {
                edgePrims[i][j] = 0;
            }
        }

        int temp1 = 0;
        int temp2 = 1;

        // randomly generate graph
        for (int i = 0; i < E; i++)
        {
            int s, d, w;
            s = temp1 % k;       // src
            d = temp2 % k;       // dest
            w = rand() % 10 + 1; // weight
            temp1++;
            temp2++;

            if (s == d)
            {
                i--;
            }
            else
            {
                // For Kruskal
                edgesKruskal[i].scr = s;
                edgesKruskal[i].dest = d;
                edgesKruskal[i].weight = w;

                // For Prims
                edgePrims[s][d] = w;
                edgePrims[d][s] = w;
            }
        }

        // Kruskal
        auto start = high_resolution_clock::now();
        EdgeKruskal *output = kruskal(edgesKruskal, v, E);
        auto end = high_resolution_clock::now();
        auto d_Kruskal = duration_cast<microseconds>(end - start);

        // Prims
        start = high_resolution_clock::now();
        prims(edgePrims, v);
        end = high_resolution_clock::now();
        auto d_Prims = duration_cast<microseconds>(end - start);

        cout << "Edges    : " << E << endl;
        cout << "vertices : " << v << endl;
        cout << "Time Taken by Kruskal : " << d_Kruskal.count() << " microseconds" << endl;
        cout << "Time Taken by Prims : " << d_Prims.count() << " microseconds" << endl;
        cout << endl;

        for (int i = 0; i < v; i++)
        {
            delete[] edgePrims[i];
        }
        delete[] edgePrims;
        delete[] edgesKruskal;
    }
    return 0;
}