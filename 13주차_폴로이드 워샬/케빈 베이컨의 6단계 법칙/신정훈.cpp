#include <iostream>

using namespace std;
int N, M;
int mdistance[104][104];

int main()
{
	int a, b;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
			{
			mdistance[i][j] = 0;
			}
			else
			{
				mdistance[i][j] = 100000;
			}
		}
		
	}

	for (int i = 1; i <= M; i++)
	{
		// 입력받은 행렬은 이어진다는 의미로 1삽입.
		cin >> a >> b;
		mdistance[a][b] = 1;
		// 쌍방향으로 이어지니깐 바꾼곳도 1으로 삽입.
		mdistance[b][a] = 1;
	}
	// 폴로이드 워셜 공식
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (mdistance[i][j] > mdistance[i][k] + mdistance[k][j])
				{			
					mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
				}
			}
		}
	}
	//출력
	int answer =100001;
	int an = 0;
	for (int i = 1; i <= N; i++)
	{
		    int a = 0;
		for (int j =1; j <= N; j++)
		{
			// 한 행을 전부 더한다.
			a += mdistance[i][j];

		}
		// 가장 작은 값을 구한다.
		if (a < answer)
		{
			answer = a;
			an = i;
		}
			
	}
	cout << an;
}
