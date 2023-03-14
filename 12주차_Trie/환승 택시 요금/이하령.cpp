#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

// 지점의 개수 n
// 출발지점 s
// A의 도착지점 a
// B의 도착지점 b

vector<pii> v[200];
int dis[200][200]; // dis[i] 어딘가까지 같이 감

void go(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s}); //s
    dis[s][s] = 0;
    while (!pq.empty()) {
        int cur = pq.top().second, cost = pq.top().first; pq.pop();
        if (dis[s][cur] < cost) continue;
        for(pii i : v[cur]) {
            if (dis[s][i.first] <= i.second + dis[s][cur]) continue;
            dis[s][i.first] = i.second + dis[s][cur];
            pq.push({i.second, i.first});
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9; s--; a--; b--;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 0; i < fares.size(); i++) {
        int st = fares[i][0], en = fares[i][1], c = fares[i][2];
        st--;
        en--;
        v[st].push_back({en, c});
        v[en].push_back({st, c});
    }
    for(int i = 0; i < n; i++) {
        go(i);
    }
    for(int i = 0; i < n; i++) {
        if(dis[s][i] == 1061109567 or dis[i][a] == 1061109567 or dis[i][b] == 1061109567) continue;
        answer = min(answer, dis[s][i] + dis[i][a] + dis[i][b]);
    }
    return answer;
}

int main() {
    int n = 7, s = 3, a = 4, b = 1;
    vector<vector<int>> fares = {{5, 7, 9}, {4, 6, 4},
                                 {3, 6, 1}, {3, 2, 3}, {2, 1, 6}};
    printf("%d", solution(n, s, a, b, fares));
}