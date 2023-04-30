#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e, k, st;

vector<int> adj[300001];
const int INF = 1e9 + 10;
int d[300001]; //최단거리테이블
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v >> e >> k >> st;
	fill(d, d + v + 1, INF);
	while (e--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v); // u에서 출발해서 도착하는 모든 
	}

	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> pq;
	d[st] = 0;
	//우선순위 큐에 (0,시작점) 추가
	pq.push({ d[st],st });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue; // 이부분을 잘 모르겠네
		for (auto nxt : adj[cur.second]) {
			if (d[nxt] <= d[cur.second] + 1) continue;
			d[nxt] = d[cur.second] + 1;
			pq.push({ d[nxt],nxt });
		}
	}
	int cnt = 0;
	for (int i = 1; i <= v; i++) {
		if (d[i] == k) {
			cout << i << '\n';
			cnt++;
		} 
	}
	if (cnt == 0) cout << -1;
}