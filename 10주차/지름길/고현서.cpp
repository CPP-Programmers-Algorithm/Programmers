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
vector<pair<int, int>> road[100001];
int cost[100001];
int main() {
	init();
	int n, d;
	cin >> n >> d;
	int minStart = INF;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[b].push_back({ a,c });
	}
	memset(cost, INF, sizeof(cost));
	cost[0] = 0;
	for (int i = 1; i <= d; i++) {
		if (road[i].size() == 0) {
			if (i == 0)
				cost[i] = 0;
			else
				cost[i] = min(cost[i], cost[i - 1] + 1);
			continue;
		}
		for (int j = 0; j < road[i].size(); j++) {
			int nextX = road[i][j].first;
			int nextCost = road[i][j].second;
			cost[i] = min(cost[i], min(cost[i - 1] + 1, cost[nextX] + nextCost));
		}
	}
	cout << cost[d];
}