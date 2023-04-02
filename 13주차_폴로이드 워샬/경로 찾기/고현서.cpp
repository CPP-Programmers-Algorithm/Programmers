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
int n;
void Floyd_Warshall(int wayPoint) {
	//출발지 
	for (int i = 0; i < n; i++) {
		//도착지
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == 1)
				continue;
			if (dist[i][wayPoint] + dist[wayPoint][j] > 1)
				dist[i][j] = 1;
		}
	}
}
int main(void) {
	init();
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}
	for (int w = 0; w < n; w++) {
		Floyd_Warshall(w);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}