#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int moveX[3] = {1, 0, 1};		// 오른쪽, 아래, 대각선 오른쪽 아래
int moveY[3] = {0, 1, 1};

int solution(int m, int n, vector<string> board)
{
	int answer = 0;
	vector<vector<char>> boardArr(m);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			boardArr[i].push_back(board[i][j]);
	}

	while (true)
	{
		// 매 회차마다 보드 모양 출력 (디버깅용 코드)
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << boardArr[i][j];
			cout << endl;
		}

		// 보드에 있는 모든 블록 확인하면서 제거되는 블록 좌표 저장 
		vector<pii> removeBlocks;
		for (int i = 0; i < m - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				// 현재 좌표의 오른쪽, 아래, 대각선 오른쪽 아래가 현재 좌표와 같은 글자면 현재 좌표 저장
				char curChar = boardArr[i][j];
				for (int k = 0; k < 3; k++)
				{
					if (boardArr[i + moveY[k]][j + moveX[k]] != curChar || curChar == '.')
						break;
					if (k == 2)
						removeBlocks.push_back(pii(i, j));
				}
			}
		}

		// 삭제되는 블록 없으면 루프 종료
		if (removeBlocks.size() == 0)
			break;

		// removeBlocks에 저장된 좌표들의 y, x에 대해 checkRemove[y][x]에 true로 체크
		vector<bool> set_bool(n);
		vector<vector<bool>> checkRemove(n, set_bool);

		for (int i = 0; i < removeBlocks.size(); i++)
		{
			int y = removeBlocks[i].first;
			int x = removeBlocks[i].second;
			checkRemove[y][x] = true;
			for (int j = 0; j < 3; j++)
				checkRemove[y + moveY[j]][x + moveX[j]] = true;
		}

		// checkRemove에 true로 체크된 블록들 제거하고 위 칸들 아래로 당기기
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (checkRemove[i][j])
				{
					for (int k = i; k >= 0; k--)
					{
						if (k == 0)
							boardArr[k][j] = '.';
						else
							boardArr[k][j] = boardArr[k - 1][j];
					}
					answer++;
				}
			}
		}
		cout << endl;
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int m = 6, n = 6;
	vector<string> str = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
	solution(m, n, str);
}