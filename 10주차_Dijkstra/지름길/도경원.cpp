#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int v, e, st, totaldst;

vector<pair<int, int>> adj[10001];
vector<int>st_pnt;
vector<int>en_pnt;

//1446지름길
int d[10001];
int INF = 1e9;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> e >> totaldst;
	fill(d, d + v + 1, INF);
	st = INF;

	// 지름길 저장
	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
		st = (u < st) ? u : st; // 가장 작은 출발점을 st로 저장
		st_pnt.push_back(u);
		en_pnt.push_back(v);
	}
	//기본 길에 대한 서로의 간선 연결해주기 / 출발점->다음출발점 / 도착점->다음출발점
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

	d[st] = st;				//st를 잘 지정해줘야 한다
	d[totaldst] = totaldst; // 처음의 도착지까지 최소값은 길의 길이

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
	

	// 운전할 최소값구하기
	cout << d[totaldst];



}