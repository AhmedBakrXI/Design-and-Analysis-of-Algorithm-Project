#include <iostream>
using namespace std;

// Helper Function
unsigned long long min_moves_helper(int n, unsigned long long* ans)
{
    // Base case
    if (n==1 || n==2) {
        return n;
    }

    // To check if output already exists
    if (ans[n] != -1) {
        return ans[n];
    }

    // Calculate output
    unsigned long long x = min_moves_helper(n -1, ans)+2* min_moves_helper(n-2,ans)+1;
    // Saving the output for future use
    ans[n] = x;

    // Returning the final output
    return ans[n];
}

unsigned long long min_moves(int n)
{
    unsigned long long* ans = new unsigned long long [n + 1];

    // Initializing with -1
    for (int i = 0; i <= n; i++) {
        ans[i] = -1;
    }
    return min_moves_helper(n, ans);
}

int main()
{
    int n=4; // Number of switches
    cout<<"Minimum number of moves to turn off "<<n<<" switches is : "<<min_moves(n);
    return 0;
}