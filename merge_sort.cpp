#include<iostream>
using namespace std;

void merge(int low, int mid, int high, int* A)
{
    int* B = new int[high - low + 1];
    
    int h = low;
    int j = mid + 1;
    int i = 0;

    while ((h <= mid) && (j <= high))
    {
        if (A[h] <= A[j])
        {
            B[i] = A[h];
            h = h + 1;
        }
        else
        {
            B[i] = A[j];
            j = j + 1;
        }
        i = i + 1;
    }

    while (h <= mid)
    {
        B[i] = A[h];
        i++;
        h = h + 1;
    }

    while (j <= high)
    {
        B[i] = A[j];
        i++;
        j = j + 1;
    }
    for (int k = 0; k <= high - low; k++)
    {
        A[low + k] = B[k];
    }

    delete[] B; // Free the memory allocated for B
}

void merge_sort(int low, int high, int* A)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(low, mid, A);
        merge_sort(mid + 1, high, A);
        merge(low, mid, high, A);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int* A = new int[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    merge_sort(0, n - 1, A);

    cout << "Sorted Array : ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    delete[] A; // Free the memory allocated for A

    return 0;
}
