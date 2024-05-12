#include <iostream>

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;     // Index for left subarray
    int j = mid + 1;  // Index for right subarray
    int k = left;     // Index for merged subarray
    int invCount = 0; // Inversion count

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // Count inversions
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

int mergeSort(int arr[], int temp[], int left, int right) {
    int invCount = 0;

    if (left < right) {
        int mid = (left + right) / 2;
        invCount += mergeSort(arr, temp, left, mid);
        invCount += mergeSort(arr, temp, mid + 1, right);
        invCount += merge(arr, temp, left, mid, right);
    }

    return invCount;
}

int inversionCount(int arr[], int n) {
    int temp[n];
    return mergeSort(arr, temp, 0, n - 1);
}

int main() {
    int arr[] = {10, 1, 4, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int invCount = inversionCount(arr, n);

    std::cout << "Inversion count: " << invCount << std::endl;

    return 0;
}