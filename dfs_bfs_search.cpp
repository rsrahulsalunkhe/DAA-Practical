#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V; // Number of vertices

    // Pointer to an array containing adjacency lists
    list<int>* adj;

public:
    Graph(int V); // Constructor

    void addEdge(int v, int w); // Function to add an edge to the graph

    void BFS(int s); // Breadth-First Search starting from vertex s
    void DFS(int s); // Depth-First Search starting from vertex s
    void DFSUtil(int v, vector<bool>& visited);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    // Create a vector to mark visited vertices
    vector<bool> visited(V, false);

    // Create a queue for BFS
    queue<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push(s);

    while (!queue.empty()) {
        // Dequeue a vertex from the queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop();

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent has not been visited, mark it visited and enqueue it
        for (auto adjacent : adj[s]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push(adjacent);
            }
        }
    }
}

void Graph::DFSUtil(int v, vector<bool>& visited) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    for (auto adjacent : adj[v])
        if (!visited[adjacent])
            DFSUtil(adjacent, visited);
}

void Graph::DFS(int s) {
    // Create a vector to mark visited vertices
    vector<bool> visited(V, false);

    // Call the recursive helper function to print DFS traversal
    DFSUtil(s, visited);
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Breadth-First Traversal starting from vertex 2: ";
    g.BFS(2);
    cout << endl;

    cout << "Depth-First Traversal starting from vertex 2: ";
    g.DFS(2);
    cout << endl;

    return 0;
}
