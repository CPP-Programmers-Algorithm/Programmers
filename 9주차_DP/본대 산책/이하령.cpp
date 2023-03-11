#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

ll MOD = 1000000007;
int d;
ll dp[8][100000];

// 0: 정보과학관
/*
 * 0: 정보과학관
 * 1: 전산관
 * 2: 신앙관
 * 3: 미래관
 * 4: 진리관
 * 5: 환경직기념관
 * 6: 학생회관
 * 7: 형남공학관
 * */

vector<int> v[8] = {
        {1, 3},
        {0, 2, 3},
        {1, 3, 4, 5},
        {0, 1, 2, 5},
        {2, 5, 6},
        {2, 3, 4, 7},
        {4, 7},
        {5, 6}
};


ll go(int ix, int cnt) {
    if (cnt == d) {
        if (ix == 0) return 1;
        return 0;
    }

    if (dp[ix][cnt] != -1) return dp[ix][cnt];
    ll ret = 0;
    for(int i : v[ix]) {
        ret = (ret + (go(i, cnt + 1) % MOD)) % MOD;
    }

    return dp[ix][cnt] = ret;
}

int main() {
    scanf("%d", &d);
    memset(dp, -1, sizeof(dp));
    printf("%lld", go(0, 0));
}