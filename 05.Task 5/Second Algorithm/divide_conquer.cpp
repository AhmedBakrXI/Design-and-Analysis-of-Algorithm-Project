#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*bool check_possible(int n) {
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
}*/

bool check_possible(int n) {if(n%4 == 0) return 1; return 0;}

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



int minimum_moves(int coins[], int n, int counter = 4) {
    // Base case: if there are only 4 coins, return 1 move
    if (n == 4) {
        jump(coins, counter-2 , counter-4);
        jump(coins, counter-1 , counter-3);
        return counter/2;
    }
    
    jump(coins, counter-2 , counter-4);
    jump(coins, counter-1 , counter-3);
    counter = counter + 4;
    //keep calling recursively using the new counter
    return minimum_moves(coins,n - 4, counter);
}

int main() {
     int n;
    cout << "Enter the number of coins: " << endl;
    cin >> n;
    int *coins = new int(n);
    for (int i = 0; i < n; i++) {
        coins[i] = 1;
    }
    

    if(!check_possible(n)){
        cout << "Not Possible!!" << endl;
        cout << "Array contents:";
        for (int i = 0; i < n; ++i) {
            cout << " " << coins[i];
        } 
    }

    else {
        int result = minimum_moves(coins, n);
        cout << "\nMinimum number of moves: " << result << endl;
        // Print the array at the end
        cout << "\nArray contents:";
        for (int i = 0; i < n; ++i) {
            cout << " " << coins[i];
        }
    }

    delete[] coins;
    return 0;
}
