


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
    //������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    queue<pair<int, int> > q;

    //ù��° ĭ���� ����
    q.push(make_pair(0, 0));
    cnt[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;//�ʹ����
            if (map[nx][ny] == 1 && cnt[nx][ny] == 0) {//���������ְ� ��������������
                q.push(make_pair(nx, ny));

                //���� �ܰ躸�� 1 ����(�̵� Ƚ�� ����)
                cnt[nx][ny] = cnt[x][y] + 1;
            }
        }
    }

    //������ ĭ�� ���
    printf("%d\n", cnt[n - 1][m - 1]);

    return 0;
}
