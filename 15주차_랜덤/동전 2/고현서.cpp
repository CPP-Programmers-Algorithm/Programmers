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

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
//���ڸ� ����µ� �ּ� ������ ����
int dp[10001];
vector<int> coins;
int main(void) {
	init();
	int n, k;
	cin >> n >> k;
	memset(dp, 10001, sizeof(dp));
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num > 10000) continue;
		coins.push_back(num);
		dp[num] = 1;
	}
	sort(coins.begin(), coins.end());
	for (int i = 0; i < coins.size(); i++) {
		for (int j = coins[i] + 1; j <= k; j++) {
			//j���� ��ġ�� ����µ��� coins[i]�� ������� ��, �� ���� ���� ������ ���� �� �ִ°�?
			dp[j] = min(dp[j], dp[j - coins[i]] + dp[coins[i]]);
		}
	}
	if (dp[k] >= 10001)
		cout << -1;
	else
		cout << dp[k];
	return 0;
}
