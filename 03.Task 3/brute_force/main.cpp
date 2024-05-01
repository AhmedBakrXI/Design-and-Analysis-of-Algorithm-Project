#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long ull;

int main() {
    int n;
    cin >> n;
    ull twoPowerN = pow(2, n);
    int negOnePowerN = (n % 2 == 0) ? 1 : -1;
    ull output = 2 * twoPowerN / 3 - negOnePowerN / 6 - 1 / 2;
    cout << "Output is: " << output << endl;
    return 0;
}
