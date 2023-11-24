#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function for Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    const int n = 3000; // You can change the value of n

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Filling the array with random numbers
    }

    int tempArr[n];

    // Merge Sort
    copy(begin(arr), end(arr), begin(tempArr));
    auto start = high_resolution_clock::now();
    mergeSort(tempArr, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Merge Sort Time: " << duration.count() << " microseconds\n";

    return 0;
}
