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
#define INF 0x3f3f3f3f
using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
}
int n;
int ans = 0;
void DP(int num, int cnt) {
	if (cnt >= n) {
		if (num % 3 == 0)
			ans++;
		return;
	}
	if (num != 0)
		DP(num * 10, cnt + 1);
	DP(num * 10 + 1, cnt + 1);
	DP(num * 10 + 2, cnt + 1);
}
void Sol2() {
	int cache[10];
	cache[1] = 0;
	cache[2] = 2;
	for (int i = 3; i <= n; i++) {
		cache[i] = (cache[i - 1] * 3);
	}
	cout << cache[n];
}
int main() {
	init();
	cin >> n;
	Sol2();
	//DP(0, 0);
	//cout << ans;

}