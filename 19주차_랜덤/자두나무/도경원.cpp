#include <iostream>
#include <algorithm>
using namespace std;
//�ڵγ���

int dp[3][1001][32];//�ڵγ��� ��ġ, �ڵΰ� �������� ��, �����̴� Ƚ��
int arr[1001];      //�ڵ� �������� ���� ����

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