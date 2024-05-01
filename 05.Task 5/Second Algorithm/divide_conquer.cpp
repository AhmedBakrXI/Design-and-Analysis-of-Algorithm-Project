#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool check_possible(int n) {
    if (n>0){
        // loop to 31 as higher numbers cannot be represented as int
        for (int i = 2; i<31; i++){
            if (n == (pow (2,i)) -2) {
                return 1;
            }
        }
        return 0;
    }
    else return 0;
}

int minimum_moves(int n, int counter = 1) {
    // Base case: if there are only 2 coins, return 1 move
    if (n == 2) {
        return counter;
    }
    // Increment counter if not base case
    counter++;
    //keep calling recursively using the new counter
    return minimum_moves(n - 2, counter);
}

int main() {
    int n;
    cout << "Enter the number of coins: " << endl;
    cin >> n;

    if (!check_possible(n)) {
        cout << "Not Possible!!" << endl;
    } else {
		int result = minimum_moves(n);
        cout << "Minimum number of moves: " << result << endl;
    }

    return 0;
}
