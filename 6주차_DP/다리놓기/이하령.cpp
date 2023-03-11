#include <cstdio>
#include <cstring>
using namespace std;

int t, n, m;
int dp[30][30];

int go(int nn, int mm) {
    if (nn == 0 or mm == 0) {
        if (nn != 0) return 0;
        return 1;
    }
    if (dp[nn][mm] != -1) return dp[nn][mm];
    int ret = 0;

    for(int i = mm-1; i >= 0; i--) {
        ret += go(nn - 1, i);
    }
    return dp[nn][mm] = ret;
}

int main() {
    scanf("%d", &t);
    memset(dp, -1, sizeof(dp));
    while(t--) {
        scanf("%d %d", &n, &m);
        printf("%d\n", go(n, m));
    }
}