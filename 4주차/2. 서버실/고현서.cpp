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
	int n;
	cin >> n;
	vector<int> server;
	long long sum = 0; long long max = 0; long long min = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int com;
			cin >> com;
			sum += com;
			max = max < com ? com : max;
			server.push_back(com);
		}
	}
	long long fPer = (ceil)((double)sum / 2);
	min = 0;
	while (min <= max) {
		long long midValue = (min + max) / 2;
		long long newSum = 0;
		for (int i = 0; i < server.size(); i++) {
			newSum += midValue > server[i] ? server[i] : midValue;
		}

		if (newSum < fPer) {
			min = midValue + 1;
		}
		else {
			max = midValue - 1;
		}
	}
	cout << min;
}