#include <iostream>
using namespace std;

class Heap {
public:
    void insert(int A[], int n) {
        int i, j, item;
        j = n;
        i = n/2;
        item = A[n];

        while (i > 0 && A[i] < item) {
            A[j] = A[i];
            j = i;
            i = i / 2;
        }
        A[j] = item;
    }

    void BuildMaxHeap(int A[], int n) {
        for (int i = 2; i <= n; i++) {
            insert(A, i);
        }
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int* A = new int[n + 1];

    cout << "Enter the elements of the array: ";
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    Heap h;
    h.BuildMaxHeap(A, n);

    cout << "Max Heap: ";
    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}