#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;

void dijkstra(const vector<vector<int>>& graph, int start, vector<int>& dist) {
    int n = graph.size();
    vector<bool> visited(n, false);

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF) {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, INF, 1, INF},
        {2, 0, 4, INF, 5},
        {INF, 4, 0, 3, INF},
        {1, INF, 3, 0, 6},
        {INF, 5, INF, 6, 0}
    };

    int startVertex = 0;
    int numVertices = graph.size();

    vector<int> dist(numVertices, INF);

    dijkstra(graph, startVertex, dist);

    cout << "Shortest distances from vertex " << startVertex << ":\n";
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ": " << dist[i] << "\n";
    }

    return 0;
}
