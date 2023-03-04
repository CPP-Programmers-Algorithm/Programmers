#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, m, k, x;
vector<int> v[300000];
int dis[300000];
vector<int> ans;

void go() {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, x});
    dis[x] = 0;

    while (!q.empty()) {
        int t = q.top().second, cnt = q.top().first; q.pop();
        if (cnt == k) {
            ans.push_back(t);
        } else {
            for(int i : v[t]) {
                if (dis[i] > 1 + cnt) {
                    dis[i] = 1 + cnt;
                    q.push({dis[i], i});
                }
            }
        }

    }

}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &x);
    x--;
    for(int i = 0; i < n; i++) dis[i] = 1e9;
    for(int a, b, i = 0; i < m; i++) {
        scanf("%d %d", &a, &b); a--; b--;
        v[a].push_back(b);
    }
    go();
    sort(ans.begin(), ans.end());
    if (ans.size() != 0) for(int i : ans) printf("%d\n", i+1);
    else printf("-1");
}