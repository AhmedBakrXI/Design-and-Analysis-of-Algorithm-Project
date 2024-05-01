#include <iostream>
using namespace std;

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

void traditionalThreePeg(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "\n Move disk " << n << " from rod " << source << " to rod " << destination;
        return;
    }
    traditionalThreePeg(n - 1, source, auxiliary, destination);
    cout << "\n Move disk " << n << " from rod " << source << " to rod " << destination;
    traditionalThreePeg(n - 1, auxiliary, destination, source);
}

void fourPegAlgorithm(int n, char source, char destination, char auxiliary1, char auxiliary2) {
    if (n == 0)
        return;
    if (n == 1) {
        cout << "\n Move disk " << n << " from rod " << source << " to rod " << destination;
        return;
    }

    int k = largestK(n);

    fourPegAlgorithm(n - k, source, auxiliary1, auxiliary2, destination);

    traditionalThreePeg(k, source, destination, auxiliary1);

    fourPegAlgorithm(n - k, auxiliary2, destination, auxiliary1, source);
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

    // A, B, C and D are names of rods
    fourPegAlgorithm(n, 'A', 'D', 'B', 'C');
    return 0;
}
