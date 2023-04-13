#include <iostream>
#include <queue>
#define MAX

using namespace std;

int N, M;
int map[104][104];
//아래, 오른쪽, 위, 왼쪽
int dx[] = { 1, 0 , -1 , 0 };
int dy[] = { 0, 1 , 0 , -1 };
int cnt = 1;
int answer = 100004;
vector<vector<bool>> visited;

void BFS()
{
	queue<pair<pair<int, int>, int>> myqueue;
	myqueue.push({{ 1,1 },1});
	visited[1][1] = true;
	while (!myqueue.empty())
	{
		int x = myqueue.front().first.first;
		int y = myqueue.front().first.second;
		int cnt = myqueue.front().second;
		myqueue.pop();
		if (x == N && y == M)
		{
			cout << cnt;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (1 <= xx && xx <= N && 1 <= yy && yy <= M)
			{
				if (!visited[xx][yy] && map[xx][yy] != 0)
				{
					visited[xx][yy] = true;
					//모든 경로가 다 카운트 된다.
					//cnt++;
					myqueue.push({ { xx,yy }, cnt + 1 });
				}
			}
		}
	}
	return;
}

int main()
{
	cin >> N >> M;
	visited.resize(N + 1, vector<bool>(M + 1, false));
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			map[i][j+1] = s[j] - '0';
		}
	}
	BFS();
}
