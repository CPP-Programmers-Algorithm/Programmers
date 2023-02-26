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
using namespace std;


void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
}
//3 * n
// 7*13
//---0-0-0-0---
//--0-0-0-0-0--
//-0-0-0-0-0-0-
//0-0-0-0-0-0-0
//-0-0-0-0-0-0-
//--0-0-0-0-0--
//---0-0-0-0---

//--0-0-0--
//-0-0-0-0-
//0-0-0-0-0
//-0-0-0-0-
//--0-0-0--

//-0-0-
//0-0-0
//-0-0-

#define MAX 14
//미로 틀
char miro[MAX + 1][29];
//int dp[7 * 2 + 1][(7 * 2)+8+7];
//1~14번만에 특정 위치에 도달할 경우의 수
int dp[MAX + 1][MAX + 1][29];
//방향
int xSign[6] = { -1, -1, 1, 1, 2, -2 };
int ySign[6] = { 1, -1, 1, -1, 0, 0 };
//방문처리
bool isVisited[MAX + 1][MAX + 1][29];
void DPSetting(int startY, int startX) {
	queue<pair<pair<int, int>, int>> searchQue;
	searchQue.push({ { startY,startX }, 0 });
	dp[0][startY][startX] = 1;
	while (!searchQue.empty()) {
		int y = searchQue.front().first.first;
		int x = searchQue.front().first.second;
		int curDepth = searchQue.front().second;
		searchQue.pop();
		if (curDepth + 1 > MAX)
			continue;
		//6방향으로 뻗어나가며 자신의 depth + 1을 더해준다.
		for (int i = 0; i < 6; i++) {
			int nextY = y + ySign[i];
			int nextX = x + xSign[i];
			if (nextY < 0 || nextY > MAX || nextX < 0 || nextX > 28)
				continue;
			if (miro[nextY][nextX] == '-')
				continue;
			dp[curDepth + 1][nextY][nextX] += dp[curDepth][y][x];
			if (!isVisited[curDepth + 1][nextY][nextX]) {
				searchQue.push({ {nextY, nextX},curDepth + 1 });
				isVisited[curDepth + 1][nextY][nextX] = true;
			}
		}
	}
}
int main() {
	init();
	int centerY = 7;
	int centerX = 14;
	int tc;
	cin >> tc;
	//미로 그리기
	for (int i = 0; i < centerY; i++) {
		for (int j = 0; j < 29; j++) {
			if (j < MAX / 2 - i || j > 29 - (MAX / 2 - i)
				|| ((i + 1) % 2 == 1 && (j + 1) % 2 == 1)
				|| ((i + 1) % 2 == 0 && (j + 1) % 2 == 0))
				miro[i][j] = '-';
			else
				miro[i][j] = '0';
		}
	}
	for (int i = centerY; i <= MAX; i++) {
		for (int j = 0; j < 29; j++) {
			if (j < (MAX / 2 - (MAX / 2 - (i - centerY))) || j > 29 - (MAX / 2 - (MAX / 2 - (i - centerY)))
				|| ((i + 1) % 2 == 1 && (j + 1) % 2 == 1)
				|| ((i + 1) % 2 == 0 && (j + 1) % 2 == 0))
				miro[i][j] = '-';
			else
				miro[i][j] = '0';
		}
	}
	//경로 탐색
	DPSetting(centerY, centerX);

	for (int t = 0; t < tc; t++) {
		int maxCnt;
		cin >> maxCnt;
		cout << dp[maxCnt][centerY][centerX] << "\n";
	}
}