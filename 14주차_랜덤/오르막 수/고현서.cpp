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
int dp[1010][10];
int main(void) {
	init();
	int N;
	cin >> N;
	for (int i = 0; i < 10; i++) {
		//0��° �ڸ����� i��� ���� ���� ���
		dp[0][i] = 1;
	}
	for (int i = 1; i < N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < 10; j++) {
			//i��° �ڸ����� j�� �� ���
			//�״�� ���� �������ų� �� ���� �ø��ų� 
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans = (ans + dp[N - 1][i]) % 10007;
	}
	cout << ans;
}
