#include <iostream>
using namespace std;

// Helper Function
int min_switch_helper(int n, int* ans)
{
    // Base case
    if (n == 1) {
        return 1;
    }
    if(n==2){
        return 2;
    }

    // To check if output already exists
    if (ans[n] != -1) {
        return ans[n];
    }

    // Calculate output
    int x = min_switch_helper(n -1, ans)+2* min_switch_helper(n-2,ans)+1;
    // Saving the output for future use
    ans[n] = x;

    // Returning the final output
    return ans[n];
}

int min_switch(int n)
{
    int* ans = new int[n + 1];

    // Initializing with -1
    for (int i = 0; i <= n; i++) {
        ans[i] = -1;
    }
    return min_switch_helper(n, ans);
}

int main()
{
    int n = 4; // number of switches

    cout << "Minimum number of moves needed to turn off all switches : "<< min_switch(n);
    return 0;
}