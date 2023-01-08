#include <bits/stdc++.h>

using namespace std;
typedef tuple<int, int, int> tiii;

bool isMoreThan2 = false;
vector<bool> set_bool(5, false);
vector<vector<bool>> visited(5, set_bool);

void DFS(int y, int x, vector<tiii> arr, int depth, int count)
{
	// 방문 처리
	visited[y][x] = true;

	int currentDepth = depth;
	int currentCount = count;
	
	if (depth <= 3 && count >= 2)
	{
		isMoreThan2 = true;
		return;
	}

	if (depth >= 3 && count < 2)
		return;

	// 위로 이동
	if (y > 0 && !visited[y - 1][x] && get<2>(arr[(y - 1) * 5 + x]) != -1)
	{
		if (get<2>(arr[(y - 1) * 5 + x]) == 1)
			DFS(y - 1, x, arr, currentDepth + 1, currentCount + 1);
		else
			DFS(y - 1, x, arr, currentDepth + 1, currentCount);	
	}

	// 아래로 이동
	if (y < 4 && !visited[y + 1][x] && get<2>(arr[(y + 1) * 5 + x]) != -1)
	{
		if (get<2>(arr[(y + 1) * 5 + x]) == 1)
			DFS(y + 1, x, arr, currentDepth + 1, currentCount + 1);
		else
			DFS(y + 1, x, arr, currentDepth + 1, currentCount);
	}

	// 왼쪽으로 이동
	if (x > 0 && !visited[y][x - 1] && get<2>(arr[y * 5 + x - 1]) != -1)
	{
		if (get<2>(arr[y * 5 + x - 1]) == 1)
			DFS(y, x - 1, arr, currentDepth + 1, currentCount + 1);
		else
			DFS(y, x - 1, arr, currentDepth + 1, currentCount);
	}

	// 오른쪽으로 이동
	if (x < 4 && !visited[y][x + 1] && get<2>(arr[y * 5 + x + 1]) != -1)
	{
		if (get<2>(arr[y * 5 + x + 1]) == 1)
			DFS(y, x + 1, arr, currentDepth + 1, currentCount + 1);
		else
			DFS(y, x + 1, arr, currentDepth + 1, currentCount);
	}

	if (currentDepth == 0)
	{
		if (isMoreThan2)
			cout << 1;
		else
			cout << 0;
	}
}

int main()
{	
	vector<tuple<int, int, int>> arr(25);	// 각 칸에 대해 (y좌표, x좌표, 칸 종류) 저장

	// 맵 입력하기
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int n;
			cin >> n;	// cin은 입력 버퍼에서 공백 이전까지만 값을 가져옴. 이후 cin을 호출하면 입력하지 않아도 자동으로 입력 버퍼에서 남아있는 값을 가져옴.
						// 따라서 0 0 1 0 0 을 한 번 입력 시, 5번의 반복문 동안 n에 0 0 1 0 0 이 차례대로 할당됨.
			arr[i * 5 + j] = tiii(i, j, n);
		}
	}

	// 현재 위치 입력하기
	int y, x;
	cin >> y;
	cin >> x;
	cin.ignore();

	DFS(y, x, arr, 0, 0);
}
