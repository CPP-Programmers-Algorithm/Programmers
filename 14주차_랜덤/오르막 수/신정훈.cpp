#include <iostream>
#include <vector>

using namespace std;
// 점화식 dp[i][j] = dp[i][j-1] + dp[i-1][j]

int dp[1001][11], N;

int answer = 0;
int MOD = 10007;
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == 1 || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j])% MOD;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        answer += dp[N][i];
    }

    cout << answer % MOD;
}
