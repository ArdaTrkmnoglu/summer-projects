#include <iostream>
using namespace std;

// quadratic time complexity function: O(n^2)

void selectionSort(int arr[], int size);

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: \n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    selectionSort(arr, size);
    
    cout << "Sorted array: \n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}