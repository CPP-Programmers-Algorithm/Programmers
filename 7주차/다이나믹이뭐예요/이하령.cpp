#include <cstdio>
#include <cstring>
using namespace std;
int dy[] = { 1, 0, 1}, dx[] = { 1, 1, 0};

int MOD = 1000000007;
int n, m;
int dp[1001][1001];

int go(int a, int b) {
    if (a == n-1 or b == m-1) {
        return 1;
    }
    if (dp[a][b] != -1) return dp[a][b];
    int ret = 0;
    for(int i = 0; i < 3; i++) {
        int x = a + dx[i], y = b + dy[i];
        if (x >= n or y >= m) continue;
        ret = (ret + (go(x, y) % MOD)) % MOD;
    }
    return dp[a][b] = ret;
}


int main() {
    scanf("%d %d", &n, &m);
    memset(dp, -1, sizeof(dp));
    printf("%d", go(0, 0));
}