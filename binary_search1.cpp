#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

// Binary Search function
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Element not found
}

// Function to measure execution time
double measureExecutionTime(int arr[], int size, int target) {
    auto start = chrono::high_resolution_clock::now();

    int result = binarySearch(arr, 0, size - 1, target);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return duration.count();
}

int main() {
    const int n1 = 1000;
    const int n2 = 2000;
    const int n3 = 3000;

    int arr1[n1], arr2[n2], arr3[n3];

    // Initializing arrays with sorted elements
    for (int i = 0; i < n1; ++i) arr1[i] = i;
    for (int i = 0; i < n2; ++i) arr2[i] = i;
    for (int i = 0; i < n3; ++i) arr3[i] = i;

    int target = 500; // Change this value to the element you want to search

    // Measure execution time for array of size n1
    double time1 = measureExecutionTime(arr1, n1, target);
    cout << "Time taken for n=" << n1 << ": " << time1 << " microseconds" << endl;

    // Measure execution time for array of size n2
    double time2 = measureExecutionTime(arr2, n2, target);
    cout << "Time taken for n=" << n2 << ": " << time2 << " microseconds" << endl;

    // Measure execution time for array of size n3
    double time3 = measureExecutionTime(arr3, n3, target);
    cout << "Time taken for n=" << n3 << ": " << time3 << " microseconds" << endl;

    return 0;
}
