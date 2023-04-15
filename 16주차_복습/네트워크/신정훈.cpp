#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<int>> computers;
vector<bool> visited;
int cnt=0;
void DFS(int v)
{
	if (visited[v])
	{
		return;
	}
	visited[v] = true;

	for (int i = 0; i < N; i++)
	{
		if (v != i)
		{
			if (computers[v][i] == 1 && !visited[i])
			{
				DFS(i);
			}
		}
	}
}
int main()
{
	cin >> N;
	visited.resize(N + 1, false);
	computers.resize(N + 1, vector<int>(N + 1));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> computers[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			DFS(i);
			cnt++;
		}
	}
	cout << cnt;
}
