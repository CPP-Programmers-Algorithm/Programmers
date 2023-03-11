#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<deque>
#include<map>
#include<vector>
#include<cmath>
#include<climits>
#include<set>
#include<queue>
#include<list>
#include<stack>
#include<math.h>
#include<memory>
#include<sstream>
#include<unordered_map>
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
}
vector<pair<int, int>> city[1001];
int visited[1001];
int cost[1001];
void dijkstra(int s, int end) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();
		if (cur == end)
			continue;
		if (visited[cur]) continue;
		visited[cur] = true;
		for (int i = 0; i < city[cur].size(); i++) {
			int next = city[cur][i].first;
			int nextCost = city[cur][i].second;
			if (cost[next] > curCost + nextCost) {
				cost[next] = curCost + nextCost;
			}
			pq.push({ cost[next], next });
		}
	}
}
int main() {
	init();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		city[a].push_back({ b,c });
	}
	int start, end;
	cin >> start >> end;
	memset(cost, INF, sizeof(cost));
	cost[start] = 0;
	dijkstra(start, end);
	cout << cost[end] << endl;
}