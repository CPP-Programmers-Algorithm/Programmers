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
int cost[1001];
int n;
int dp[1001];
int main(void) {
	init();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dp[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= floor(n / i); j++) {
			//자기 자신으로만 이루어진 것들을 업데이트
			dp[i * j] = max(dp[i * j], dp[i] * j);

		}
		//자신 이전의 인덱스들과 자신의 인덱스의 위치의 cost합으로 상위 인덱스의 cost 예측 가능 
		for (int j = 1; j <= i; j++) {
			if (i + j > n) break;
			dp[i + j] = max(dp[i + j], dp[i] + dp[j]);
		}
	}
	cout << dp[n];
}
