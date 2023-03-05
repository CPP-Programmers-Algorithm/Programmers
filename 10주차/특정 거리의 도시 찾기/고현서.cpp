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
int n, m, k, x;
vector<int> road[300001];
int dist[300001];
set<int> ans2;
void dijkstra(int start) {
	dist[start] = 0;
	queue<int> roadQ;
	for (int i = 0; i < road[start].size(); i++) {
		dist[road[start][i]] = dist[start] + 1;
		roadQ.push(road[start][i]);
	}
	while (!roadQ.empty()) {
		int frontQ = roadQ.front();
		roadQ.pop();
		if (dist[frontQ] == k) {
			ans2.insert(frontQ);
			continue;
		}
		for (int i = 0; i < road[frontQ].size(); i++) {
			if (dist[road[frontQ][i]] > dist[frontQ] + 1) {
				dist[road[frontQ][i]] = dist[frontQ] + 1;
				roadQ.push(road[frontQ][i]);
			}
		}
	}
}
int main() {
	init();
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
	}
	memset(dist, INF, sizeof(dist));
	dijkstra(x);
	if (ans2.size() == 0)
		cout << "-1";
	else {
		for (auto i : ans2)
			cout << i << endl;
	}
}