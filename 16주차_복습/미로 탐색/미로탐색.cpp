


#include <cstdio>
#include <queue>
using namespace std;

int n, m;
int map[100][100];
int cnt[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
    scanf("%d %d", &n, &m);
    //맵정보
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    queue<pair<int, int> > q;

    //첫번째 칸에서 시작
    q.push(make_pair(0, 0));
    cnt[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;//맵벗어나면
            if (map[nx][ny] == 1 && cnt[nx][ny] == 0) {//지나갈수있고 지나가지않은곳
                q.push(make_pair(nx, ny));

                //이전 단계보다 1 증가(이동 횟수 증가)
                cnt[nx][ny] = cnt[x][y] + 1;
            }
        }
    }

    //마지막 칸을 출력
    printf("%d\n", cnt[n - 1][m - 1]);

    return 0;
}
