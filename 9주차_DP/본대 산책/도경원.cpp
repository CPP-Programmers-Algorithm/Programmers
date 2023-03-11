#include <iostream>
using namespace std;

long long dp[8], nxt[8];		// 건물의 수만큼 배열 선언

int main(void)
{
	int d;
	cin >> d;
								
	dp[0] = 1;					// dp[0] -> 정보관에 도착하는 경우의 수
	while (d--)					// nxt : 업데이트 될때마다 1걸음 갔을 때 도달할 수 있는 경우의 술
	{
		nxt[0] = dp[1] + dp[2];
		nxt[1] = dp[0] + dp[2] + dp[3];
		nxt[2] = dp[0] + dp[1] + dp[3] + dp[4];
		nxt[3] = dp[1] + dp[2] + dp[4] + dp[5];
		nxt[4] = dp[2] + dp[3] + dp[5] + dp[6];
		nxt[5] = dp[3] + dp[4] + dp[7];
		nxt[6] = dp[4] + dp[7];
		nxt[7] = dp[5] + dp[6];

		for (int i = 0; i < 8; i++)
			dp[i] = nxt[i] % 1000000007; //nxt를 모두 업데이트 후 dp를 업데이트한다
	}

	cout << dp[0];							//정보관에 도달할 수 있는 경우의 수를 출력한다
	return 0;
}









// https://velog.io/@beclever/C-%EB%B0%B1%EC%A4%80-12849%EB%B2%88-%EB%B3%B8%EB%8C%80-%EC%82%B0%EC%B1%85