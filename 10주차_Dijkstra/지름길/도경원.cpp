#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int v, e, st, totaldst;

vector<pair<int, int>> adj[10001];
vector<int>st_pnt;
vector<int>en_pnt;

//1446������
int d[10001];
int INF = 1e9;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> e >> totaldst;
	fill(d, d + v + 1, INF);
	st = INF;

	// ������ ����
	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
		st = (u < st) ? u : st; // ���� ���� ������� st�� ����
		st_pnt.push_back(u);
		en_pnt.push_back(v);
	}
	//�⺻ �濡 ���� ������ ���� �������ֱ� / �����->��������� / ������->���������
	for (int i = 0; i < st_pnt.size() - 1; i++) 
	{
		adj[st_pnt[i]].push_back({ st_pnt[i + 1] - st_pnt[i],st_pnt[i + 1] });
	}
	for (int i = 0; i < en_pnt.size(); i++)
	{
		for (int j = 0; j < st_pnt.size(); j++)
		{
			if (st_pnt[j] > en_pnt[i]) {
				adj[en_pnt[i]].push_back({ st_pnt[j] - en_pnt[i], st_pnt[j] });
				break;
			}
		}
	}
	



	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	d[st] = st;				//st�� �� ��������� �Ѵ�
	d[totaldst] = totaldst; // ó���� ���������� �ּҰ��� ���� ����

	pq.push({ d[st],st });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (auto nxt : adj[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second],nxt.second });
		}
	}
	

	// ������ �ּҰ����ϱ�
	cout << d[totaldst];



}