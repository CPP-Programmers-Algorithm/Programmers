#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[200000];
int dp[200000][2];

int go(int idx, int cnt) {
    if (idx == n or cnt == 2) {
        if (cnt == 1) return -1e9;
        return 0;
    }
    if (dp[idx][cnt] != -1) return dp[idx][cnt];
    int ret;
    if (cnt == 0) { // 아직 사지도 않았다면
        ret = max(go(idx + 1, cnt), go(idx+1, cnt + 1) - arr[idx]);
    } else if (cnt == 1) { // 사기만 했다면
        ret = max(go(idx + 1, cnt), go(idx+1, cnt+1) + arr[idx]);
    }
    return dp[idx][cnt] = ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    memset(dp, -1, sizeof(dp));
    printf("%d", go(0, 0));
}