#include <iostream>
#include <iomanip>

struct Pairs
{
    int x, y, sum;

    Pairs() : x(0), y(0), sum(0){};

    Pairs(int x, int y) : x(x), y(y) {
        sum = x + y;
    }
};

void sumPair(Pairs arr[], int size)
{
    if (size == 0)
        return;

    bool freqArr[size * 1000];
    std::fill_n(freqArr, size * 1000, false);
    for (int i = 0; i < size; i++)
    {
        if (!freqArr[arr[i].sum])
        {
            freqArr[arr[i].sum] = true;
        }
    }
}

int main()
{
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    if (size < 2)
    {
        std::cout << "Array size must be at least 2." << std::endl;
        return 1;
    }

    int *inputArray = new int[size];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> inputArray[i];
    }

    auto *pairsArray = new Pairs[size * (size - 1) / 2];

    int pairIndex = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            pairsArray[pairIndex++] = Pairs(inputArray[i], inputArray[j]);
        }
    }

    int min = pairsArray[0].sum;
    int max = pairsArray[0].sum;

    for (int i = 0; i < size * (size - 1) / 2; i++) {
        if (pairsArray[i].sum < min) {
            min = pairsArray[i].sum;
        }
        if (pairsArray[i].sum > max) {
            max = pairsArray[i].sum;
        }
    }

    int frequency[max - min + 1] = {0};
    for (int i = 0; i < size * (size - 1) / 2; i++) {
        int index = pairsArray[i].sum - min;
        frequency[index]++;
    }

    auto pairArraySize = size * (size - 1) / 2.0;
    sumPair(pairsArray, (int)pairArraySize);

    std::cout << std::left << std::setw(10) << "SUM" << std::left << std::setw(10) << "Pairs_Count" << std::right << std::setw(10) << "Pairs" << std::endl;

    for (int i = min; i <= max; i++)
    {
        std::cout << std::left << std::setw(10) << i << std::left << std::setw(10) << frequency[i - min] << std::setw(7);

        for (int j = 0; j < frequency[i - min]; j++)
        {
            for (int k = j; k < size * (size - 1) / 2; k++) {
                if (pairsArray[k].sum == i) {
                    std::cout  << std::right << "{" << pairsArray[k].x << ", " << pairsArray[k].y << "} ";
                    break;
                }
            }

        }

        std::cout << std::endl;
    }

    delete[] inputArray;
    delete[] pairsArray;

    return 0;
}