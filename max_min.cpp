#include <iostream>
using namespace std;

void MaxMin(int i, int j, int &fmax, int &fmin, int A[]) {
    if (i == j) {
        fmax = fmin = A[i];
    } else if (i == j - 1) {
        if (A[i] > A[j]) {
            fmax = A[i];
            fmin = A[j];
        } else {
            fmax = A[j];
            fmin = A[i];
        }
    } else {
        int mid = (i + j) / 2;
        int gmax, gmin, hmax, hmin;
        MaxMin(i, mid, gmax, gmin, A);
        MaxMin(mid + 1, j, hmax, hmin, A);
        fmax = max(gmax, hmax);
        fmin = min(gmin, hmin);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    int* A = new int[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int max_val, min_val;
    MaxMin(0, n - 1, max_val, min_val, A);

    cout << "Maximum value: " << max_val << endl;
    cout << "Minimum value: " << min_val << endl;

    return 0;
}
