


// 내림차순 오름차순 
// https://itguava.tistory.com/67
// https://koosaga.com/9

#include <iostream>
#include <queue>
#define MAX 126
#define INF 2501
using namespace std;

int n;
int arr[MAX][MAX];
int dp[MAX][MAX];

bool inRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n);
}

void dijkstra(int x, int y) {
	// greater는 내림차순
	// a가 자료구조, cmp가 bool이라고 할 때
	// priority_queue<a, vector<a>, cmp> 이런 식으로 쓴다
	// 이 자료구조는 pair<int, pair<int,int>를 내림차순으로 자동정렬
	priority_queue < pair<int, pair<int, int>>, 
					vector<pair<int, pair<int, int>>>, 
					greater<pair<int, pair<int, int>>>> pq;
	pq.push({ arr[x][y], {x, y} });
	dp[x][y] = arr[x][y];

	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };

	while (!pq.empty()) {
		int curX = pq.top().second.first;
		int curY = pq.top().second.second;
		int curM = pq.top().first;
		// pop from the queue
		pq.pop();

		if (curM > dp[curX][curY])
			continue;

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (!inRange(nextX, nextY))
				continue;

			int nextM = curM + arr[nextX][nextY];

			if (dp[nextX][nextY] > nextM) {
				dp[nextX][nextY] = nextM;
				pq.push({ nextM, {nextX, nextY} });
			}
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int problemCnt = 1;

	while (1) {
		cin >> n;

		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = INF;
			}
		}

		dijkstra(0, 0);

		cout << "Problem " << problemCnt++ << ": " << dp[n - 1][n - 1] << "\n";
	}


	return 0;
}