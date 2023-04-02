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
#define endl "\n"
using namespace std;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
int dp[100001];
int solution(vector<int> sticker)
{
	int answer = 0;
	if (sticker.size() == 1) return sticker[0];

	//1. 0�� index�� ��� ���� �ϴ� ���
	// -> 1�� index�� ������ �ε����� �� �� ����.
	dp[0] = sticker[0];
	dp[1] = sticker[0];
	for (int i = 2; i < sticker.size() - 1; i++) {
		dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
	}
	answer = max(answer, dp[sticker.size() - 2]);

	//2. 0�� index�� ��� ���� ���ϰ� ������Ű�� ���
	//  -> 1�� index�� ������ �ε����� �� �� �ִ�.
	dp[0] = 0;
	dp[1] = sticker[1];
	for (int i = 2; i < sticker.size(); i++) {
		dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
	}
	answer = max(answer, dp[sticker.size() - 1]);
	return answer;
}