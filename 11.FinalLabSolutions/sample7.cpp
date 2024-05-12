#include <iostream>

int sumOfEvenSubsets(int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        int currentSum = 0;
        for (int j = i; j < size; j++) {
            currentSum += arr[j];
            if ((j - i + 1) % 2 == 0) {
                sum += currentSum;
            }
        }
    }

    return sum;
}

int main() {
    int k[] = {1, 4, 2, 5};
    int size = sizeof(k) / sizeof(k[0]);

    int sum = sumOfEvenSubsets(k, size);

    std::cout << "The sum of all subsets with an even number of integers: " << sum << std::endl;

    return 0;
}
