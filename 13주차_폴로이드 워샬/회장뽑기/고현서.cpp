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
int dist[51][51];
int n;
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
	cin >> n;

	memset(dist, n, sizeof(dist));

	int a, b;
	while (cin >> a >> b && !(a == -1 && b == -1)) {
		dist[a - 1][b - 1] = 1;
		dist[b - 1][a - 1] = 1;
	}
	for (int w = 0; w < n; w++) {
		Floyd_Warshall(w);
	}
	int minCnt = n + 1;
	vector<int> num;
	for (int i = 0; i < n; i++) {
		int calc = 0;
		for (int j = 0; j < n; j++) {
			calc = max(dist[i][j], calc);
		}
		if (calc < minCnt) {
			minCnt = calc;
			num.clear();
			num.push_back(i + 1);
		}
		else if (calc == minCnt) {
			num.push_back(i + 1);
		}
	}
	if (minCnt > n)
		minCnt = n;
	cout << minCnt << " " << num.size() << endl;
	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << " ";
	}
}