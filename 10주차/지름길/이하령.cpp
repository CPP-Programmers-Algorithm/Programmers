#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, d;
vector<pii> v[10001];
int dis[10001];

int main() {
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
    }
    for(int i = 0; i <= d; i++) dis[i] = 1e9;
    dis[0] = 0;

    for(int i = 0; i <= d; i++) {
        dis[i] = min(dis[i-1]+1, dis[i]);

        for(pii t : v[i]) {
            if (dis[t.first] < dis[i] + t.second) continue;
            dis[t.first] = dis[i] + t.second;
        }
    }
    printf("%d", dis[d]);
}