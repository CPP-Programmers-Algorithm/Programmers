#include<iostream>
#include <queue>
using namespace std;

priority_queue<int> pri_que;

int WinDasom(int myCnt) {
	int answer = 0;
	int topNum = pri_que.top();
	pri_que.pop();
	while (myCnt <= topNum) {
		myCnt++;
		topNum--;
		answer++;
		pri_que.push(topNum);
		topNum = pri_que.top();
		pri_que.pop();
	}
	return answer;
}

int main() {
	int n;
	cin >> n;
	int myCnt;
	cin >> myCnt;
	if (n == 1) {
		cout << "0";
		return 0;
	}
	for (int i = 1; i < n; i++) {
		int cnt;
		cin >> cnt;
		pri_que.push(cnt);
	}
	cout << WinDasom(myCnt);
}
