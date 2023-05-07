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

int dp[1001][1001];
int arr[1001][1001];
int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < a.length(); j++) {
			arr[i][j + 1] = a[j] - '0';
		}
	}
	int maxCnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 0) continue;
			dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
			maxCnt = max(maxCnt, dp[i][j]);
		}
	}
	cout << maxCnt * maxCnt;
}