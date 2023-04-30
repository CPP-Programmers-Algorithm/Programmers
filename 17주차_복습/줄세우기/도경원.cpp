// BOJ2252 줄세우기

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> adj[32001];
int deg[32001];
int n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b); // a에 연결된 정점정보를 저장
		deg[b]++; //indegree의 수를 높여준다->부모의수
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {	//초기상태설정
		if (deg[i] == 0) q.push(i); //indegree가 없는 정점을 q에 넣는다
	}								//아래서 이 과정이 반복된다 -> do while로도 해결가능
	while (!q.empty()) {
		int cur = q.front(); q.pop(); // indegree가 0인 정점을 가져온다
		cout << cur << ' ';
		for (int nxt : adj[cur]) { //해당정점에 연결된 정점정보를 가져운다
			deg[nxt]--; //연결된 정점의 indegree를 하나 줄이고
			if (deg[nxt] == 0) q.push(nxt); //그랬을 때 부모노드가 하나도 없어지면 q에 넣는다
		}
	}
}