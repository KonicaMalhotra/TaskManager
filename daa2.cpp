#include <iostream>
using namespace std;

int mergeSort(int arr[], int left, int right, int &comparisons) {
    if (left >= right) {
        return 0;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid, comparisons);
    mergeSort(arr, mid + 1, right, comparisons);
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];
    while (i <= mid && j <= right) {
        comparisons++;
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
    return 0;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int comparisons = 0;
    mergeSort(arr, 0, n - 1, comparisons);
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nNumber of comparisons are: " << comparisons << endl;
    return 0;
}