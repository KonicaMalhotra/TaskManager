#include<iostream>
using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertion_sort(int arr[], int n, int& comparisons) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            comparisons++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int comparisons = 0;
    insertion_sort(arr, n, comparisons);
    cout << "Sorted array is: ";
    print_array(arr, n);
    cout << "Number of comparisons are: " << comparisons << endl;
    delete[] arr;
    return 0;
}