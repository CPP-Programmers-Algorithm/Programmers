#include <iostream>
#include <vector>
using namespace std;

int N;
// 행렬
int mdistance[104][104];
vector<int> vec;
int main()
{
	cin >> N;
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
				mdistance[i][j] = 100000;
			}
		}
	}
	int a, b;
	// 마지막 입력값이 -1이니까 while 문으로
	while (true)
	{
		cin >> a >> b;
		if (a == -1 && b == -1)
		{
			break;
		}
		mdistance[a][b] = 1;
		mdistance[b][a] = 1;
	}

	//플로이드 워셜 공식
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
	int answer = 100000;
	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		int an = 0;
		for (int j = 1; j <= N; j++)
		{
			// 한 행에서 가장 큰 값 찾는다. 그것이 후보의 점수
			// 친구의 친구의 친구...일수록 점수가 증가
			if (mdistance[i][j] > an)
			{
				an = mdistance[i][j];
			}
		}
		// 가장 작은 점수를 가진 후보를 찾는다.
		if (an < answer)
		{
			answer = an;
		}
	}

	// 가장 작은 점수를 가진 후보들을 찾는다
	for (int i = 1; i <= N; i++) {
		bool t = true;
		// 후보가 가진 행중에 가장 작은점수(anwer)보다 큰 점수가 있으면 안된다.
		for (int j = 1; j <= N; j++)
		{
			if (mdistance[i][j] > answer)
			{
				t = false;
				break;
			}
		}
		for (int j = 1; j <= N; j++)
		{
			if (t== true&&mdistance[i][j] == answer)
			{
				// 후보 벡터에 넣어준다.
				vec.push_back(i);
				count++;
				break;
			}
		}

	}
	// 회장 후보의 점수, 회장 후보의 수 출력
	// 회장 후보 출력
	cout << answer << " " << count << "\n";
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
}

