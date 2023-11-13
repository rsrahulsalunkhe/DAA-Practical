#include <iostream>
#include <stack>
#include <queue>

using namespace std;

const int MAX_VERTICES = 100;

class Graph {
private:
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];

public:
    Graph(int V) {
        vertices = V;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void DFS(int startVertex) {
        bool visited[vertices] = {false};
        stack<int> stk;

        stk.push(startVertex);

        while (!stk.empty()) {
            int u = stk.top();
            stk.pop();

            if (!visited[u]) {
                visited[u] = true;
                cout << "DFS Visited vertex: " << u << endl;

                for (int v = 0; v < vertices; v++) {
                    if (adjMatrix[u][v] == 1 && !visited[v]) {
                        stk.push(v);
                    }
                }
            }
        }
    }

    void BFS(int startVertex) {
        bool visited[vertices] = {false};
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int u = q.front();
            cout << "Visited vertex: " << u << endl;
            q.pop();

            for (int v = 0; v < vertices; v++) {
                if (adjMatrix[u][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
};

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    Graph G(V);

    for (int i = 0; i < V-1; i++)
    {
        cout << "Enter Edges x and y " << endl;
        int x, y;
        cin >> x >> y;
        G.addEdge(x,y);
    }
    

    int startVertex = 0;

    cout << "Depth-First Traversal starting from vertex " << startVertex << ":" << endl;
    G.DFS(startVertex);

    cout << "Breadth-First Traversal starting from vertex " << startVertex << ":" << endl;
    G.BFS(startVertex);

    return 0;
}
