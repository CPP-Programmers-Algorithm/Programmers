#include <iostream>
#include <algorithm>
#define INF 987654321;
using namespace std;

int dis[101][101];
int cnt[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n, m; cin >> n >> m;

	int kevin, kevinNum;
	kevin = kevinNum = INF;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			dis[i][j] = INF; // 거리중 최소값을 구하기때문에 INF로 초기화
			cnt[i][j] = 1; //모든 관계는 연결되어 있다
		}
			

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		dis[a-1][b-1] = 1; // idx를 맞춰주고 간선을 초기화한다
		dis[b-1][a-1] = 1;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dis[i][j] > dis[i][k] + dis[k][j]) { // 새로운 거리가 원래거리보다 작다면
					dis[i][j] = dis[i][k] + dis[k][j]; // 거리갱신
					cnt[i][j] = cnt[i][k] + cnt[k][j]; // 깊이갱신
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += cnt[i][j];
		}
		if (sum < kevinNum) { kevinNum = sum; kevin = i+1;} // 작은 경우만 갱신되어 같은 값중에 최소갑을 가지게 된다
	}
	cout << kevin;
}

