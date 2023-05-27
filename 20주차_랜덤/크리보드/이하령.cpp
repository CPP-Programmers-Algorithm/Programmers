#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
ll dp[101];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + 1;
        for(int j = i - 3; j > 0; j--) {
            dp[i] = max(dp[i], dp[j] + dp[j] * (i-j-2));
        }
    }
    printf("%lld", dp[n]);
}