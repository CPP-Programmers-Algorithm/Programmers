#include <iostream>
#include <algorithm>
using namespace std;

int times[1002];
int score[1002];
int dp[101][10002];
int n, t;

int go(int num, int totalTime) {
	int& ret = dp[num][totalTime];
	if (totalTime < 0) return -1e8;	// �ִ�ð��� �Ѿ�� ��ȿ
	if (num >= n) return 0;			// ���� ���� �Ѿ�� 0
	if (ret != -1) return ret;		// ��ϵ� ���� �ִٸ� �װ��� ��ȯ
	return ret = max(go(num + 1, totalTime), go(num + 1, totalTime - times[num]) + score[num]);

	//dp[i][j] = ����max(���� é�͸� ���� �ʾ��� ��, ���� é�͸� ����� ��)
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(&dp[0][0], &dp[100][10002], -1);
	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> times[i] >> score[i];
	cout << go(0, t);
}



// ���⼭ num�� �Ѿ�� �� 0�� ��ȯ�ұ�
//https://m.blog.naver.com/fbfbf1/222356288580
//https://codecollector.tistory.com/1079