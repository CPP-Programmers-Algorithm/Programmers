#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001][1001][2];

int go(int ix, int pre, int type) { // 0 증가, 1 감소
    if (ix == n+1) return 0;

    if (dp[ix][pre][type] != -1) return dp[ix][pre][type];
    int ret = 0;

    if (arr[pre] < arr[ix]) {
        if (!type) ret = max(go(ix + 1, pre, type), go(ix + 1, ix, type) + 1); // 안먹던가 먹던가
        else ret = go(ix + 1, pre, type); // 감소해야 하므로 못먹음
    } else if (arr[pre] > arr[ix]) {
        if (type) ret = max(go(ix + 1, pre, type), go(ix + 1, ix, type) +1); // 안먹던가 먹던가
        else ret = max(go(ix + 1, pre, type), go(ix + 1, ix, 1) + 1);
    } else {
        ret = go(ix + 1, pre, type);
    }

    return dp[ix][pre][type] = ret;
}

int main() {
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d", go(1, 0, 0));
}