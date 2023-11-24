#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Function for Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    const int n = 3000; // You can change the value of n

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Filling the array with random numbers
    }

    int tempArr[n];

    // Heap Sort
    copy(begin(arr), end(arr), begin(tempArr));
    auto start = high_resolution_clock::now();
    heapSort(tempArr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Heap Sort Time: " << duration.count() << " microseconds\n";

    return 0;
}
