#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int n, k;
set<int> st;
vector<int> v;
int dp[100][10001];

int go(int ix, int sm) {
    if (ix == v.size()) {
        if (sm == k) return 0;
        return 1e9;
    }
    if (dp[ix][sm] != -1) return dp[ix][sm];

    int ret = 1e9;
    for(int i = 0; sm + i * v[ix] <= k; i++) {
        ret = min(ret, go(ix+1, sm + i*v[ix]) + i);
    }

    return dp[ix][sm] = ret;
}

int main() {
    scanf("%d %d", &n, &k);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (st.find(a) == st.end()) {
            v.push_back(a);
            st.insert(a);
        }
    }
    int ans = go(0, 0);
    if (ans == 1000000000) printf("-1");
    else printf("%d", ans);
}