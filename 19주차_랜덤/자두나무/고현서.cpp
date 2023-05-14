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

//전환되기 전에 먹을 수 있느 자두의 갯수
vector<int> Jadu;
int dp[1001][31];
int main(void) {
	int t, w;
	cin >> t >> w;
	int pre;
	int first;
	cin >> pre;
	first = pre;
	int cnt = 1;
	for (int i = 1; i < t; i++) {
		int num;
		cin >> num;
		if (pre != num) {
			Jadu.push_back(cnt);
			cnt = 0;
			pre = num;
		}
		cnt++;
	}
	Jadu.push_back(cnt);
	if (t == 1) {
		cout << Jadu[0];
		return 0;
	}
	if (first == 1) {
		dp[0][0] = Jadu[0];
		dp[1][1] = dp[0][0] + Jadu[1];
	}
	else {
		dp[0][1] = Jadu[0];
		dp[1][0] = Jadu[1]; dp[1][2] = dp[0][1] + Jadu[1];
	}
	for (int i = 2; i < Jadu.size(); i++) {
		dp[i][0] = dp[i - 2][0] + Jadu[i];
		for (int j = 1; j <= w; j++) {
			//그대로 가져오거나 이전 값에 이동해서 가져오거나
			dp[i][j] = max(dp[i - 2][j], dp[i - 1][j - 1]) + Jadu[i];
		}
	}
	int maxAns = 0;
	for (int i = 0; i <= w; i++) {
		maxAns = max(maxAns, dp[Jadu.size() - 1][i]);
	}
	cout << maxAns;
	return 0;
}