#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, t;
pii arr[100];
int dp[100][10001];

int go(int ix, int sm) {
    if (ix == n) {
        return 0;
    }
    if (dp[ix][sm] != -1) return dp[ix][sm];
    int ret = go(ix + 1, sm);
    if (sm + arr[ix].first <= t) ret = max(ret, go(ix + 1, sm + arr[ix].first) + arr[ix].second);

    return dp[ix][sm] = ret;
}

int main() {
    scanf("%d %d", &n, &t);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d", go(0, 0));
}