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

int graph[100001][3];
int dp[100001][3];
int main(void) {
	int k = 1;
	int n;
	while (cin >> n && n != 0) {
		memset(dp, 1000001, sizeof(dp));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> graph[i][j];
			}
		}
		dp[0][0] = 1000003;
		dp[0][1] = graph[0][1];
		dp[0][2] = graph[0][1] + graph[0][2];
		for (int i = 1; i < n; i++) {
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + graph[i][0];
			dp[i][1] = min(min(dp[i][0], dp[i - 1][2]), min(dp[i - 1][0], dp[i - 1][1])) + graph[i][1];
			dp[i][2] = min(dp[i - 1][1], min(dp[i][1], dp[i - 1][2])) + graph[i][2];
		}
		cout << k << ". " << dp[n - 1][1] << endl;
		k++;
	}
	return 0;
}