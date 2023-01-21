#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

// sol1 )
int n, m, k, h[20000001];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        h[k + 10000000]++;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &k);
        printf("%d ", h[k + 10000000]);
    }
    return 0;
}

// sol 2)
map<int, int> mp;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (mp.find(a) == mp.end()) mp[a] = 1;
        else mp[a]++;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int a; scanf("%d", &a);
        if (mp.find(a) == mp.end()) printf("0 ");
        else printf("%d ", mp[a]);
    }
}