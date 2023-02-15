#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int dp[30][10];

int go(int cnt, int ix) {
    if (cnt == m) return 1;

    if (dp[cnt][ix] != -1) return dp[cnt][ix];
    int ret = 0;
    for(int i = ix; i < n; i++) {
        ret += go(cnt + 1, i);
    }

    return dp[cnt][ix] = ret;
}

int main() {
    scanf("%d %d", &n, &m); m -= n;
    memset(dp, -1, sizeof(dp));
    printf("%d", go(0, 0));
}