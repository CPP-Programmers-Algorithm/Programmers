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

int dp[10001][4];
int main(void)
{
	int tc;
	cin >> tc;
	vector<int> testCase;
	int maxN = 0;
	for (int t = 0; t < tc; t++) {
		int n;
		cin >> n;
		testCase.push_back(n);
		maxN = maxN < n ? n : maxN;
	}
	dp[1][1] = 1;
	dp[2][2] = 1; dp[2][1] = 1;
	dp[3][3] = 1; dp[3][2] = 1; dp[3][1] = 1;

	for (int i = 4; i <= maxN; i++) {
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}
	for (int i = 0; i < testCase.size(); i++) {
		cout << dp[testCase[i]][1] + dp[testCase[i]][2] + dp[testCase[i]][3] << endl;
	}
}