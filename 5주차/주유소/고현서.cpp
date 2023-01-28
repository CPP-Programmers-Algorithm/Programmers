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
	int n;
	cin >> n;
	vector<int> roads;
	vector<int> ju;
	for (int i = 0; i < n - 1; i++) {
		int d;
		cin >> d;
		roads.push_back(d);
	}
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		ju.push_back(c);
	}
	//맨 마지막 주유소는 신경쓰지 말자
	ju.pop_back();

	long long ans = 0;
	long long sum = 0;
	int roadCnt = 0;
	for (int i = 0; i < ju.size() - 1; i++) {
		if (ju[i] <= ju[i + 1]) {
			ju[i + 1] = ju[i];
			sum += roads[roadCnt];
		}
		else {
			sum += roads[roadCnt];
			ans += ju[i] * sum;
			sum = 0;
		}
		roadCnt++;
	}
	sum += roads[roadCnt];
	ans += ju[ju.size() - 1] * sum;
	cout << ans;
}