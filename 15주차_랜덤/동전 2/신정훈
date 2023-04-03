#include <iostream>
using namespace std;

int dp[100001];
int coin[100001];
int N, K;

int main()
{
    cin >> N >> K;

    for (int i = 1; i <= K; i++)
    {
        dp[i] = 100001;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> coin[i];
    }
    for (int i = 0; i <= N; i++)
    {
        for (int j = coin[i]; j <= K; j++)
        {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }
    if (dp[K] == 100001)
    {
        cout << -1;
    }
    else
    {
    cout << dp[K];
    }
}
