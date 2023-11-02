#include<iostream>
using namespace std;

void adjust(int A[], int i, int n) {
        int j, item;

        j = 2 * i;
        item = A[i];

        while (j <= n) {
            if (j < n && A[j] < A[j + 1]) {
                j = j + 1;
            }
            if (item >= A[j]) {
                break;
            }
            else {
                A[j / 2] = A[j];
                j = 2 * j;
            }
        }
        A[j / 2] = item;
    }

    void heapify(int A[], int n) {
        int i;

        for (i = n / 2; i >= 1; i--)
        {
            adjust(A, i, n);
        }
    }

void heap_sort(int A[], int n)
{
    heapify(A, n);

    for (int i = n; i >= 1; i--)
    {
        int t = A[i];
        A[i] = A[1];
        A[1] = t;
        adjust(A, 1, i -1);
    }
    
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int* A = new int[n+1];

    cout << "Enter the elements of the array: ";
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    heap_sort(A, n);

    cout << "Sorted Array : ";
    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}