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
using namespace std;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
long long dp[91];
long long DP(int x) {
	if (x == 0) return 0;
	if (x == 1) return 1;
	if (dp[x] != -1) return dp[x];
	return dp[x] = DP(x - 1) + DP(x - 2);
}
int main() {
	init();
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	cout << DP(n);
}