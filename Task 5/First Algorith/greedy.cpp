#include <iostream>
#include <cmath>

using namespace std;

bool check_possible(int n) {
    if (n > 0) {
        // loop to 31 as higher numbers cannot be represented as int
        for (int i = 2; i < 31; i++) {
            if (n == (pow(2, i)) - 2) {
                return true;
            }
        }
        return false;
    } else return false;
}

bool check_done(int coins[], int size) {
    // Check that half the array is filled with twos while the other half consists of zeros
    int numberOfTwos = 0, numberOfZeroes = 0;
    for (int i = 0; i < size; i++) {
        if (coins[i] == 2) numberOfTwos++;
        else if (coins[i] == 0) numberOfZeroes++;
    }
    return numberOfTwos == size / 2 && numberOfZeroes == size / 2;
}

void jump(int coins[], int coin1_position, int coin2_position) {
    // Update values of coins after a jump, will update value of coin that will jump to zero and the coin it will jump to two
    coins[coin1_position] = 0;
    coins[coin2_position] = 2;
}

int minimum_moves(int coins[], int size) {
    if (!check_possible(size)) return -1;
    int moves = 0;
    if (!check_done(coins, size)) {
        for (int i = 0; i < size; i++) {
            if (coins[i] == 1) {
                int sum = 0;
                int j = 0;
                while (sum < moves + 1) {
                    sum += coins[i + j];
                    j++;
                }
                if (coins[i + j] == 1) {
                    jump(coins, i, i + j);
                    moves++;
                }
            }
        }
    }
    return moves;
}

int main() {
    int n;
    cout << "Enter the number of coins: " << endl;
    cin >> n;
    int coins[n];
    for (int i = 0; i < n; i++) {
        coins[i] = 1;
    }
    int result = minimum_moves(coins, n);

    if (result == -1 || !check_done(coins, n)) {
        cout << "Not Possible!!" << endl;
        cout << "Array contents:";
        for (int i = 0; i < n; ++i) {
            cout << " " << coins[i];
        }
    } else {
        cout << "Minimum number of moves: " << result << endl;
        // Print the array at the end
        cout << "Array contents:";
        for (int i = 0; i < n; ++i) {
            cout << " " << coins[i];
        }
    }
    return 0;
}
