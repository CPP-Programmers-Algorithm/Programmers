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
int dp[11];
int n, m;
int DP(int x, int cnt) {
	if (x == n) return 1;
	dp[x] = 0;
	for (int i = 0; i <= m - cnt; i++) {
		//i°³¸¦ ÈÉÃÆÀ» ¶§, °æ¿ìÀÇ ¼ö
		dp[x] += DP(x + 1, cnt + i);
	}
	return dp[x];
}
int main() {
	init();
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	m -= n;
	cout << DP(1, 0);

}