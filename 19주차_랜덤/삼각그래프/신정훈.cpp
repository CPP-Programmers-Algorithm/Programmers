#include <iostream>
#include <climits>
#include<algorithm>

using namespace std;

int dp[100001][4];
int map[100001][4];
int N;
int t = 1;
int main()
{
	int max = INT_MAX;
	while (cin >> N && N != 0)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> map[i][j];
			}
		}

		dp[0][0] = map[0][0];
		dp[0][1] = map[0][1];
		dp[0][2] = map[0][1] + map[0][2];

		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 1)
				{
					if (j == 0)
					{
						dp[i][j] = dp[i - 1][j + 1] + map[i][j];
					}
					else if (j == 1)
					{
						dp[i][j] = min({ dp[i - 1][j] + map[i][j], dp[i][j - 1] + map[i][j], dp[i - 1][j + 1] + map[i][j] });
					}
					else if (j == 2)
					{
						dp[i][j] = min({ dp[i - 1][j] + map[i][j], dp[i][j - 1] + map[i][j], dp[i - 1][j - 1] + map[i][j] });
					}
				}
				else
				{
					if (j == 0)
					{
						dp[i][j] = min(dp[i - 1][j + 1] + map[i][j], dp[i - 1][j] + map[i][j]);
					}
					else if (j == 1)
					{
						dp[i][j] = min({ dp[i - 1][j] + map[i][j], dp[i - 1][j - 1] + map[i][j], dp[i - 1][j + 1] + map[i][j], dp[i][j - 1] + map[i][j] });
					}
					else if (j == 2)
					{
						dp[i][j] = min({ dp[i - 1][j] + map[i][j], dp[i][j - 1] + map[i][j], dp[i - 1][j - 1] + map[i][j] });
					}

				}
			}
		}

		cout << t++ << ". " << dp[N - 1][1] << "\n";
	}
}
