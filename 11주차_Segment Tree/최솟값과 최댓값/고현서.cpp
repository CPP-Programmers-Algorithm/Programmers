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
int treeMax[100001 << 2];
int treeMin[100001 << 2];
int nodes[100001];

int init_Min(int node, int start, int end) {
	if (start == end) return treeMin[node] = nodes[start];
	int mid = (start + end) / 2;
	return treeMin[node] = min(
		init_Min(node * 2, start, mid),
		init_Min(node * 2 + 1, mid + 1, end));
}
int init_Max(int node, int start, int end) {
	if (start == end) return  treeMax[node] = nodes[start];
	int mid = (start + end) / 2;
	return treeMax[node] = max(
		init_Max(node * 2, start, mid),
		init_Max(node * 2 + 1, mid + 1, end));
}
int query_Min(int node, int start, int end, int left, int right) {
	if (end < left || start > right) return INF;
	if (left <= start && end <= right) return treeMin[node];
	int mid = (start + end) / 2;
	return min(
		query_Min(node * 2, start, mid, left, right),
		query_Min(node * 2 + 1, mid + 1, end, left, right));
}

int query_Max(int node, int start, int end, int left, int right) {
	if (end < left || start > right) return 0;
	if (left <= start && end <= right) return treeMax[node];
	int mid = (start + end) / 2;
	return max(
		query_Max(node * 2, start, mid, left, right),
		query_Max(node * 2 + 1, mid + 1, end, left, right));
}
int main(void) {
	init();
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> nodes[i];
	}
	init_Max(1, 0, N - 1);
	init_Min(1, 0, N - 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << query_Min(1, 0, N - 1, a - 1, b - 1) << " " << query_Max(1, 0, N - 1, a - 1, b - 1) << endl;
	}
}