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
#define INF 0x3f3f3f3f / 3
#define endl "\n"
using namespace std;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
vector<vector<pair<int, int>>> roads;
struct cmp {
	bool operator() (pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};
void Dijkstra(int start, vector<int>& cost) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ start, 0 });
	cost[start] = 0;
	while (!pq.empty()) {
		int curCost = pq.top().second;
		int curPos = pq.top().first;
		pq.pop();
		for (int i = 0; i < roads[curPos].size(); i++) {
			int nextCost = curCost + roads[curPos][i].second;
			int nextPos = roads[curPos][i].first;
			if (nextCost < cost[nextPos]) {
				cost[nextPos] = nextCost;
				pq.push({ nextPos, nextCost });
			}
		}
	}
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = INF;
	for (int i = 0; i <= n; i++) {
		roads.push_back(vector<pair<int, int>>());
	}
	for (int i = 0; i < fares.size(); i++) {
		roads[fares[i][0]].push_back({ fares[i][1], fares[i][2] });
		roads[fares[i][1]].push_back({ fares[i][0], fares[i][2] });
	}
	vector<int> cost1(n + 1, INF);
	vector<int> cost2(n + 1, INF);
	vector<int> cost3(n + 1, INF);

	Dijkstra(s, cost1);

	Dijkstra(a, cost2);

	Dijkstra(b, cost3);

	for (int i = 1; i <= n; ++i) {
		if (answer > cost1[i] + cost2[i] + cost3[i])
			answer = cost1[i] + cost2[i] + cost3[i];
	}

	return answer;
}
