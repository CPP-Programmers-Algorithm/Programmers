#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int map[26][26];
int maptemp[26][26][4];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n;

typedef struct {
	int x;
	int y;
	int money;
	int px;
}node;

int bfs(int start) {
	queue<node> q;
	q.push({ start, start, 0, -1 });			        	// 시작점 노드 넣기
	vector<int> result;							        	// 결과들 저장할 vector
	
	fill(&maptemp[0][0][0], &maptemp[n - 1][n][4], 0);		// 0으로 초기화

	while (!q.empty()) {
		int qx = q.front().x;			    	// x 좌표
		int qy = q.front().y;			    	// y 좌표
		int qm = q.front().money;		    	// 현재 지용
		int qpx = q.front().px;			    	// 이전방향
		q.pop();

		if (qx == n - 1 && qy == n - 1) {		// 목적지에 도착하면 비용을 저장
			result.push_back(qm);
			continue;
		}

		for (int i = 0; i < 4; i++)								// 방향탐색
		{
			int mx = qx + dx[i];
			int my = qy + dy[i];
			int temp = qm;
															    // 아무것도 하지 않는 경우
			if (mx<0 || mx>n - 1 || my<0 || my>n - 1)continue;  // 1. map을 벗어난 경우
			if (map[mx][my] == 1)continue;					    // 2. 벽인 경우
																// 방향검사
			if (qpx == -1 || qpx == i)							// 1. -1 이거나 pqx가 현재방향과 동일하면
				temp += 100;
			else if (qpx != i || qpx != -1)						// 2. 그 외의 경우
				temp += 600;

			if (maptemp[mx][my][i] >= temp || maptemp[mx][my][i] == 0) { // 현재 비용값이 maptemp에 저장된 비용보다 작거나 같으면
				maptemp[mx][my][i] = temp;								 // 작으면 더 효율적인 방법
				q.push({ mx, my, temp, i });							 // q와 map 모두에 넣는다
			}
		}
	}
	sort(result.begin(), result.end());			// 오름차순 정렬
	return result[0];							// 가장 작은 값 반환
}

int solution(vector<vector<int>>board) {
	int answer = 0;

	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[i].size(); j++)
			map[i][j] = board[i][j];

	n = board.size();

	int temp = bfs(0);
	answer = temp;

	return answer;
}





//https://fishersheep.tistory.com/242