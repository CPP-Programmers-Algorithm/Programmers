#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n;
int dp[1000][10];
int MOD = 10007;

int go(int ix, int nm) {
    if (ix == n) return 1;

    if (dp[ix][nm] != -1) return dp[ix][nm];

    int ret = 0;
    for(int i = nm; i < 10; i++) {
        ret += go(ix + 1, i) % MOD;
    }
    return dp[ix][nm] = ret % MOD;
}

int main() {
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    printf("%d", go(0, 0));
}