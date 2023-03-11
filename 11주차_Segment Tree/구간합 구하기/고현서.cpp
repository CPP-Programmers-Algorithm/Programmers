#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<deque>
#include<map>
#include<vector>
#include<cmath>
#include<climits>
#include<set>
#include<queue>
#include<list>
#include<stack>
#include<math.h>
#include<memory>
#include<sstream>
#include<unordered_map>
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

long long tree[1000001 << 2];
long long nodes[1000001];
long long init(int node, int start, int end) {
	if (start == end) return tree[node] = nodes[start];
	int mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) +
		init(node * 2 + 1, mid + 1, end);
}

long long query(int node, int start, int end, int left, int right) {
	if (right < start || left > end) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) +
		query(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, long long diff) {
	if (idx < start || idx > end) return;
	tree[node] += diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, diff);
	update(node * 2 + 1, mid + 1, end, idx, diff);
}
int main(void) {
	init();
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> nodes[i];
	}
	init(1, 0, N - 1);
	for (int i = 0; i < M + K; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		switch (a)
		{
		case 1:
			update(1, 0, N - 1, b - 1, c - nodes[b - 1]);
			nodes[b - 1] = c;
			break;
		case 2:
			cout << query(1, 0, N - 1, b - 1, c - 1) << endl;
			break;
		default:
			break;
		}
	}
}