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
	q.push({ start, start, 0, -1 });			        	// ������ ��� �ֱ�
	vector<int> result;							        	// ����� ������ vector
	
	fill(&maptemp[0][0][0], &maptemp[n - 1][n][4], 0);		// 0���� �ʱ�ȭ

	while (!q.empty()) {
		int qx = q.front().x;			    	// x ��ǥ
		int qy = q.front().y;			    	// y ��ǥ
		int qm = q.front().money;		    	// ���� ����
		int qpx = q.front().px;			    	// ��������
		q.pop();

		if (qx == n - 1 && qy == n - 1) {		// �������� �����ϸ� ����� ����
			result.push_back(qm);
			continue;
		}

		for (int i = 0; i < 4; i++)								// ����Ž��
		{
			int mx = qx + dx[i];
			int my = qy + dy[i];
			int temp = qm;
															    // �ƹ��͵� ���� �ʴ� ���
			if (mx<0 || mx>n - 1 || my<0 || my>n - 1)continue;  // 1. map�� ��� ���
			if (map[mx][my] == 1)continue;					    // 2. ���� ���
																// ����˻�
			if (qpx == -1 || qpx == i)							// 1. -1 �̰ų� pqx�� �������� �����ϸ�
				temp += 100;
			else if (qpx != i || qpx != -1)						// 2. �� ���� ���
				temp += 600;

			if (maptemp[mx][my][i] >= temp || maptemp[mx][my][i] == 0) { // ���� ��밪�� maptemp�� ����� ��뺸�� �۰ų� ������
				maptemp[mx][my][i] = temp;								 // ������ �� ȿ������ ���
				q.push({ mx, my, temp, i });							 // q�� map ��ο� �ִ´�
			}
		}
	}
	sort(result.begin(), result.end());			// �������� ����
	return result[0];							// ���� ���� �� ��ȯ
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