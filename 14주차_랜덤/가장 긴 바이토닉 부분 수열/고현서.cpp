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
int main(void) {
	init();
	int arr[1001];

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int dp1[1001];
	fill(&dp1[0], &dp1[n], 1);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j])
				dp1[j] = max(dp1[j], dp1[i] + 1);
		}
	}

	int dp2[1001];
	fill(&dp2[0], &dp2[n], 1);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] < arr[j])
				dp2[j] = max(dp2[j], dp2[i] + 1);
		}
	}
	int maxCnt = 0;
	for (int i = 0; i < n; i++) {
		maxCnt = max(maxCnt, dp1[i] + dp2[i]);
	}
	cout << maxCnt - 1;

	return 0;
}
