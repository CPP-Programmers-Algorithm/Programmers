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
#define INF 0x3f3f3f3f/3
#define endl "\n"
using namespace std;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
enum DirState {
	Right,
	Down,
	RightAndDown
};

int pipeDirX[3] = { 1, 0 ,1 };
int pipeDirY[3] = { 0, 1 ,1 };

int prePipe[3][3] = { {1, 0, 1},{0, 1, 1}, { 1,1,1 } };

int house[16][16];
int n;
int dp[16][16][3];
int main(void) {
	init();
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> house[i][j];
		}
	}

	//(x=1,y=0)에 도착했을 때 파이프 방향이 가로일 경우
	dp[0][1][0] = 1;

	//끝 꼬다리 기준
	for (int i = 0; i < n; i++) {
		for (int j = 2; j < n; j++) {
			if (house[i][j] == 1)
				continue;
			//(x=j,y=i)에 도착했을 때 파이프 방향이 k일 경우
			//그곳에 도착하기에까지 그 전 경로의 경우의 수를 가져와 더한다.
			for (int k = 0; k < 3; k++) {
				for (int d = 0; d < 3; d++) {
					//k방향으로 도착하는데 d방향으로 부터 도착할 수 있는지 확인
					if (!prePipe[k][d]) continue;

					int preX = j - pipeDirX[k];
					int preY = i - pipeDirY[k];

					if (preX < 0 || preY < 0) continue;
					//시작 또다리가 막혔는지 확인
					if (house[preY][preX] == 1) continue;

					if (k == RightAndDown) {
						if (i - 1 < 0 ||
							j - 1 < 0 ||
							house[i - 1][j] == 1 ||
							house[i][j - 1] == 1)
							continue;
					}

					dp[i][j][k] += dp[preY][preX][d];
				}
			}
		}
	}
	//각 방향으로 끝 꼬다리가 도착할 경우의 수의 합
	cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
	return 0;
}
