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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
}
int main() {
	init();
	int n, m;
	cin >> n >> m;
	vector<int> videos;
	long long sum = 0;
	long long start = 0;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		sum += s;
		start = start < s ? s : start;
		videos.push_back(s);
	}
	long long end = sum;
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long newSum = 0;
		long long cnt = 1;
		for (int i = 0; i < n; i++) {
			if (newSum + videos[i] > mid) {
				newSum = 0;
				cnt++;
			}
			newSum += videos[i];
		}
		if (cnt > m) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << start;
}