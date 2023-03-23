#include <iostream>
#include <vector>
using namespace std;

// 행렬
int mdistance[104][104];
int N = 6;
int K = 4;
vector<vector<int> > road = { {1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1} };


int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	// 행렬 만들기~
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
				mdistance[i][j] = 500001;
			}
		}
	}

	// 행렬의 숫자 넣기~
	for (int i = 0; i < road.size(); i++)
	{
		if (mdistance[road[i][0]][road[i][1]] > road[i][2])
		{
		mdistance[road[i][0]][road[i][1]] = road[i][2];
		mdistance[road[i][1]][road[i][0]] = road[i][2];
		}
	}

	// 플로이드 워셜 공식~
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				// 전부 채운다~
				if (mdistance[i][j] > mdistance[i][k] + mdistance[k][j])
				{
					mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
				}
			}
		}
	}

	// 한행에서 k이하를 찾아준다~
		for (int i = 1; i <= N; i++)
		{
			if (mdistance[1][i] <= K)
			{
				answer++;
			}
		}
	
	return answer;
}

int main()
{
	solution(N, road, K);
	return 0;
}
