#include <iostream>
using namespace std;

// quasilinear runtime complexity function: O(n.logn)

void mergeSort(int arr[], int size);
void mergeArrays(int leftArr[], int rightArr[], int arr[], int size);

int main() {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: \n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, size);
    
    cout << "Sorted array: \n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

void mergeSort(int arr[], int size) {

    if (size <= 1)
        return;
    
    int middle = size / 2;
    int leftArr[middle];
    int rightArr[size - middle];

    int i = 0;
    int j = 0;

    for (i = 0; i < size; i++) {
        if (i < middle) {
            leftArr[i] = arr[i];
        }
        else {
            rightArr[j] = arr[i]; 
            j++;
        }
    }
    mergeSort(leftArr, middle);
    mergeSort(rightArr, size - middle);
    mergeArrays(leftArr, rightArr, arr, size);
}

void mergeArrays(int leftArr[], int rightArr[], int arr[], int size) {

    int leftSize = size / 2;
    int rightSize = size - leftSize;
    int i = 0;
    int l = 0;
    int r = 0;

    while (l < leftSize && r < rightSize) {
        if (leftArr[l] < rightArr[r]) {
            arr[i] = leftArr[l];
            i++;
            l++;
        }
        else {
            arr[i] = rightArr[r];
            i++;
            r++;
        }
    }

    while (l < leftSize) {
        arr[i] = leftArr[l];
        i++;
        l++;
    }
    
    while (r < rightSize) {
        arr[i] = rightArr[r];
        i++;
        r++;     
    }
    
}