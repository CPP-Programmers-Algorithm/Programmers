#include <cstdio>
using namespace std;
typedef long long ll;

int n;
int arr[1000][1000];
ll le = 0, ri = 10000000, mid, total = 0, ans;

ll getN() {
    ll ret = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (arr[i][j] < mid) ret += arr[i][j];
            else ret += mid;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            total += arr[i][j];
        }
    }

    while(le <= ri) {
        mid = (le + ri) / 2;
        ll tmp = getN();
        if (tmp * 2 >= total) {
            ans = mid;
            ri = mid - 1;
        }
        else le = mid + 1;
    }
    printf("%lld", ans);
}
