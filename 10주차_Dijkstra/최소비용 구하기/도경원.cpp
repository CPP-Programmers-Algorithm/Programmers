#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define X first;
#define Y second;

int v, e, st, en;

// [비용, 정점번호]
vector<pair<int, int>> adj[20005];
const int INF = 1e9 + 10;
int d[20005]; //최단거리테이블
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v >> e;	//v: 정점갯수 e: 간선갯수 st: 시작정점
	fill(d, d + v + 1, INF); //최소값을 비교해야하기 때문에 가장큰수로 초기값세팅
	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v }); // 점 u에 출발하는 모든 도착점과 간선의 가중치 저장
	}
	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> pq;

	cin >> st >> en;
	d[st] = 0;
	//우선순위 큐에 (0, 시작점) 추가
	pq.push({ d[st],st });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue; // 이걸 안하면 시간초과 남
		for (auto nxt : adj[cur.second]) {	//nxt : 현재 정점에서 도착하는 점들
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue; //다음 노드에 이미 저장된 최단거리가 현재 노드의 최단거리 + 다음노드까지 거리보다 작다면
			d[nxt.second] = d[cur.second] + nxt.first;		//위가 성립하지 않으면 최단거리 갱신
			pq.push({ d[nxt.second],nxt.second });			//최단거리가 갱신되면 다음을 검사할 가치가 있다
		}
	}
	
	cout << d[en];
}
