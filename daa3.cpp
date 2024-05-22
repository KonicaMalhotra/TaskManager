//Write a program to sort the elements of an array using Heap Sort (The program should report the number of//
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, int &comparisons) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    comparisons++;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    comparisons++;
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, comparisons);
    }
}

void heapSort(int arr[], int n, int &comparisons) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, comparisons);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int comparisons = 0;
    heapSort(arr, n, comparisons);
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nNumber of comparisons are: " << comparisons << endl;
    return 0;
}
