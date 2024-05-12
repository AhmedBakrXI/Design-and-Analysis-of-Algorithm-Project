#include <iostream>
#include <string>

int calculateTotalCompositions(int arr[], int size) {
    int total = 1;
    for (int i = 0; i < size; ++i) {
        total *= arr[i];
    }
    return total;
}

void generateAllComp(int arr[], int size, int composition[], int index, std::string *compositions, int &currentIndex) {
    if (index == size) {
        std::string compStr = "[";
        for (int i = 0; i < size; ++i) {
            compStr += std::to_string(composition[i]);
            if (i < size - 1) compStr += ", ";
        }
        compStr += "]";
        compositions[currentIndex++] = compStr;
        return;
    }

    for (int i = 1; i <= arr[index]; ++i) {
        composition[index] = i;
        generateAllComp(arr, size, composition, index + 1, compositions, currentIndex);
    }
}

void printComposition(const std::string& composition) {
    std::cout << "|";
    for (size_t i = 1; i < composition.length(); i += 3) {
        std::cout << composition[i];
        if (i + 3 < composition.length()) {
            std::cout << " - ";
        }
    }
    std::cout << "|";
}

int main() {
    int arrSize;
    std::cout << "Enter the size of the array: ";
    std::cin >> arrSize;

    int *arr = new int[arrSize];

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < arrSize; ++i) {
        std::cin >> arr[i];
    }

    int numCompositions = calculateTotalCompositions(arr, arrSize);
    auto *compositions = new std::string[numCompositions];
    int currentIndex = 0;
    int *composition = new int[arrSize];
    generateAllComp(arr, arrSize, composition, 0, compositions, currentIndex);

    std::cout << "All compositions:\n";
    for (int i = 0; i < numCompositions; ++i) {
        std::cout << compositions[i] << std::endl;
    }

    // Convert strings to arrays of integers
    int** compositionsAsArrays = new int*[numCompositions];
    for (int i = 0; i < numCompositions; ++i) {
        compositionsAsArrays[i] = new int[arrSize];
        for (int j = 0; j < arrSize; ++j) {
            compositionsAsArrays[i][j] = compositions[i][j * 3 + 1] - '0';
        }
    }

    std::cout << "\nSum of absolute differences for each composition:\n";
    int maxSum = 0;
    for (int i = 0; i < numCompositions; ++i) {
        std::cout << "Composition " << i + 1 << ": ";
        printComposition(compositions[i]);
        std::cout << " = ";
        int sum = 0;
        for (int j = 2; j < arrSize; ++j) {
            sum += std::abs(compositionsAsArrays[i][j] - compositionsAsArrays[i][j - 1]);
        }
        std::cout << sum << std::endl;
        maxSum = std::max(maxSum, sum);
    }

    std::cout << "\nMaximum sum of absolute differences: " << maxSum << std::endl;

    // Free memory
    delete[] arr;
    delete[] composition;
    delete[] compositions;
    for (int i = 0; i < numCompositions; ++i) {
        delete[] compositionsAsArrays[i];
    }
    delete[] compositionsAsArrays;

    return 0;
}
