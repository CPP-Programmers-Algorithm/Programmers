#include <iostream>
using namespace std;

int N;
int map[100004][4] = { 0 };
int maxDp[4][4] = { 0 };
int minDp[4][4] = { 0};

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> map[i][j];
		}
	}
	if (N == 1)
	{
		cout << max(max(map[1][1], map[1][2]), map[1][3]) << " " << min(min(map[1][1], map[1][2]), map[1][3]);
	}
	else
	{
		maxDp[1][1] = map[1][1];
		maxDp[1][2] = map[1][2];
		maxDp[1][3] = map[1][3];
		minDp[1][1] = map[1][1];
		minDp[1][2] = map[1][2];
		minDp[1][3] = map[1][3];

		for (int i = 2; i <= N; i++)
		{
			maxDp[2][1] = map[i][1] + max(maxDp[1][1], maxDp[1][2]);
			maxDp[2][2] = map[i][2] + max(max(maxDp[1][1], maxDp[1][2]), maxDp[1][3]);
			maxDp[2][3] = map[i][3] + max(maxDp[1][2], maxDp[1][3]);
			minDp[2][1] = map[i][1] + min(minDp[1][1], minDp[1][2]);
			minDp[2][2] = map[i][2] + min(min(minDp[1][1], minDp[1][2]), minDp[1][3]);
			minDp[2][3] = map[i][3] + min(minDp[1][2], minDp[1][3]);

			for (int j = 1; j <= 3; j++)
			{
				maxDp[1][j] = maxDp[2][j];
				minDp[1][j] = minDp[2][j];
			}
		}

		cout << max(max(maxDp[2][1], maxDp[2][2]), maxDp[2][3]) << " " << min(min(minDp[2][1], minDp[2][2]), minDp[2][3]);
	}
	
}
