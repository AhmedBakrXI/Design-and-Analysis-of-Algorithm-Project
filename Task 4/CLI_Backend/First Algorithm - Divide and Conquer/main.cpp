#include <iostream>

// Function to solve Tower of Hanoi puzzle with four pegs
void towerOfHanoi(int n, char source, char destination, char auxiliary1, char auxiliary2) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        return;
    }
    if (n == 2) {
        std::cout << "Move disk 1 from " << source << " to " << auxiliary1 << std::endl;
        std::cout << "Move disk 2 from " << source << " to " << destination << std::endl;
        std::cout << "Move disk 1 from " << auxiliary1 << " to " << destination << std::endl;
        return;
    }
    // Calculate optimal value of k
    int k = n / 2;

    // Transfer k smallest disks to an intermediate peg
    towerOfHanoi(k, source, auxiliary1, auxiliary2, destination);

    // Move remaining n-k disks to the destination peg using classic Tower of Hanoi algorithm
    towerOfHanoi(n - k, source, destination, auxiliary1, auxiliary2);

    // Transfer k smallest disks to the destination peg
    towerOfHanoi(k, auxiliary1, destination, auxiliary2, source);
}

int main() {
    int n = 8; // Number of disks
    char source = 'A', auxiliary1 = 'B', auxiliary2 = 'C', destination = 'D';

    std::cout << "Moves to solve Tower of Hanoi with " << n << " disks and 4 pegs:" << std::endl;
    towerOfHanoi(n, source, destination, auxiliary1, auxiliary2);

    return 0;
}
