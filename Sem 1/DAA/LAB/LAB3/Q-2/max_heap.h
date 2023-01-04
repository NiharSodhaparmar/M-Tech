#include <vector>
using namespace std;

void max_heapify(vector<int> &v, vector<int> &e, int s, int node)
{
    int max = node;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;

    if (left_child < s && v[max] < v[left_child])
    {
        max = left_child;
    }
    if (right_child < s && v[max] < v[right_child])
    {
        max = right_child;
    }

    if (max != node)
    {
        swap(v[max], v[node]);
        swap(e[max], e[node]);
        max_heapify(v, e, s, max);
    }
}

void make_max_heap(vector<int> &v, vector<int> &e, int s)
{
    for (int i = s / 2 - 1; i >= 0; i--)
    {
        max_heapify(v, e, s, i);
    }
}

void max_heapsort(vector<int> &v, vector<int> &e, int s)
{
    make_max_heap(v, e, s);
    for (int i = s - 1; i > 0; i--)
    {
        swap(v[i], v[0]);
        swap(e[i], e[0]);
        max_heapify(v, e, i, 0);
    }
}