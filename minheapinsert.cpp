#include <iostream>
using namespace std;

class Heap {
public:
    int arr[100];
    int size = -1;

    void insert(int value) {
        size = size + 1;
        int index = size;
        int parentIndex = (index - 1) / 2;

        while (index > 0 && arr[parentIndex] > value) {
            arr[index] = arr[parentIndex];
            index = parentIndex;
            parentIndex = (parentIndex - 1) / 2;
        }
        arr[index] = value;
    }

    void printHeap() {
        for (int i = 0; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;

    while (true) {
        cout << "Enter your choice" << endl;
        cout << "1. insert node in min heap" << endl;
        cout << "2. print min heap" << endl;
        cout << "3. exit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            int node;
            cout << "Enter a value : ";
            cin >> node;
            h.insert(node);
        } else if (choice == 2) {
            h.printHeap();
        } else {
            break;
        }
    }

    return 0;
}
