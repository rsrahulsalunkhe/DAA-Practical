#include <iostream>
#include <vector>
using namespace std;

const int MaxSize = 100;

vector<int> parent(MaxSize, -1);

int FIND(int i) {
    int j = i;
    while (parent[j] > 0) {
        j = parent[j];
    }
    int k, t;
    while (i != j) {
        k = i;
        t = parent[k];
        parent[k] = j;
        i = t;
    }
    return j;
}

void UNION(int i, int j) {
    int x = parent[i] + parent[j];
    if (parent[i] > parent[j]) {
        parent[i] = j;
        parent[j] = x;
    } else {
        parent[j] = i;
        parent[i] = x;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
    }

    int operation;
    do {
        cout << "1. UNION\n2. FIND\n3. Exit\n";
        cout << "Enter operation (1/2/3): ";
        cin >> operation;

        if (operation == 1) {
            int i, j;
            cout << "Enter i and j for UNION: ";
            cin >> i >> j;
            UNION(i, j);
        } else if (operation == 2) {
            int i;
            cout << "Enter i for FIND: ";
            cin >> i;
            cout << "The representative of the set containing element " << i << " is " << FIND(i) << endl;
        }
    } while (operation != 3);

    return 0;
}
