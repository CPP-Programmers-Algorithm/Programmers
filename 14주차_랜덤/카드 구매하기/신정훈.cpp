#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int dp[1004], N, M;

vector<int> cards;

int main()
{
    cin >> N;
    cards.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> M;
        cards[i] = M;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], dp[i - j] + cards[j]);
        }
    }
    cout << dp[N];
}



