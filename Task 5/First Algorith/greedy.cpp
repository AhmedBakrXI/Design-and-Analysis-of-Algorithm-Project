#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std; 

bool check_even(int n){
    if (n % 2 == 0) return true;
    else return false;
}

bool check_done(vector<int> &coins){
     // Check that half the vector is filled with twos while the other half consists of zeros
    int numberOfTwos = count(coins.begin(), coins.end(), 2);
    int numberOfZeroes = count(coins.begin(), coins.end(), 0);
    if (numberOfTwos == coins.size()/2 && numberOfZeroes  == coins.size()/2) 
    return true;
    else return false;
}
   

void jump(vector<int> &coins, int coin1_position, int coin2_position){
    // Update values of coins after a jump, will update value of coin that will jump to zero and the coin it will jump to two
    coins[coin1_position] = 0;
    coins[coin2_position] = 2;
}

int minimum_moves(vector<int> &coins){
    if (!check_even(coins.size())) return -1;
    int moves = 0;
    if(!check_done(coins)){
    for (int i = 0; i < coins.size(); i++){
        if (coins[i] == 1){
            int sum = 0;
            int j = 0;
            while (sum < moves + 1){
                sum += coins[i+j];
                j++;
            }
            if (coins[i+j] == 1){
                jump(coins, i , i+j );
                moves++;
            }
        }
      }
    }
    return moves;
}


int main() {
    int n;
    cout<<"Enter the number of coins: "<<endl;
    cin >> n;
    vector<int> coins(n, 1);
    int result = minimum_moves(coins);

    if (result == -1 || !check_done(coins)) {
        cout << "Not Possible!!" << endl;
        cout << "Vector contents:";
        for (int i = 0; i < coins.size(); ++i) {
            cout << " " << coins[i];
        }
    } else {
        cout << "Minimum number of moves: " << result << endl;
        // Print the vector at the end
        cout << "Vector contents:";
        for (int i = 0; i < coins.size(); ++i) {
            cout << " " << coins[i];
        }
    }
    /*
    //print possible n
    for (int i = 2; i < 100; i+=2){
        vector<int> coins_n_check(i, 1);
        minimum_moves(coins_n_check);
        if (check_done(coins_n_check)) cout<< i <<" ";
    }
    */
    return 0;
}
