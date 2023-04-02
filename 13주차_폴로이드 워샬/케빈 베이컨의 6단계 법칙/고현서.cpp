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
int dist[101][101];
int n, m;
void Floyd_Warshall(int wayPoint) {
	//출발지 
	for (int i = 0; i < n; i++) {
		//도착지
		for (int j = 0; j < n; j++) {
			if (i == j)
				dist[i][j] = 0;
			if (dist[i][wayPoint] + dist[wayPoint][j] < dist[i][j])
				dist[i][j] = dist[i][wayPoint] + dist[wayPoint][j];
		}
	}
}
int main(void) {
	init();
	cin >> n >> m;
	memset(dist, INF, sizeof(dist));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dist[a - 1][b - 1] = 1;
		dist[b - 1][a - 1] = 1;
	}
	for (int w = 0; w < n; w++) {
		Floyd_Warshall(w);
	}
	int ans = INF;
	int ansPerson = INF;
	for (int i = 0; i < n; i++) {
		int minCnt = 0;
		for (int j = 0; j < n; j++) {
			minCnt += dist[i][j];
		}
		if (ans == minCnt) {
			ansPerson = min(ansPerson, i + 1);
		}
		else if (ans > minCnt) {
			ansPerson = i + 1;
			ans = minCnt;
		}

	}
	cout << ansPerson;
}