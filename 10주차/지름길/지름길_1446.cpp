#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, m;
vector<vector<pii>> graph;	// 0 ~ n까지 각 위치와 연결된 다른 위치들의 pii(인덱스, 거리)를 저장 
int dp[10001];				// 노드 개수만큼의 dp 배열 
const long long INF = 1e9;

// 다익스트라 알고리즘으로 start 위치에서 다른 모든 위치까지의 최소 거리 저장
void dijkstra(int start)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, start));
	dp[start] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dp[cur] < dist) continue;
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int cost = dist + graph[cur][i].second;
			if (cost < dp[graph[cur][i].first])
			{
				dp[graph[cur][i].first] = cost;
				pq.push(pii(cost, graph[cur][i].first));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> m >> n;
	graph.resize(n + 1);

	// 지름길 간선 연결
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(pii(b, c));
	}

	// 0 ~ n까지 각 위치에서 +1 위치로 간선 연결 (길이는 1)
	for (int i = 0; i <= n; i++)
		graph[i].push_back(pii(i + 1, 1));

	fill(dp, dp + n + 1, INF);
	dijkstra(0);

	// 0 ~ n이 현재 위치일 때 -> 현재 위치까지의 최소 거리 + (목적지 - 현재 위치)를 전부 비교하여 가장 작은 값 찾기
	int minDist = INF;
	for (int i = 0; i <= n; i++)
	{
		int curDist = dp[i] + (n - i);	
		if (curDist < minDist)
			minDist = curDist;
	}
	cout << minDist;
}