#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;

int MOD = 1000000007;
int n;
ll dp[1515][13636];

ll go(int ix, ll total) {
    if (ix == n) {
        if (total % 3 == 0) return 1;
        return 0;
    }
    if (dp[ix][total] != -1) return dp[ix][total];
    ll ret = go(ix + 1, total + 1) % MOD + go(ix + 1, total + 5) % MOD;

    return dp[ix][total] = ret % MOD;
}

int main() {
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    printf("%lld", go(1, 5));
}