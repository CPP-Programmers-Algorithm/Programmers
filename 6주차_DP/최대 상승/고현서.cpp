#include<iostream>
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
	int minNum = 0; int maxNum = -1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (i == 0) {
			minNum = a;
			continue;
		}
		if (minNum > a) {
			minNum = a;
		}
		else if (minNum < a) {
			maxNum = a;
			ans = max(ans, maxNum - minNum);
		}
	}
	cout << ans;
}