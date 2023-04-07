#include <iostream>
#include <vector>
using namespace std;

int N;
int map[17][17];
vector<vector<bool>> visited;
int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };
int cnt;
void DFS(int x, int y, int v);
int main()
{
    cin >> N;
    visited.resize(N + 1, vector<bool>(N + 1, false));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
        }
    }
    cnt = 0;
    DFS(1,2,0);
    cout << cnt;
}

void DFS(int x, int y, int v)
{
    if (x == N && y == N)
    {
        cnt++;
        return;
    }
   
    visited[x][y] = true;
// 0 가로 , 1 세로 , 2, 대각선
    for (int i = 0; i < 3; i++) {
        if (v == 0 && i == 1) // 가로 + 세로
        {
            continue;
        }
        if (v == 1 && i == 0) // 세로 + 가로
        {
            continue;
        }
        else 
        {
            // 대각선으로 이동은 x+1, y+1
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 범위를 벗어나는 경우
            if (N < nx || N < ny || nx <= 0 || ny <= 0)
            {
                continue;
            }
            // 가로, 세로
            if (i < 2)
            {
                if (map[nx][ny] != 1 && !visited[nx][ny])
                {
                    DFS(nx, ny, i);
                    visited[nx][ny] = false;
                }
            }
            else
            {
                if (map[nx][ny] != 1 && map[nx - 1][ny] != 1 && map[nx][ny - 1] != 1 && !visited[nx][ny])
                {
                    DFS(nx, ny, i);
                    visited[nx][ny] = false;
                }
            } 
        }
    }
}
