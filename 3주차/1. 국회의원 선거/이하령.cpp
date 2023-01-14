#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n;
priority_queue<int> pq;

int main() {
    int ans = 0, dasom;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        if (i == 0) dasom = a;
        else pq.push(a);
    }
    while(pq.size() and pq.top() >= dasom) {
        int t = pq.top(); pq.pop(); ans++; dasom++;
        pq.push(t-1);
    }
    printf("%d", ans);
}