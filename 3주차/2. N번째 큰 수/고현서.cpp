#include<iostream>
#include<climits>
#include <queue>
using namespace std;

priority_queue<int> pri_que;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
int main() {
	init();
	int n;
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		int num;
		cin >> num;
		if (pri_que.size() < n)
			pri_que.push(-num);
		else {
			if (-pri_que.top() < num) {
				pri_que.pop();
				pri_que.push(-num);
			}
		}
	}
	cout << -pri_que.top();
}