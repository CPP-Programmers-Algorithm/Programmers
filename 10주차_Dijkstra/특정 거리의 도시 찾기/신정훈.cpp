#include <vector>
#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;
int N, M, K, X;
vector<int> mdistance;
vector<edge> mlist[1000001];
vector<bool> visited;
static priority_queue<edge, vector<edge>, greater<edge>> q;
bool condition = false;

int main()
{
	cin >> N >> M >> K >> X;
	mdistance.resize(N + 1);
	fill(mdistance.begin(), mdistance.end(), INT_MAX);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++) 
	{
		int u, v;
		cin >> u >> v;
		
		mlist[u].push_back(make_pair(v,1));
	}

	q.push(make_pair(0, X));
	mdistance[X] = 0;

	while (!q.empty()) {
		edge current = q.top();
		q.pop();
		int c_v = current.second;
		if (visited[c_v]) {
			continue;
		}
		visited[c_v] = true;
		for (int i = 0; i < mlist[c_v].size(); i++) {
			edge tmp = mlist[c_v][i];
			int next = tmp.first;
			int value = tmp.second;

			if (mdistance[next] > mdistance[c_v] + value) {
				mdistance[next] = value + mdistance[c_v];
				q.push(make_pair(mdistance[next], next));
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] && mdistance[i] ==  K) {
			cout << i << "\n";
			condition = true;
		}
		
	
	}
	if (condition == false)
	{
		cout << -1 << "\n";
	}

}
