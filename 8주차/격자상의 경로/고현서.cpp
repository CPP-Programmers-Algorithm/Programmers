#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<deque>
#include<map>
#include<vector>
#include<cmath>
#include<climits>
#include<set>
#include<queue>
#include<list>
#include<stack>
#include<math.h>
#include<memory>
#include<sstream>
#include<unordered_map>
#define INF 0x3f3f3f3f
using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
}
int dp[16][16];
int DP(int startX, int startY, int n, int m) {
	for (int i = startX + 1; i <= m; i++) {
		dp[startY][i] = dp[startY][startX];
	}
	for (int i = startY + 1; i <= n; i++) {
		for (int j = startX; j <= m; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	return dp[n][m];
}
int main() {
	init();
	int n, m, k;
	cin >> n >> m >> k;
	dp[1][1] = 1;
	if (k == 0)
		cout << DP(1, 1, n, m);
	else {
		int kY = (k % m) == 0 ? (k / m) : (k / m) + 1;
		int kX = (k % m) == 0 ? m : (k % m);
		DP(1, 1, kY, kX);
		cout << DP(kX, kY, n, m);
	}
}