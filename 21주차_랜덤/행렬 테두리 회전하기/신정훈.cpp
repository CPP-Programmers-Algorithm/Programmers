#include <string>
#include <vector>

using namespace std;
int map[101][101];
int num = 1;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
vector<int> originKeep;
int mn = 1e9;
void DFS(int dir, int x, int y, int limitX, int limitY, int keep, int min)
{
	int nx = dx[dir] + x;
	int ny = dy[dir] + y;
	if (dir == 0 || dir == 1)
	{
		if (nx <= limitX && ny <= limitY)
		{

			if (keep < min)
			{
				min = keep;
				mn = min;
			}
			int keepTemp = map[nx][ny];
			map[nx][ny] = keep;
			keep = keepTemp;

			DFS(dir, nx, ny, limitX, limitY, keep, min);
		}
	}
	else if (dir == 2 || dir == 3)
	{
		if (nx >= limitX && ny >= limitY)
		{

			if (keep < min)
			{
				min = keep;
				mn = min;
			}
			int keepTemp = map[nx][ny];
			map[nx][ny] = keep;
			keep = keepTemp;

			DFS(dir, nx, ny, limitX, limitY, keep, min);
		}
	}
	else
	{
		return;
	}
    return;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= columns; j++)
		{
			map[i][j] = num;
			num++;
		}
	}
for (int i = 0; i < queries.size(); i++)
	{
		originKeep.push_back(map[queries[i][0]][queries[i][1]]);
		originKeep.push_back(map[queries[i][0]][queries[i][3]]);
		originKeep.push_back(map[queries[i][2]][queries[i][3]]);
		originKeep.push_back(map[queries[i][2]][queries[i][1]]);
		for (int j = 0; j < 4; j++)
		{

			int x = 0;
			int y = 0;
			int limitX = 0;
			int limitY = 0;
			int keep = 0;
			if (j == 0)
			{

				x = queries[i][0];
				y = queries[i][1];
				limitX = queries[i][0];
				limitY = queries[i][3];
				keep = originKeep[0];
			}
			else if (j == 1)
			{
				x = queries[i][0];
				y = queries[i][3];
				limitX = queries[i][2];
				limitY = queries[i][3];
				keep = originKeep[1];
			}
			else if (j == 2)
			{
				x = queries[i][2];
				y = queries[i][3];
				limitX = queries[i][2];
				limitY = queries[i][1];
				keep = originKeep[2];
			}
			else if (j == 3)
			{
				x = queries[i][2];
				y = queries[i][1];
				limitX = queries[i][0];
				limitY = queries[i][1];
				keep = originKeep[3];
			}
			DFS(j, x, y, limitX, limitY, keep, mn);
		}
		answer.push_back(mn);
		mn = 1e9;
		originKeep.clear();
	}
    
    return answer;
}
