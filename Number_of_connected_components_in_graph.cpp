#include <bits/stdc++.h>
using namespace std;

// Making Graph
class Graph
{
public:
    unordered_map<int, bool> visited;  //To keep track of visited elements
    unordered_map<int, list<int>> adj; // Adjacency list

    void addEdge(int v, int w); // function for adding edge to the graph
    void DFS(int v);            // depth first search using v as first node
};
//Defining addEdge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
    visited[v]=false;       // Initializing visited with false
    visited[w]=false;
}
void Graph ::DFS(int v)
{
    visited[v] = true;      //marking as visited

    for (auto i = adj[v].begin(); i != adj[v].end(); i++)
        if (!visited[*i])
        {
            DFS(*i);
        }
}
int main()
{
    int count = 1; // Number of connected components
    Graph g;

    // --Example--

//         1
//        /  
//        2
//       / \
//      3   4

//      6      8
//     /        \
//    7          9     Have three connected components

    g.addEdge(1, 2);       
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(6, 7);
    g.addEdge(8,9);

    g.DFS(1);
    for (auto i = g.visited.begin(); i != g.visited.end(); i++)
    {
        if (i->second == false)    //If not visited then it's a new connected component
        {
            g.DFS(i->first);    
            count++;
        }
    }
    cout<<count<<endl;
    //output --> 3
    return 0;
}
