#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Initialize each element as a separate set
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int n; // Number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    UnionFind uf(n);

    int m; // Number of union operations
    cout << "Enter the number of union operations: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cout << "Enter elements to union (x and y): ";
        cin >> x >> y;
        uf.unionSets(x, y);
    }

    int queries; // Number of queries to find representatives
    cout << "Enter the number of queries to find representatives: ";
    cin >> queries;

    for (int i = 0; i < queries; i++) {
        int x;
        cout << "Enter element to find representative: ";
        cin >> x;
        cout << "Representative of " << x << ": " << uf.find(x) << endl;
    }

    return 0;
}
