#include <iostream>
using namespace std;

// Global variable to track the number of moves
int moveCount = 0;

int sumInt(int n) {
    return (n * (n + 1)) / 2;
}

int largestK(int n) {
    int k = 1;
    while (sumInt(k) <= n) {
        k++;
    }
    return k - 1;
}

void traditionalThreePeg(int n, char source, char destination, char auxiliary, int startDisk, int endDisk) {
    if (n == 1) {
        cout << "Move disk " << startDisk << " from rod " << source << " to rod " << destination << endl;
        moveCount++;
        return;
    }
    traditionalThreePeg(n - 1, source, auxiliary, destination, startDisk, endDisk - 1); // Update endDisk
    cout << "Move disk " << endDisk << " from rod " << source << " to rod " << destination << endl;
    moveCount++;
    traditionalThreePeg(n - 1, auxiliary, destination, source, startDisk, endDisk - 1); // Update endDisk
}

void fourPegAlgorithm(int n, char source, char destination, char auxiliary1, char auxiliary2) {
    if (n == 0)
        return;
    if (n == 1) {
        cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
        moveCount++;
        return;
    }

    int k = largestK(n);

    fourPegAlgorithm(n - k, source, auxiliary1, auxiliary2, destination);

    traditionalThreePeg(k, source, destination, auxiliary2, n - k + 1, n);

    fourPegAlgorithm(n - k, auxiliary1, destination, auxiliary2, source);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <number of disks>" << endl;
        return 1;
    }

    int n = atoi(argv[1]); // Number of disks

    // Determine the correct value of k
    int k = largestK(n);
    cout << "Optimal value of k for n = " << n << ": " << k << endl;
    cout << "------------------------------------------------" << endl;

    // A, B, C and D are names of rods
    fourPegAlgorithm(n, 'A', 'D', 'B', 'C');

    // Print the total number of moves
    cout << "------------------------------------------------" << endl;
    cout << "Total moves made: " << moveCount << endl;

    return 0;
}
