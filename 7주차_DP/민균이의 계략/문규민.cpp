#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>
using namespace std;
int cards[1001];
int dp[1001];

int solution(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)			// 현재 순서 인덱스를 모든 이전 인덱스들과 비교
		{
			if (cards[j] < cards[i])		// 현재 인덱스의 값이 이전 인덱스의 값보다 클 때만 (증가 수열이므로)
			{
				if (dp[i] < dp[j] + 1)		// 현재 인덱스의 dp가 이전 인덱스의 dp + 1보다 작을 때만 갱신
					dp[i] = dp[j] + 1;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < dp[i])
			max = dp[i];
	}
	return max;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> cards[i];
		dp[i] = 1;
	}

	cout << solution(n);
}
