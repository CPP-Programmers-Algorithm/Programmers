#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

int n;
ll ans = 0;
ll arr[100000];
ll dis[100000];
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) scanf("%lld", &dis[i]);
    for(int i = 0; i < n; i++) scanf("%lld", &arr[i]);

    pq.push(arr[0]);
    for(int i = 1; i < n; i++) {
        ans += pq.top() * dis[i];
        pq.push(arr[i]);
    }
    printf("%lld", ans);
}