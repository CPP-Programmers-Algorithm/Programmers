#include <iostream>
using namespace std;

long long dp[8], nxt[8];		// �ǹ��� ����ŭ �迭 ����

int main(void)
{
	int d;
	cin >> d;
								
	dp[0] = 1;					// dp[0] -> �������� �����ϴ� ����� ��
	while (d--)					// nxt : ������Ʈ �ɶ����� 1���� ���� �� ������ �� �ִ� ����� ��
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
			dp[i] = nxt[i] % 1000000007; //nxt�� ��� ������Ʈ �� dp�� ������Ʈ�Ѵ�
	}

	cout << dp[0];							//�������� ������ �� �ִ� ����� ���� ����Ѵ�
	return 0;
}









// https://velog.io/@beclever/C-%EB%B0%B1%EC%A4%80-12849%EB%B2%88-%EB%B3%B8%EB%8C%80-%EC%82%B0%EC%B1%85