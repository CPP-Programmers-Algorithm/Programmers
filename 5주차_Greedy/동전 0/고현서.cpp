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

int main() {
	init();
	int n, k;
	cin >> n >> k;
	vector<int> coin;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		coin.push_back(a);
	}
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (k >= coin[i]) {
			cnt += k / coin[i];
			k %= coin[i];
		}
	}
	cout << cnt;
}