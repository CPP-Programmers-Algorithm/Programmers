// BOJ1238 ��Ƽ

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001
#define INF 1e9
#define pii pair<int,int>
using namespace std;

vector<pii> graph[MAX];
int dst[MAX], ans[MAX];
int n, m, x, s, e, t;


// �������� : �ܹ��⵵��, ��Ƽ�� ���ٰ� ���ƿ;� ��
// ���     : ��������ɸ��� �л��� ���϶� 

// (i -> x) + (x -> i) ���� ū �� ���϶�

//�ϳ��� �������� �ٸ� ��� ���������� �ִܰŸ�
void dijkstra(int start) {
	priority_queue<pii, vector<pii>, greater<pii>> pq; //�Ÿ�, ���
	pq.push(make_pair(0, start)); //�Ÿ�, ���
	dst[start] = 0;
	
	while (!pq.empty()) {
		int cost = pq.top().first; //�Ÿ��� ū ������ �̴´�
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[now].size(); i++){
			int nxt = graph[now][i].first;
			int nCost = graph[now][i].second;

			if (cost + nCost < dst[nxt]) { //���ο� �Ÿ��� ���� ���� ����� �Ÿ����� ���� ��
				dst[nxt] = cost + nCost;   //�Ÿ��� �������ش�
				pq.push(make_pair(cost + nCost, nxt)); //���ο� �Ÿ��� ���� ��带 ����
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> x;

	// ��庰 �������� ����� �־��ش�
	for (int i = 0; i < m; i++){
		cin >> s >> e >> t; 
		graph[s].push_back(make_pair(e, t));
	}

	//i to x
	for (int i = 1; i <= n ; i++){
		// �ִܰŸ��� ���ؾ� �ϴ� �ʱ⸦ �������� ����
		// �л����� �ִܰŸ��� ���ؾ� �ϹǷ� dst�� �� ������ �ʱ�ȭ
		for (int j = 1; j <= n; j++){
			dst[j] = INF;
		}
		dijkstra(i); // �л����� �Ÿ��� ����, ������� �Ű������� ����
		ans[i] = dst[x]; // ��������� ���� �Ÿ��� �л����� ����
	}

	// x to i
	for (int i = 1; i <= n; i++) dst[i] = INF;//�ٽ� dst�ʱ�ȭ
	dijkstra(x); //������� x�� �ϰ� ��� �������� �ִܰŸ� ����

	// (i to x) + (x to i)
	for (int i = 1; i <= n; i++){
		ans[i] += dst[i]; // ans�� i to x �� ���� ��, ���⿡ ���� ���ŵ� �ִܰŸ��� �����ֱ�
	}

	cout << *max_element(ans + 1, ans + n + 1); // 1����� ~ n ������� ���� ū �� ���

	return 0;
}





//https://9x211x2.tistory.com/46