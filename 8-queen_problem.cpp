#include <iostream>
#include <cmath>

using namespace std;

const int N = 8;

bool place(int k, int X[]) {
    for (int i = 1; i < k; i++) {
        if (X[i] == X[k] || abs(X[i] - X[k]) == abs(i - k)) {
            return false;
        }
    }
    return true;
}

void printBoard(int X[]) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (X[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

void nQueens(int n) {
    int X[N + 1];
    X[1] = 0;
    int k = 1;
    int lastSolution[N + 1];

    while (k > 0) {
        X[k]++;
        while (X[k] <= n && !place(k, X)) {
            X[k]++;
        }

        if (X[k] <= n) {
            if (k == n) {
                // Store the last solution
                for (int i = 1; i <= n; i++) {
                    lastSolution[i] = X[i];
                }
            } else {
                k++;
                X[k] = 0;
            }
        } else {
            k--;
        }
    }

    // Print all solutions
    printBoard(lastSolution);
}

int main() {
    nQueens(N);

    return 0;
}
