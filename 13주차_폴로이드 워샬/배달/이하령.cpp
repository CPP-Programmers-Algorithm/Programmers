#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

vector<pii> v[50];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dis[50];

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 0; i < road.size(); i++) {
        int a = road[i][0], b = road[i][1], c = road[i][2];
        a--; b--;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    pq.push({0, 0});
    dis[0] = 0;

    while(!pq.empty()) {
        int t = pq.top().second, cost = pq.top().first; pq.pop();
        if (dis[t] < cost) continue;
        for(pii i : v[t]) {
            if (dis[i.first] <= i.second + dis[t]) continue;
            dis[i.first] = i.second + dis[t];
            pq.push({i.second, i.first});
        }
    }

    for(int i = 0; i < N; i++) {
        if (dis[i] <= K) answer++;
    }
    return answer;
}

int main() {
    int n = 5;
    vector<vector<int>> road = {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};
    int k = 3;

    printf("%d", solution(n, road, k));

}