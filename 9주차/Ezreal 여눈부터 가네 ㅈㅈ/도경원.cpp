#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int n, mod = 1'000'000'007;
	cin >> n;

	int dist[3][1516];						// dist[i][j]�� j�ڸ��鼭 3���� ���� �������� i�� ����� ��
	
	dist[0][1] = 0;							// 1�ڸ����� ����� �� ����
	
	dist[0][2] = 1;							// 2�ڸ����� �ʱ�� ��´�
	dist[1][2] = 1; 
	dist[2][2] = 0; 

	for (int i = 3; i < n + 1; i++) {		//���� �ڸ������� ���� ������
		dist[0][i] = (dist[2][i - 1] + dist[1][i - 1]) % mod; 
		dist[1][i] = (dist[0][i - 1] + dist[2][i - 1]) % mod;
		dist[2][i] = (dist[1][i - 1] + dist[0][i - 1]) % mod;
	}

	cout << dist[0][n];
	return 0;
}


// ��ȭ��
// dp[(i + 1) % 3][j] += dp[i][j - 1]
// dp[(i + 5) % 3][j] += dp[i][j - 1]
// 
//https://kangwlgns.tistory.com/17