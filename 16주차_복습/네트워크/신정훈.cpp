#include <string>
#include <vector>

using namespace std;
vector<bool> visited;
int answer = 0;
int N;
void DFS(int v, vector<vector<int>> computers)
{
	
	visited[v] = true;

	for (int i = 0; i < N; i++)
	{
		if (v != i)
		{
			if (computers[v][i] == 1 && !visited[i])
			{
				DFS(i, computers);
			}
		}
	}
}
int solution(int n, vector<vector<int>> computers) {
   
    N = n;
    visited.resize(n + 1, false);
    for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			DFS(i , computers);
            answer++;
		}
	}
    
    return answer;
}
