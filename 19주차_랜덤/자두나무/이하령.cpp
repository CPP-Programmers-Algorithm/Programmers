#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t, w;
int arr[1000];
int dp[1000][31][2];

int go(int ix, int n, int cur) {
    if (ix == t) return 0;

    if (dp[ix][n][cur] != -1) return dp[ix][n][cur];
    int ret;

    if (n < w) {
        ret = max(go(ix + 1, n, cur) + (arr[ix] == cur), go(ix + 1, n + 1, !cur) + (arr[ix] == !cur));
    } else ret = go(ix + 1, n, cur) + (arr[ix] == cur);

    return dp[ix][n][cur] = ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &t, &w);
    for(int i = 0; i < t; i++) {
        scanf("%d", &arr[i]);
        arr[i]--;
    }
    printf("%d", go(0, 0, 0));
}