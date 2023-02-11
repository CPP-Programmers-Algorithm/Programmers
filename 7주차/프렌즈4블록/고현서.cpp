#include<cstring>
#include<string>
#include<vector>
using namespace std;

int boardHash[31][31];
void CalcHash(vector<string> board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size() - 1; j++) {
			if (board[i][j + 1] != '0' && board[i][j] != '0') {
				boardHash[i][j] =
					((int)board[i][j]) * 2 +
					((int)board[i][j + 1]);
			}
		}
	}
}
int blockCount[31][31];
vector<string> boardFrame;
vector<string> boardNext;
//ÆÎ ÅÍÁø block °¹¼ö »õ±â
int Pang(int y, int x) {
	int ans = 0;
	for (int i = y; i < y + 2; i++) {
		for (int j = x; j < x + 2; j++) {
			if (blockCount[i][j] == 0) {
				blockCount[i][j] = 1;
				boardNext[i][j] = '0';
				ans++;
			}
		}
	}
	return ans;
}
//ºí·Ï ¹ØÀ¸·Î ³»¸®±â
void MoveDown() {
	for (int i = 0; i < boardFrame[0].size(); i++) {
		bool isChange = false;
		int lastPosY = 0;
		for (int j = boardFrame.size() - 1; j >= 0; j--) {
			if (blockCount[j][i] == 0 && isChange) {
				int temp = boardNext[j][i];
				boardNext[j][i] = boardNext[lastPosY][i];
				boardNext[lastPosY][i] = temp;
				lastPosY--;
			}
			else if (blockCount[j][i] == 1 && !isChange) {
				isChange = true;
				lastPosY = j;
			}
		}
	}
}
bool isCheck(int y, int x) {
	char pangBlock = boardFrame[y][x];
	for (int i = y; i < y + 2; i++) {
		for (int j = x; j < x + 2; j++) {
			if (pangBlock != boardFrame[i][j])
				return false;
		}
	}
	return true;
}
int solution(int m, int n, vector<string> board) {
	int answer = 0;
	boardFrame = board;
	boardNext = board;
	while (true) {
		memset(blockCount, 0, sizeof(blockCount));
		memset(boardHash, 0, sizeof(boardHash));
		CalcHash(boardFrame);
		bool isCorrect = false;
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (boardHash[i][j] != 0 &&
					boardHash[i][j] == boardHash[i + 1][j]) {
					if (isCheck(i, j)) {
						isCorrect = true;
						answer += Pang(i, j);
					}
				}
			}
		}
		if (!isCorrect)
			break;
		MoveDown();
		boardFrame = boardNext;
	}
	return answer;
}