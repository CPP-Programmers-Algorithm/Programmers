#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<bool>> visited;
vector<vector<int>>  room;
int d, w;
int sum = 0;

void CheckTile(int curTile, int nd, int nw) {                       // nowDepth, nowWidth

	if (nd >= d || nw >= w) { sum++; return; }						// ���� �Ѿ�� ���� ���̴� 1 ���
	if (curTile != room[nd][nw]) { sum++; return; }					// ���� �Ͱ� ���� ������ ������ ���̴� 1 ���
	// �� �������� �Ѿ�� ������ visited �ƴ�
	if (curTile == 0) { CheckTile(room[nd][nw], nd, nw + 1); }
	if (curTile == 1) { CheckTile(room[nd][nw], nd + 1, nw); }
	visited[nd][nw] = true;
}

void solution(int d, int w, vector<vector<int>> room) {
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (visited[i][j] == true) continue;  // �湮�ߴٸ� ��������
			CheckTile(room[i][j], i, j);		  // ó���� ���� �� �־��ش�
		}
	}
}

int main() {
	cin >> d >> w;							// room���� �����Է�
	room.resize(d); visited.resize(d);      // room�� visited ��������

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < w; j++) {
			char temp; cin >> temp;
			if (temp == '-') room[i].push_back(0);  // ���ζ�� 0�� �־���
			else room[i].push_back(1);				// ���ζ�� 1�� �־���

			visited[i].push_back(false);            // visited �ʱ�ȭ
		}
	}
	solution(d, w, room);							// solution ����
	cout << sum;
	return 0;
}