#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int n;
map<pii, int> mp;

int main() {
    int ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        mp[{a, b}]++;
    }

    while(!mp.empty()) {
        auto it = mp.begin(); ans++;
        piii itValue = *mp.begin();
        if (itValue.second > 1) mp[itValue.first]--;
        else mp.erase(it);
        while(mp.lower_bound({itValue.first.second, -1}) != mp.end()) {
            it = mp.lower_bound({itValue.first.second, -1});
            itValue = *it;

            if (itValue.second > 1) mp[itValue.first]--;
            else mp.erase(it);
        }
    }
    printf("%d", ans);
}