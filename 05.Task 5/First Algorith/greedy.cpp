#include <iostream>

using namespace std;

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

bool move_possible(int coins[],int pos1,int pos2, int moveNum){
        if (coins[pos1] && coins[pos2] != 1) return 0;
        int sum = 0;
        for (int i = pos1 + 1; i < pos2; i++) {
           sum += coins[i];
        }
        if (sum == moveNum) return 1; return 0;
}

int minimum_moves(int coins[], int size) {
    if (!check_possible(size)) return -1;
    int move = 1;
    int count = size - 1;
    for (int k = 0; k < ((size/4) - 1); k++){
        while(coins[count] != 1) { count--;}
        for (int j = count - 1 ; j > 0 ; j--){
            if (move_possible(coins,j,count,move)){
                jump(coins,j,count);
                move++;
                count--;

                cout << "\nArray contents:";
                for (int i = 0; i < size; ++i) {
                    cout << " " << coins[i];
                }
                break;
            }
        }
    }
    for(int k = 0; k < 3 * size / 4 ; k++){
        if(coins[k] != 1) { continue;}
        for (int j = k+1 ; j < size ; j++){
            if (move_possible(coins,k,j,move)){
                jump(coins,k,j);
                move++;

                cout << "\nArray contents:";
                for (int i = 0; i < size; ++i) {
                    cout << " " << coins[i];
                }
                break;

            }
        }
    }
    return move - 1;
}

int main() {
    int n;
    cout << "Enter the number of coins: " << endl;
    cin >> n;
    int *coins = new int(n);
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
