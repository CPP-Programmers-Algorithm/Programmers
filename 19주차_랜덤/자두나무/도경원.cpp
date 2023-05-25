#include <iostream>
#include <algorithm>
using namespace std;
//자두나무

int dp[3][1001][32];//자두나무 위치, 자두가 떨어지는 초, 움직이는 횟수
int arr[1001];      //자두 떨어지는 나무 정보

void solve() {
    int t; cin >> t;
    int w; cin >> w;
    int ans = 0;

    for (int i = 1; i <= t; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= t; i++) {
        int appleTree = arr[i];
        for (int j = 1; j <= w + 1; j++) {
            if (appleTree == 2 && i == 1 && j == 1) continue;

            dp[1][i][j] = max(dp[1][i - 1][j], dp[2][i - 1][j - 1]);
            dp[2][i][j] = max(dp[1][i - 1][j - 1], dp[2][i - 1][j]);

            dp[appleTree][i][j]++;
        }
    }
    for (int i = 1; i <= w + 1; i++) {
        ans = max(ans, max(dp[1][t][i], dp[2][t][i]));
    }
    cout << ans;
}

int main() {
    solve();
}