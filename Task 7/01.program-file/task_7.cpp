#include <iostream>
#include <vector>
#include <climits>

int minShotsToHitTarget(int n) {
    // Initialize the DP array with maximum values, except for the first hiding spot
    std::vector<int> DP(n + 1, INT_MAX);
    DP[1] = 0;  // Base case: no shots needed to hit the target at the first spot

    // Iterate through all hiding spots
    for (int i = 2; i <= n; ++i) {
        // Consider all possible positions for the target to move
        for (int j = 1; j < i; ++j) {
            // Update DP[i] based on the minimum shots needed from the previous hiding spot
            DP[i] = std::min(DP[i], 1 + std::max(DP[j], DP[i-j]));
        }
    }

    // The final result is the minimum shots needed to hit the target at the last hiding spot
    return DP[n];
}

int main() {

    int n =6;  // Number of hiding spots
    int result = minShotsToHitTarget(n);
    std::cout << "Minimum shots needed to guarantee hitting the target: " << result << std::endl;

    return 0;
}
