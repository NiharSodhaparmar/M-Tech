#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <chrono>
using namespace std;
using namespace std::chrono;

class graph
{
    list<int> *vertex_arr;
    vector<int> circuit;
    int *outgoing_edge;
    int size = 0;

public:
    graph(int v)
    {
        vertex_arr = new list<int>[v];
        this->size = v;
        outgoing_edge = new int[v];
        for (int i = 0; i < v; i++)
        {
            outgoing_edge[i] = 0;
        }
    }

    void add_edge(int a, int b)
    {
        vertex_arr[a].push_back(b);
    }

    void count_outgoing_edge()
    {
        for (int i = 0; i < size; i++)
        {
            outgoing_edge[i] = vertex_arr[i].size();
        }
    }

    vector<int> find_euler_circuit()
    {
        count_outgoing_edge();
        stack<int> s;
        int stack_top;
        s.push(0);
        while (!s.empty())
        {
            if (outgoing_edge[s.top()])
            {
                stack_top = s.top();
                s.push(vertex_arr[stack_top].front());
                vertex_arr[stack_top].pop_front();
                outgoing_edge[stack_top]--;
            }
            else
            {
                circuit.push_back(s.top());
                s.pop();
            }
        }
        return circuit;
    }

    void printAdjList()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " =  ";
            for (auto a : vertex_arr[i])
            {
                cout << a << " -> ";
            }
            cout << "Null" << endl;
        }
    }
};

int main()
{
    for (int i = 10; i <= 10000; i = i * 10)
    {
        graph g(i);
        int temp1 = 0;
        int temp2 = 1;
        for (int j = 0; j < i; j++)
        {
            g.add_edge(temp1++ % i, temp2++ % i);
        }

        auto start = high_resolution_clock::now();
        vector<int> ans = g.find_euler_circuit();
        auto end = high_resolution_clock::now();

        cout << endl;
        cout << "Edges : " << i << endl;
        cout << "Vertecies : " << i << endl;
        if (ans[0] == ans[ans.size() - 1])
            cout << "Euler circuit exist." << endl;
        else
            cout << "Euler circuit not exist." << endl;

        cout << "Time taken: " << duration_cast<microseconds>(end - start).count() << " microseconds" << endl;
    }

    return 0;
}