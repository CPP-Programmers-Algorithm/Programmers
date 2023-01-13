#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int n, a;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a);
            pq.push(a);
        }
        while(pq.size() > n) pq.pop();
    }
    printf("%d", pq.top());
}