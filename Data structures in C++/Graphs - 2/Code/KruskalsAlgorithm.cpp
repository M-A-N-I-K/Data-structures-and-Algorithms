#include <iostream>
#include <algorithm>
using namespace std;

class edge
{
public:
    int source;
    int destination;
    int weight;
};

bool compare(edge e1, edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int vertex, int *parent)
{
    if (parent[vertex] == vertex)
    {
        return vertex;
    }
    return findParent(parent[vertex], parent);
}

void KruskalsAlgorithm(edge *input, int n, int e)
{
    sort(input, input + e, compare);
    edge *output = new edge[n - 1];
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int count = 0, i = 0;
    while (count != n - 1)
    {
        edge currEdge = input[i];

        // Check if we can add current edge in MST or not
        int sourceParent = findParent(currEdge.source, parent);
        int destParent = findParent(currEdge.destination, parent);

        if (sourceParent != destParent)
        {
            output[count] = currEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].destination)
        {
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
        }
    }
    delete[] output;
    delete[] parent;
}

int main()
{
    int n, e;
    cin >> n >> e;
    edge *input = new edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
    }
    KruskalsAlgorithm(input, n, e);
    delete[] input;
}