// BOJ1238 파티

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


// 문제조건 : 단방향도로, 파티에 갔다가 돌아와야 함
// 출력     : 가장오래걸리는 학생을 구하라 

// (i -> x) + (x -> i) 가장 큰 것 구하라

//하나의 정점에서 다른 모든 정점으로의 최단거리
void dijkstra(int start) {
	priority_queue<pii, vector<pii>, greater<pii>> pq; //거리, 노드
	pq.push(make_pair(0, start)); //거리, 노드
	dst[start] = 0;
	
	while (!pq.empty()) {
		int cost = pq.top().first; //거리가 큰 순으로 뽑는다
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[now].size(); i++){
			int nxt = graph[now][i].first;
			int nCost = graph[now][i].second;

			if (cost + nCost < dst[nxt]) { //새로운 거리를 더한 것이 저장된 거리보다 작을 때
				dst[nxt] = cost + nCost;   //거리를 갱신해준다
				pq.push(make_pair(cost + nCost, nxt)); //새로운 거리와 다음 노드를 갱신
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> x;

	// 노드별 도착점과 비용을 넣어준다
	for (int i = 0; i < m; i++){
		cin >> s >> e >> t; 
		graph[s].push_back(make_pair(e, t));
	}

	//i to x
	for (int i = 1; i <= n ; i++){
		// 최단거리를 비교해야 하니 초기를 무한으로 설정
		// 학생마다 최단거리를 구해야 하므로 dst를 할 때마다 초기화
		for (int j = 1; j <= n; j++){
			dst[j] = INF;
		}
		dijkstra(i); // 학생별로 거리를 구함, 출발점을 매개변수로 전달
		ans[i] = dst[x]; // 목적지까기 가는 거리를 학생마다 저장
	}

	// x to i
	for (int i = 1; i <= n; i++) dst[i] = INF;//다시 dst초기화
	dijkstra(x); //출발점을 x로 하고 모든 마을까지 최단거리 구함

	// (i to x) + (x to i)
	for (int i = 1; i <= n; i++){
		ans[i] += dst[i]; // ans는 i to x 값 저장 중, 여기에 새로 갱신된 최단거리들 합해주기
	}

	cout << *max_element(ans + 1, ans + n + 1); // 1번요소 ~ n 번요소중 가장 큰 것 출력

	return 0;
}





//https://9x211x2.tistory.com/46