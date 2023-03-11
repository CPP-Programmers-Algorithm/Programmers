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

int dp[16];
vector<int> term;
vector<int> price;
int n;
int maxPrice = 0;
int dpSearch(int x) {
	if (dp[x] != -1) return dp[x];
	dp[x] = price[x - 1];
	for (int i = x + term[x - 1]; i <= term.size(); i++) {
		if (i + term[i - 1] - 1 > n) continue;
		int sum = price[x - 1] + dpSearch(i);
		dp[x] = max(dp[x], sum);
	}
	return dp[x];
}
int main() {
	init();
	cin >> n;
	fill(&dp[0], &dp[n + 1], -1);
	for (int i = 1; i <= n; i++) {
		int t; int p;
		cin >> t >> p;
		term.push_back(t);
		price.push_back(p);
	}
	for (int i = 1; i <= n; i++) {
		if (i + term[i - 1] - 1 > n) continue;
		maxPrice = max(maxPrice, dpSearch(i));
	}
	cout << maxPrice;
}