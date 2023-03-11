#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct axis { int x, y; };
typedef pair<axis, int> pai;

int n;
int arr[3][3];
int vis[3][3];
bool isEnd = false;
queue<pai> q;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    q.push({{0, 0}, arr[0][0]});
    vis[0][0] = 1;

    while(!q.empty()) {
        axis t = q.front().first;
        int num = q.front().second; q.pop();
        if (t.x == n-1 and t.y == n-1) {
            isEnd = true;
            break;
        }

        for(int i = 0; i < 2; i++) {
            int x = t.x + num * i, y = t.y + num * (1 - i);
            if (x < 0 or y < 0 or x >= n or y >= n) continue;
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            q.push({{x, y}, arr[x][y]});
        }
    }

    if (isEnd) printf("HaruHaru");
    else printf("Hing");
}

// 점프왕 쩰리 (large)는 배열의 크기만 바꾸면 된다.