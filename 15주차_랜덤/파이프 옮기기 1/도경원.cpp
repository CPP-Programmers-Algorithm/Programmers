#include<iostream>
using namespace std;

int arr[20][20];
int n;

void dfs(int x, int y, int dir) {
	arr[x][y]++;

	//가로세로일때는 아래 2가지 경우로 dfs
	if (dir == 0 || dir == 2) {
		if (y < n && arr[x][y + 1] != -1) // 영역안에 있고 다음 탐색이 벽이 아니라면
			dfs(x, y + 1, 0);
	}
	if (dir == 1 || dir == 2) {
		if (x < n && arr[x + 1][y] != -1) // 영역안에 있고 다음 탐색이 벽이 아니라면
			dfs(x + 1, y, 1);
	}
	//가로세로대각선일 경우 모두 대각선방향으로 이동가능
	if (x < n && y < n) {
		if (arr[x][y + 1] != -1 && arr[x + 1][y] != -1 && arr[x + 1][y + 1] != -1) {
			dfs(x + 1, y + 1, 2);
		}
	}
		

	return;
}

int main() {
	cin >> n;

	for (int i = 1;i <= n;i++) {
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1) arr[i][j] = -1;
		}
	}

	//파이프의 오른좌표 x,y 방향정보
	//0 가로, 1 세로, 2 대각선
	//파이프의 끝점에 집중한 문제풀이
	dfs(1, 2, 0);

	if (arr[n][n] == -1)arr[n][n] = 0;
	cout << arr[n][n];

	return 0;
}












//https://rujang.tistory.com/entry/%EB%B0%B1%EC%A4%80-17070%EB%B2%88-%ED%8C%8C%EC%9D%B4%ED%94%84-%EC%98%AE%EA%B8%B0%EA%B8%B0-1-CC