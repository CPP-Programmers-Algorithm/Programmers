// BOJ2252 �ټ����

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> adj[32001];
int deg[32001];
int n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b); // a�� ����� ���������� ����
		deg[b]++; //indegree�� ���� �����ش�->�θ��Ǽ�
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {	//�ʱ���¼���
		if (deg[i] == 0) q.push(i); //indegree�� ���� ������ q�� �ִ´�
	}								//�Ʒ��� �� ������ �ݺ��ȴ� -> do while�ε� �ذᰡ��
	while (!q.empty()) {
		int cur = q.front(); q.pop(); // indegree�� 0�� ������ �����´�
		cout << cur << ' ';
		for (int nxt : adj[cur]) { //�ش������� ����� ���������� �������
			deg[nxt]--; //����� ������ indegree�� �ϳ� ���̰�
			if (deg[nxt] == 0) q.push(nxt); //�׷��� �� �θ��尡 �ϳ��� �������� q�� �ִ´�
		}
	}
}