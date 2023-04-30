#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define X first;
#define Y second;

int v, e, st, en;

// [���, ������ȣ]
vector<pair<int, int>> adj[20005];
const int INF = 1e9 + 10;
int d[20005]; //�ִܰŸ����̺�
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v >> e;	//v: �������� e: �������� st: ��������
	fill(d, d + v + 1, INF); //�ּҰ��� ���ؾ��ϱ� ������ ����ū���� �ʱⰪ����
	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v }); // �� u�� ����ϴ� ��� �������� ������ ����ġ ����
	}
	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> pq;

	cin >> st >> en;
	d[st] = 0;
	//�켱���� ť�� (0, ������) �߰�
	pq.push({ d[st],st });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue; // �̰� ���ϸ� �ð��ʰ� ��
		for (auto nxt : adj[cur.second]) {	//nxt : ���� �������� �����ϴ� ����
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue; //���� ��忡 �̹� ����� �ִܰŸ��� ���� ����� �ִܰŸ� + ���������� �Ÿ����� �۴ٸ�
			d[nxt.second] = d[cur.second] + nxt.first;		//���� �������� ������ �ִܰŸ� ����
			pq.push({ d[nxt.second],nxt.second });			//�ִܰŸ��� ���ŵǸ� ������ �˻��� ��ġ�� �ִ�
		}
	}
	
	cout << d[en];
}
