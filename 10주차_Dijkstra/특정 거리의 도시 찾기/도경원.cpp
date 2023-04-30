#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e, k, st;

vector<int> adj[300001];
const int INF = 1e9 + 10;
int d[300001]; //�ִܰŸ����̺�
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v >> e >> k >> st;
	fill(d, d + v + 1, INF);
	while (e--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v); // u���� ����ؼ� �����ϴ� ��� 
	}

	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> pq;
	d[st] = 0;
	//�켱���� ť�� (0,������) �߰�
	pq.push({ d[st],st });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue; // �̺κ��� �� �𸣰ڳ�
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