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
string Sum(string a, string b) {
	string big = a.size() > b.size() ? a : b;
	string small = a.size() > b.size() ? b : a;
	reverse(big.begin(), big.end());
	reverse(small.begin(), small.end());

	vector<char> ans;
	int overflow = 0;
	for (int i = 0; i < small.size(); i++) {
		int sum = overflow + (big[i] - 48) + (small[i] - 48);
		overflow = sum / 10;
		sum %= 10;
		ans.push_back((char)(sum + 48));
	}
	for (int j = small.size(); j < big.size(); j++) {
		int sum = overflow + (big[j] - 48);
		overflow = sum / 10;
		sum %= 10;
		ans.push_back((char)(sum + 48));
	}
	if (overflow != 0)
		ans.push_back((char)(overflow + 48));
	string ret = "";
	for (int i = ans.size() - 1; i >= 0; i--) {
		ret += ans[i];
	}
	return ret;
}

string dp[10001];
string DP(int x) {
	if (x == 0) return "0";
	if (x == 1) return "1";
	if (dp[x] != "-1") return dp[x];
	return dp[x] = Sum(DP(x - 1), DP(x - 2));
}

int main() {
	init();
	int n;
	cin >> n;
	fill(&dp[0], &dp[n + 1], "-1");
	cout << DP(n);
}