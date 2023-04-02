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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
vector<vector<pair<int, int>>> roadInfo;
int cost[2001];
int visited[2001];
void dijkstra(int start) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	cost[start] = 0;
	while (!pq.empty()) {
		int curCost = pq.top().first;
		int curPos = pq.top().second;
		pq.pop();
		if (visited[curPos]) continue;
		visited[curPos] = true;
		for (int i = 0; i < roadInfo[curPos].size(); i++) {
			int nextPos = roadInfo[curPos][i].first;
			int nextCost = curCost + roadInfo[curPos][i].second;
			if (nextCost < cost[nextPos]) {
				cost[nextPos] = nextCost;
				pq.push({ nextCost, nextPos });
			}
		}
	}
}
int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	memset(cost, INF, sizeof(cost));
	for (int i = 0; i < N; i++) {
		roadInfo.push_back(vector < pair<int, int>>());
	}
	for (int i = 0; i < road.size(); i++) {
		roadInfo[road[i][0] - 1].push_back({ road[i][1] - 1, road[i][2] });
		roadInfo[road[i][1] - 1].push_back({ road[i][0] - 1, road[i][2] });
	}
	dijkstra(0);
	for (int i = 0; i < N; i++) {
		if (cost[i] <= K)
			answer++;
	}

	return answer;
}