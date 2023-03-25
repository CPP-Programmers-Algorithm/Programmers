#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n;
int arr[50][50];
pii ans[50];

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == j) arr[i][j] = 0;
            else arr[i][j] = 1e9;
        }
    }

    while(1) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == -1) break;
        a--; b--;
        arr[a][b] = 1; arr[b][a] = 1;
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (arr[i][k] + arr[k][j] < arr[i][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        int mn = 0;
        for(int j = 0; j < n; j++) {
            mn = max(mn, arr[i][j]);
        }
        ans[i] = {mn, i};
    }
    sort(ans, ans + n);
    int total = ans[0].first;
    int cnt = 1;

    for(int i = 1; i < n; i++) {
        if (ans[i].first == total) {
            cnt++;
        } else break;
    }
    printf("%d %d\n", total, cnt);
    for(int i = 0; i < cnt; i++) printf("%d ", ans[i].second + 1);
}