#include <iostream>
using namespace std;

int dp[31][11];


int main() {
	int n, m;
	cin >> n >> m;
	int ans;
	if (n == m|| n == 1) ans = 1;
	else
	{
		for (int i = 0; i <= 30; i++)
			dp[i][2] = i + 1;
		for (int i = 0; i <= 10; i++)
			dp[0][i] = 1;
		
		for (int j = 3; j <= 10; j++){
			for (int i = 1; i <= 30; i++){
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		ans = dp[m-n][n];
	}
	cout << ans;

	return 0;
}