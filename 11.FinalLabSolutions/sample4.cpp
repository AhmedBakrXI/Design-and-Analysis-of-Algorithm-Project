#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;
const int N = 1e6;
bool visited[N] = {false};
int arr[N];
int min_sum = INT32_MAX;
vector<int> res, cur;
int n, x;

void solve(int i, int xs, int sum) {
    if (sum > min_sum)
        return;
    if (i + xs == n + x) {
        if (sum < min_sum) {
            min_sum = sum;
            res = cur;
        }
        return;
    }

    if (i < n) {
        cur.push_back(arr[i]);
        if (cur.size() > 1) {
            solve(i + 1, xs, sum + abs(cur[cur.size() - 2] - cur[cur.size() - 1]));
        } else {
            solve(i + 1, xs, sum);
        }
        cur.pop_back();
    }

    if (xs < x) {
        for (int j = 1; j <= x; j++) {
            if (!visited[j]) {
                visited[j] = true;
                cur.push_back(j);
                if (cur.size() > 1) {
                    solve(i, xs + 1, sum + abs(cur[cur.size() - 2] - cur[cur.size() - 1]));
                } else {
                    solve(i, xs + 1, sum);
                }

                visited[j] = false;
                cur.pop_back();
            }
        }
    }
}

int main() {
    cin >> x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    solve(0, 0, 0);

    cout << min_sum << '\n';
    for (int num: res) {
        cout << num << ' ';
    }
}

