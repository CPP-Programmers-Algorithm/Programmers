#include <iostream>
#include <algorithm>
#define INF 987654321;
using namespace std;

int dis[101][101];
int cnt[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n, m; cin >> n >> m;

	int kevin, kevinNum;
	kevin = kevinNum = INF;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			dis[i][j] = INF; // �Ÿ��� �ּҰ��� ���ϱ⶧���� INF�� �ʱ�ȭ
			cnt[i][j] = 1; //��� ����� ����Ǿ� �ִ�
		}
			

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		dis[a-1][b-1] = 1; // idx�� �����ְ� ������ �ʱ�ȭ�Ѵ�
		dis[b-1][a-1] = 1;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dis[i][j] > dis[i][k] + dis[k][j]) { // ���ο� �Ÿ��� �����Ÿ����� �۴ٸ�
					dis[i][j] = dis[i][k] + dis[k][j]; // �Ÿ�����
					cnt[i][j] = cnt[i][k] + cnt[k][j]; // ���̰���
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += cnt[i][j];
		}
		if (sum < kevinNum) { kevinNum = sum; kevin = i+1;} // ���� ��츸 ���ŵǾ� ���� ���߿� �ּҰ��� ������ �ȴ�
	}
	cout << kevin;
}

