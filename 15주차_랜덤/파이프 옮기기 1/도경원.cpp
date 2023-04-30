#include<iostream>
using namespace std;

int arr[20][20];
int n;

void dfs(int x, int y, int dir) {
	arr[x][y]++;

	//���μ����϶��� �Ʒ� 2���� ���� dfs
	if (dir == 0 || dir == 2) {
		if (y < n && arr[x][y + 1] != -1) // �����ȿ� �ְ� ���� Ž���� ���� �ƴ϶��
			dfs(x, y + 1, 0);
	}
	if (dir == 1 || dir == 2) {
		if (x < n && arr[x + 1][y] != -1) // �����ȿ� �ְ� ���� Ž���� ���� �ƴ϶��
			dfs(x + 1, y, 1);
	}
	//���μ��δ밢���� ��� ��� �밢���������� �̵�����
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

	//�������� ������ǥ x,y ��������
	//0 ����, 1 ����, 2 �밢��
	//�������� ������ ������ ����Ǯ��
	dfs(1, 2, 0);

	if (arr[n][n] == -1)arr[n][n] = 0;
	cout << arr[n][n];

	return 0;
}












//https://rujang.tistory.com/entry/%EB%B0%B1%EC%A4%80-17070%EB%B2%88-%ED%8C%8C%EC%9D%B4%ED%94%84-%EC%98%AE%EA%B8%B0%EA%B8%B0-1-CC