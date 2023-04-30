#include <string>
#include <vector>
#include <queue>

using namespace std;

int board[101][101] = { 0, };
int result[101][101] = { 0, };
bool visited[101][101] = { false, };
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int solution(vector<vector<int>> rect, int cX, int cY, int iX, int iY)
{
    int answer = 0;

    // 2배 늘리기
    cX *= 2, cY *= 2, iX *= 2, iY *= 2;

    int x1, x2, y1, y2;
    for (int i = 0; i < rect.size(); i++)
    {
        for (int j = 0; j < rect[i].size(); j++)
        {
            rect[i][j] *= 2;
        }

        x1 = rect[i][0], y1 = rect[i][1];
        x2 = rect[i][2], y2 = rect[i][3];

        // 사각형 채우기
        for (int y = y1; y <= y2; y++)
        {
            for (int x = x1; x <= x2; x++)
            {
                board[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < rect.size(); i++)
    {

        x1 = rect[i][0], y1 = rect[i][1];
        x2 = rect[i][2], y2 = rect[i][3];

        // 안쪽 비우기
        for (int y = y1 + 1; y < y2; y++)
        {
            for (int x = x1 + 1; x < x2; x++)
            {
                board[y][x] = 0;
            }
        }
    }

    // bfs
    queue<pair<int, int>> q;
    q.push({ cY, cX });
    visited[cY][cX] = true;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        // 목적지인가?
        if (x == iX && y == iY)
        {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nY = y + dy[i];
            int nX = x + dx[i];

            if (nX < 0 || nY < 0 || nX >= 101 || nY >= 101)
                continue;

            if (board[nY][nX] == 1 && !visited[nY][nX])
            {
                q.push({ nY, nX });
                visited[nY][nX] = true;
                result[nY][nX] = result[y][x] + 1;
            }
        }
    }

    answer = result[iY][iX] / 2;

    return answer;
}








//http://hadaming.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-Level-3-%EC%95%84%EC%9D%B4%ED%85%9C-%EC%A4%8D%EA%B8%B0-C