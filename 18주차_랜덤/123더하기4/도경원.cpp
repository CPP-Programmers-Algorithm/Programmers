//https://www.acmicpc.net/problem/15989

#include <iostream>
using namespace std;
int dp[10001][10001];

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n; cin >> n;
		int sum = 0;
		int ans = 0;
		int n2 = n / 2;
		int n3 = n / 3;

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n2; j++) {
				//if (sum > n) break;
				for (int k = 0; k <= n3; k++) {
					//if (sum > n) break;
					sum = (1 * i) + (2 * j) + (3 * k);
					if (sum == n) ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}