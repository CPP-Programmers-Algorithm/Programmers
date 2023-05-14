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
#define INF 0x3f3f3f3f/3
#define endl "\n"

using namespace std;

int dp[1001][3];
int colorCost[1001][3];
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> colorCost[i][j];
		}
	}
	int ans = 100001;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			if (j == i) dp[0][i] = colorCost[0][i];
			else dp[0][i] = 10001;
		}
		for (int i = 1; i < n - 1; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + colorCost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + colorCost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + colorCost[i][2];
		}
		for (int i = 0; i < 3; i++) {
			if (j == i) continue;
			int val = 0;
			switch (i) {
			case 0:
				val = min(dp[n - 2][1], dp[n - 2][2]) + colorCost[n - 1][0];
				break;
			case 1:
				val = min(dp[n - 2][0], dp[n - 2][2]) + colorCost[n - 1][1];
				break;
			case 2:
				val = min(dp[n - 2][0], dp[n - 2][1]) + colorCost[n - 1][2];
				break;
			default:
				break;
			}
			ans = min(ans, val);
		}
	}
	cout << ans;
	return 0;
}