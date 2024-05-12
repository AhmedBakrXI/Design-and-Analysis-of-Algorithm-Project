#include <iostream>
#include <cstring>

void merge(char* arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char* L[n1];
    char* R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    // Traverse through both arrays
    while (i < n1 && j < n2) {
        if (strcmp(L[i], "3") == 0) {
            arr[k] = L[i];
            i++;
        } else if (strcmp(R[j], "3") == 0) {
            arr[k] = R[j];
            j++;
        } else if (strcmp(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[] if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[] if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(char* arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void rearrangeDigits(char* arr[], int size) {
    // Sort the array
    mergeSort(arr, 0, size - 1);
}

int main() {
    const char* digits[] = {"2", "1", "3", "4", "3", "2", "1", "3", "4"};
    int size = sizeof(digits) / sizeof(digits[0]);

    rearrangeDigits(const_cast<char**>(digits), size);

    std::cout << "Rearranged digits: ";
    for (int i = 0; i < size; i++) {
        std::cout << digits[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
