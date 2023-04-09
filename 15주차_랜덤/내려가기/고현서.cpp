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
	std::cout.tie(NULL);
}
enum State {
	Left,
	Middle,
	Right
};
int board[100001][3];

//0번째 행이 min
//1번째 행이 max
int preDP[2][3];
int curDP[2][3];
int main(void) {
	init();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> board[i][j];
		}
	}

	//초기값
	for (int i = 0; i < 3; i++) {
		curDP[0][i] = board[0][i];
		curDP[1][i] = board[0][i];
	}

	//n줄 중
	for (int i = 1; i < n; i++) {
		//현재값을 이전값으로 복사 후 현재값을 초기화
		for (int l = 0; l < 3; l++) {
			preDP[0][l] = curDP[0][l];
			preDP[1][l] = curDP[1][l];

			curDP[0][l] = 1000001;
			curDP[1][l] = 0;
		}
		//j의 열에서
		for (int j = 0; j < 3; j++) {
			//이전 줄의 k열 중에 작은 수 or 큰 수를 자신에게 더한 값으로 업데이트
			for (int k = 0; k < 3; k++) {
				switch (j) {
				case Left:
					if (k == Right) continue;
					break;
				case Right:
					if (k == Left) continue;
					break;
				case Middle:
					break;
				default:
					break;
				}
				curDP[0][j] = min(curDP[0][j], preDP[0][k] + board[i][j]);
				curDP[1][j] = max(curDP[1][j], preDP[1][k] + board[i][j]);
			}
		}
	}
	int minAns = 1000001;
	int maxAns = 0;
	for (int i = 0; i < 3; i++) {
		minAns = min(minAns, curDP[0][i]);
		maxAns = max(maxAns, curDP[1][i]);
	}
	std::cout << maxAns << " " << minAns;
	return 0;
}
