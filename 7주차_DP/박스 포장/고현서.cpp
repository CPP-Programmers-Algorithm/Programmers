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
#define INF 0x3f3f3f3f
using namespace std;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
int dp[5001];
int card[5001];
int DP(int idx) {
	if (dp[idx] != -1)
		return dp[idx];
	dp[idx] = 1;
	for (int i = idx - 1; i >= 0; i--) {
		if (card[idx] > card[i]) {
			int cnt = DP(i) + 1;
			dp[idx] = max(dp[idx], cnt);
		}
	}
	return dp[idx];
}
int main() {
	init();
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	int maxCnt = 1;
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		maxCnt = max(maxCnt, DP(i));
	}
	cout << maxCnt;
}