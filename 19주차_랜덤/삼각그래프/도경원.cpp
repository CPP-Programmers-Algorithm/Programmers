#include <bits/stdc++.h>
using namespace std;
//»ï°¢±×·¡ÇÁ

typedef long long ll;

const int INF = 987654321;
int arr[100000][3];
ll dp[100000][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	for (int tt = 1;; ++tt) {
		int n;
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < 3; ++j)
				cin >> arr[i][j];

		dp[0][0] = INF;
		dp[0][1] = arr[0][1];
		dp[0][2] = dp[0][1] + arr[0][2];

		for (int i = 1; i < n; ++i) {
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
			dp[i][1] = min({ dp[i][0], dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] }) + arr[i][1];
			dp[i][2] = min({ dp[i][1], dp[i - 1][1], dp[i - 1][2] }) + arr[i][2];
		}

		cout << tt << ". " << dp[n - 1][1] << '\n';
	}

	return 0;
}