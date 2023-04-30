#include <iostream>
#include <vector>

using namespace std;

int M, N, Size, Point;
vector<vector<int>> MAP;

void MakeMap(vector<vector<int>> lock) { // ����� �ڹ����� ũ�⿡ ���� ��ũ�� Ȯ��
	int lock_x = 0;
	int lock_y = 0;
	for (int i = M - 1; i < Size - (M - 1); i++, lock_x++){
		for (int j = M - 1; j < Size - (M - 1); j++, lock_y++){
			MAP[i][j] = lock[lock_x][lock_y];
			if (MAP[i][j] == 0) Point++;
		}
		lock_y = 0;
	}
}

int SumKeyLock(int sx, int sy, vector<vector<int>> key) {
	int x_idx = 0;
	int y_idx = 0;
	int check = 0;
	for (int x = sx; x < sx + M; x++, x_idx++) { // ����ü�� Ž���ϸ� ���������� �˻�
		for (int y = sy; y < sy + M; y++, y_idx++)
		{
			if (MAP[x][y] == 1 && key[x_idx][y_idx] == 1) return -1;
			if (MAP[x][y] == 0 && key[x_idx][y_idx] == 0) return -1;
			if (MAP[x][y] == 0 && key[x_idx][y_idx] == 1) check++;
		}
		y_idx = 0;
	}
	return check;
}

void RotateKey(vector<vector<int>>& key) {
	vector<vector<int>> tmp = key;
	for (int i = 0; i < M; i++){
		for (int j = 0; j < M; j++){
			tmp[i][j] = key[M - 1 - j][i];
		}
	}
	key = tmp;
}

bool MoveMap(vector<vector<int>> key) {
	for (int r = 0; r < 4; r++){
		for (int i = 0; i < M+N-1; i++){
			for (int j = 0; j < M+N-1; j++){
				int Result = SumKeyLock(i, j, key); //Ž�� �������� �Ű������� �����Ѵ�
				if (Result == Point) return true; // ó�� �����ߴ� Ű�� Ȩ�� �Ȱ��� ��� ��������
			}
		}
		RotateKey(key);
	}
	return false;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	M = key.size();
	N = lock.size();
	Size = N + 2 * (M - 1);

	MAP.resize(Size, vector<int>(Size, 2));
	MakeMap(lock);
	bool answer = MoveMap(key);
	return answer;
}