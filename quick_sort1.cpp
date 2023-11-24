#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int n = 3000; // You can change the value of n

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Filling the array with random numbers
    }

    int tempArr[n];

    // Quick Sort
    copy(begin(arr), end(arr), begin(tempArr));
    auto start = high_resolution_clock::now();
    quickSort(tempArr, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Quick Sort Time: " << duration.count() << " microseconds\n";

    return 0;
}
