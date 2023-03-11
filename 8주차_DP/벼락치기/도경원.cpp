#include <iostream>
#include <algorithm>
using namespace std;

int times[1002];
int score[1002];
int dp[101][10002];
int n, t;

int go(int num, int totalTime) {
	int& ret = dp[num][totalTime];
	if (totalTime < 0) return -1e8;	// 최대시간을 넘어가면 무효
	if (num >= n) return 0;			// 과목 수를 넘어가면 0
	if (ret != -1) return ret;		// 기록된 것이 있다면 그것을 반환
	return ret = max(go(num + 1, totalTime), go(num + 1, totalTime - times[num]) + score[num]);

	//dp[i][j] = 점수max(현재 챕터를 고르지 않았을 때, 현재 챕터를 골랐을 때)
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(&dp[0][0], &dp[100][10002], -1);
	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> times[i] >> score[i];
	cout << go(0, t);
}



// 여기서 num을 넘어가면 왜 0을 반환할까
//https://m.blog.naver.com/fbfbf1/222356288580
//https://codecollector.tistory.com/1079