#include <iostream>
using namespace std;

int dp[31][31];


int main() {
	int t;
	cin >> t;

	for (int i = 1; i <= 30; i++)
	{
		dp[1][i] = i;				// 1 �� i�� ����� ���� i�� ���� 
	}

	for (int i = 2; i <= 30; i++){	// 2�� �� �� ������ ��� ����� �� �̸� ���
		for (int j = i; j <= 30; j++){
			for (int k = j-1; k >= 1; k--) // k = j-1�� ���� ����� �� �ִ� �ٸ��� 1���� ����
			{
				dp[i][j] += dp[i - 1][k];
			}
		}
	}

	while (t--) {
		int n, m; cin >> n >> m;
		cout << dp[n][m] << '\n';
	}

	return 0;
}



// https://ip99202.github.io/posts/%EB%B0%B1%EC%A4%80-1010-%EB%8B%A4%EB%A6%AC-%EB%86%93%EA%B8%B0/