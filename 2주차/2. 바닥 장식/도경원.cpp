#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<bool>> visited;
vector<vector<int>>  room;
int d, w;
int sum = 0;

void CheckTile(int curTile, int nd, int nw) {                       // nowDepth, nowWidth

	if (nd >= d || nw >= w) { sum++; return; }						// 맵을 넘어가면 끝난 것이니 1 상승
	if (curTile != room[nd][nw]) { sum++; return; }					// 다음 것과 같지 않으면 끊어진 것이니 1 상승
	// 이 다음으로 넘어가기 전에는 visited 아님
	if (curTile == 0) { CheckTile(room[nd][nw], nd, nw + 1); }
	if (curTile == 1) { CheckTile(room[nd][nw], nd + 1, nw); }
	visited[nd][nw] = true;
}

void solution(int d, int w, vector<vector<int>> room) {
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (visited[i][j] == true) continue;  // 방문했다면 지나간다
			CheckTile(room[i][j], i, j);		  // 처음엔 같은 걸 넣어준다
		}
	}
}

int main() {
	cin >> d >> w;							// room가로 세로입력
	room.resize(d); visited.resize(d);      // room과 visited 리사이즈

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < w; j++) {
			char temp; cin >> temp;
			if (temp == '-') room[i].push_back(0);  // 가로라면 0을 넣어줌
			else room[i].push_back(1);				// 세로라면 1을 넣어줌

			visited[i].push_back(false);            // visited 초기화
		}
	}
	solution(d, w, room);							// solution 시작
	cout << sum;
	return 0;
}